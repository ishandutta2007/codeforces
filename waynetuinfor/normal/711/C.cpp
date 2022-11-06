#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const long long inf = 1e15;
long long dp[maxn][maxn][maxn];
int p[maxn][maxn], c[maxn];

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", c + i);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) scanf("%d", &p[i][j]);
    }
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) for (int k = 0; k < maxn; ++k) dp[i][j][k] = inf;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (c[i] > 0) {
                dp[i][j][c[i]] = dp[i - 1][j][c[i]];
                for (int p = 0; p <= m; ++p) if (p != c[i]) dp[i][j][c[i]] = min(dp[i][j][c[i]], dp[i - 1][j - 1][p]);
            } else {
                pair<long long, int> m1 = make_pair(inf, -1), m2 = make_pair(inf, -1);
                for (int z = 1; z <= m; ++z) dp[i][j][z] = dp[i - 1][j][z] + p[i][z];
                for (int p = 0; p <= m; ++p) {
                    if (dp[i - 1][j - 1][p] < m1.first) m2 = m1, m1 = make_pair(dp[i - 1][j - 1][p], p);
                    else if (dp[i - 1][j - 1][p] < m2.first) m2 = make_pair(dp[i - 1][j - 1][p], p);
                }
                for (int z = 1; z <= m; ++z) {
                    long long t = (m1.second == z ? m2.first : m1.first);
                    dp[i][j][z] = min(dp[i][j][z], t + p[i][z]);
                }
            }
        } 
    }
    long long ans = inf;
    for (int i = 1; i <= m; ++i) ans = min(ans, dp[n][k][i]);
    if (ans == inf) puts("-1");
    else printf("%" PRId64 "\n", ans);
    return 0;
}