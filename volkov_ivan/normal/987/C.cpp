#include <iostream>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    int s[n + 1], c[n + 1];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    int dp[3][n + 1];
    for (int i = 1; i <= n; i++) dp[0][i] = c[i];
    dp[0][0] = dp[1][0] = dp[2][0] = INF;
    int ans = INF;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
            for (int last = j - 1; last > 0; last--) {
                if (dp[i - 1][last] != INF && s[last] < s[j]) dp[i][j] = min(dp[i][j], dp[i - 1][last] + c[j]);
            }
            if (i == 2) ans = min(ans, dp[i][j]);
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}