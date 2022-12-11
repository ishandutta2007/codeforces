#include <bits/stdc++.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n >> 1; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d %d\n", i, j);
            printf("%d %d\n", n + 1 - i, m + 1 - j);
        }
    }
    if (n & 1) {
        for (int i = 1; i <= m >> 1; ++i) {
            printf("%d %d\n", (n >> 1) + 1, i);
            printf("%d %d\n", (n >> 1) + 1, m + 1 - i);
        }
        if (m & 1) {
            printf("%d %d\n", (n >> 1) + 1, (m >> 1) + 1);
        }
    }
    return 0;
}