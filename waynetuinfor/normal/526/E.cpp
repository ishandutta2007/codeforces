#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int a[maxn], to[maxn];

int main() {
    int n, q; scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = n + 1; i <= n + n; ++i) a[i] = a[i - n];
    while (q--) {
        long long b; scanf("%lld", &b);
        int p = 1;
        long long s = 0;
        for (int i = 1; i <= n + n; ++i) {
            s -= a[i - 1];
            p = max(p, i);
            while (p <= n + n && s + a[p] <= b) s += a[p], ++p;
            to[i] = p;
        }
        int ans = maxn, st = -1;
        for (int i = 1; i <= n; ++i) if (st == -1 || to[i] - i < to[st] - st) st = i;
        for (int i = st, k = st; k < to[st]; i = (i + 1 > n ? 1 : i + 1), ++k) {
            int q = i;
            int z = 0, c = 0;
            for (int j = i; j <= n; j = to[j]) {
                q = max(q, j);
                while (q <= n + n && z + to[q] - q < n) z += to[q] - q, ++c, q = to[q];
                ans = min(ans, c + 1);
                --c;
                z -= to[j] - j;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}