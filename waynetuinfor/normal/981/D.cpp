#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
long long a[maxn], s[maxn];
bool dp[maxn][maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    long long mask = 0, ans = 0;
    for (int t = 60; t >= 0; --t) {
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int p = 0; p < j; ++p) {
                    long long sp = s[j] - s[p];
                    if ((sp >> t & 1) == 0) continue;
                    if ((sp & mask) != mask) continue;
                    dp[i][j] |= dp[i - 1][p];
                }
            }
        }
        if (dp[k][n]) ans ^= (1ll << t), mask ^= (1ll << t);
    }
    printf("%lld\n", ans);
}