#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
int a[maxn], b[maxn], k[maxn];
long long dp[maxn][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i], &b[i], &k[i]);
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return b[i] > b[j];
    });
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[v[i]] - b[v[i]] * 1ll * k[v[i]]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[v[i]] - min(k[v[i]], j) * 1ll * b[v[i]]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, dp[n][i]);
    printf("%lld\n", ans);
    return 0;
}