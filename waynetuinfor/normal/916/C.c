#include <stdio.h>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    int p = n - 1;
    while (p < 2) ++p;
    for (; ; ++p) {
        int d = 0;
        for (int i = 2; i * i <= p; ++i) if (p % i == 0) d = 1;
        if (!d) break;
    }
    printf("%d %d\n", p, p);
    for (int i = 1; i < n - 1; ++i) printf("%d %d %d\n", i, i + 1, 1);
    printf("%d %d %d\n", n - 1, n, p - (n - 2));
    m -= n - 1;
    for (int i = 1; i <= n && m; ++i) {
        for (int j = i + 2; j <= n && m; ++j) printf("%d %d %d\n", i, j, 1000000000), --m;
    }
    return 0;
}