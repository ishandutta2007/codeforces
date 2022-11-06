#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d %d\n", i, j);
            printf("%d %d\n", n + 1 - i, m + 1 - j);
        }
    }

    if (n & 1) {
        int x = n / 2 + 1;
        for (int i = 0, l = 1, r = m; i < m; ++i) {
            if (i & 1) {
                printf("%d %d\n", x, r);
                --r;
            } else {
                printf("%d %d\n", x, l);
                ++l;
            }
        }
    }
    return 0;
}