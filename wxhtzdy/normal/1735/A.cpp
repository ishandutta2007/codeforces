#include <stdio.h>

int main() {
    int t, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        // 1 + 1 + x + 1 + 2 * x
        printf("%d\n", (n - 6) / 3);
    }
    return 0;
}