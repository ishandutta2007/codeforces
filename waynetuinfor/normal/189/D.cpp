#include <bits/stdc++.h>
using namespace std;

const int maxn = 60 + 5, maxm = 1000 + 10, inf = 1e9;
int w[maxn][maxn][maxn], dp[maxm][maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, r; cin >> n >> m >> r;
    for (int p = 1; p <= m; ++p) {
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> w[p][i][j];
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) w[p][i][j] = min(w[p][i][j], w[p][i][k] + w[p][k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
        dp[0][i][j] = inf;
        for (int k = 1; k <= m; ++k) dp[0][i][j] = min(dp[0][i][j], w[k][i][j]);
    }
    for (int i = 1; i < maxm; ++i) for (int j = 0; j < maxn; ++j) for (int k = 0; k < maxn; ++k) dp[i][j][k] = inf;
    for (int k = 1; k < maxm; ++k) {
        for (int p = 1; p <= n; ++p) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i][p] + dp[0][p][j]);
            }
        }
    }
    while (r--) {
        int s, t, k; cin >> s >> t >> k;
        cout << dp[k][s][t] << endl;
    }
    return 0;
}