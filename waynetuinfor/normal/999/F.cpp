#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxk = 5000 + 5;
int c[maxn], h[maxn], f[maxn];
long long dp[maxk][maxk];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n * k; ++i) {
        int x; scanf("%d", &x);
        ++c[x];
    }
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        ++f[x];
    }
    for (int i = 1; i <= k; ++i) scanf("%d", &h[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n * k; ++j) {
            for (int z = 0; z <= k; ++z) if (j >= z) dp[i][j] = max(dp[i - 1][j - z] + h[z], dp[i][j]);
        }
    }
    for (int i = 0; i < maxn; ++i) {
        if (c[i] >= f[i] * k) ans += h[k] * f[i];
        else ans += dp[f[i]][c[i]];
    }
    printf("%lld\n", ans);
}