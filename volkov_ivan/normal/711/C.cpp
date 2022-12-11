#include <iostream>

using namespace std;

const long long INF = 1e18;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    long long c[n + 1];
    for (int i = 1; i <= n; i++) cin >> c[i];
    long long p[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
        }
    }
    long long dp[n + 1][k + 1][m + 1];
    for (int i = 1; i <= m; i++) {
        dp[1][0][i] = INF;
        if (c[1] == 0) dp[1][1][i] = p[1][i];
        else dp[1][1][i] = INF;
        for (int j = 2; j <= k; j++) dp[1][j][i] = INF;
    }
    if (c[1] != 0) dp[1][1][c[1]] = 0;
    for (int i = 2; i <= n; i++) {
        for (int i1 = 1; i1 <= m; i1++) {
            dp[i][0][i1] = INF;
        }
        for (int j = 1; j <= k; j++) {
            for (int i1 = 1; i1 <= m; i1++) {
                dp[i][j][i1] = INF;
                if (c[i] == 0) {
                    dp[i][j][i1] = min(dp[i][j][i1], dp[i - 1][j][i1] + p[i][i1]);
                    for (int j1 = 1; j1 <= m; j1++) {
                        if (j1 == i1) continue;
                        dp[i][j][i1] = min(dp[i][j][i1], dp[i - 1][j - 1][j1] + p[i][i1]);
                    }
                } else {
                    if (c[i] == i1) {
                        dp[i][j][i1] = min(dp[i][j][i1], dp[i - 1][j][i1]);
                        for (int j1 = 1; j1 <= m; j1++) {
                            if (i1 == j1) continue;
                            dp[i][j][i1] = min(dp[i][j][i1], dp[i - 1][j - 1][j1]);
                        }
                    }
                    else dp[i][j][i1] = INF;
                }
                //cout << dp[i][j][i1] << endl;
            }
        }
    }
    long long ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][k][i]);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}