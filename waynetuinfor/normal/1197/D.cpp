#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
long long s[maxn];
long long p[maxn][10];
int a[maxn];

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    long long ans = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) p[j][i] = s[j];
        long long d = -k;
        for (int j = i, r = 0; j <= n; ++j) {
            p[j][i] = s[j] + d;
            if (++r == m) {
                r = 0;
                d -= k;
            }
        }
        long long prv = p[0][i];
        for (int j = 1; j <= n; ++j) {
            if (j % m == i) ans = max(ans, p[j][i] - prv);
            prv = min(prv, p[j][i]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}