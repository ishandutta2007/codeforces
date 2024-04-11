#include <stdio.h>

int main() {
        int n, m, i;

        scanf("%d%d", &n, &m);
        i = 1;
        while (m >= i) {
                m -= i;
                i++;
                if (i > n) i = 1;
        }
        printf("%d", m);
        return 0;
}