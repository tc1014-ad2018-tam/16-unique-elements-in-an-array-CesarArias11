/*
 * This program allows the user to enter 'n' numbers.
 * Then it will display the numbers which aren't repeated in the sequence (meaning that they are unique)
 *
 * Author: Cesar Alejandro Arias Perales
 * Date: October 15th, 2018
 * Mail: A01411995@itesm.mx
 */
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {
    // Here I declare my variables
    int x;
    int n;
    int counter;
    int reps;

    // Here I ask the user how many numbers he is entering
    printf("How many numbers are you entering?\n");
    scanf("%i", &n);

    int arr[n];

    // Loop that asks for the value and stores it in the array
    for (int i = 0; i < n; i++) {
        printf("Give me number %i:\n", i + 1);
        scanf("%i", &x);
        arr[i] = x;
    }

    // Sorts the numbers in the array from smallest to biggest.
    qsort(arr, n, sizeof(int), cmpfunc);
    printf("The unique numbers are:\n");

    // Loop that prints the unique numbers.
    for (int i = 0; i < n; i += counter+1) {
        counter = 0;
        // Loop that compares a number with the next one.
        do {
            // Compares the number in the current position with the next one or the one after, etc.
            if (arr[i] == arr[i+counter+1]) {
                counter++;
                reps = 1;
            } else {
                reps = 0;
            }
        } while (reps == 1);

        // If no duplicates were found, the number is unique and should be printed.
        if (counter == 0) {
            printf("%i\n", arr[i]);
        }
    }
    return 0;
}