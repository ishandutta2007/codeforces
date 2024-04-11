#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], p[maxn];

int main() {
    int c, n; scanf("%d %d", &c, &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++a[x];
    }
    for (int i = 1; i <= c; ++i) {
        p[i] = p[i - 1];
        if (a[i]) p[i] = i;
    }
    // for (int i = 1; i <= c; ++i) printf("%d ", p[i]); puts("");
    for (int i = 1; i <= c; ++i) {
        int z = c, q = p[z];
        // printf("i = %d\n", i);
        bool f = true;
        while (z) {
            if (q > z) q = p[z];
            // printf("z = %d q = %d\n", z, q);
            if (!q) return 0 * printf("%d\n", i);
            if (i >= q && z >= i && f) {
                f = false;
                z -= i;
                continue;
            }
            int t = min(z / q, a[q]);
            z -= t * q;
            if (a[q] == t) q = p[min(z, q - 1)];
        }
    }
    puts("Greed is good");
    return 0;
}