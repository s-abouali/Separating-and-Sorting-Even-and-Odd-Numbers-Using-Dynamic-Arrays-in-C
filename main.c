#include <stdio.h>
#include <stdlib.h>

// 1. Function to input array elements
void inputArray(int *tab, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Enter tab[%d]: ", i);

        if (scanf("%d", tab + i) != 1) {
            printf("Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// 2. Function to separate even and odd numbers
void separateArray(int *tab, int *tabOdd, int *tabEven, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (*(tab + i) % 2 == 0) {
            *tabEven = *(tab + i);
            tabEven++;
        } else {
            *tabOdd = *(tab + i);
            tabOdd++;
        }
    }
}

// 3. Function to sort an array in ascending order
void sortArray(int *tab, int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

// 4. Function to display array elements
void displayArray(int *tab, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

// 5. Main function
int main() {
    int n, i;
    int nEven = 0, nOdd = 0;

    int *tab, *tabOdd, *tabEven;

    printf("Enter the array size: ");

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return EXIT_FAILURE;
    }

    // Dynamic memory allocation
    tab = malloc(n * sizeof(int));
    tabOdd = malloc(n * sizeof(int));
    tabEven = malloc(n * sizeof(int));

    if (tab == NULL || tabOdd == NULL || tabEven == NULL) {
        printf("Memory allocation failed.\n");

        free(tab);
        free(tabOdd);
        free(tabEven);

        return EXIT_FAILURE;
    }

    // Input array elements
    inputArray(tab, n);

    // Count even and odd numbers
    for (i = 0; i < n; i++) {
        if (tab[i] % 2 == 0) {
            nEven++;
        } else {
            nOdd++;
        }
    }

    // Separate even and odd numbers
    separateArray(tab, tabOdd, tabEven, n);

    // Sort both arrays
    sortArray(tabOdd, nOdd);
    sortArray(tabEven, nEven);

    // Display results
    printf("\nOdd numbers (ascending order): ");
    displayArray(tabOdd, nOdd);

    printf("Even numbers (ascending order): ");
    displayArray(tabEven, nEven);

    // Free allocated memory
    free(tab);
    free(tabOdd);
    free(tabEven);

    return EXIT_SUCCESS;
}