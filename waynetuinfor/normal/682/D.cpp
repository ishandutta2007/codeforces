#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxk = 11;
const int inf = 1e9;
int dp[2][maxk][maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;
    a = "," + a; b = "," + b;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int k = 0; k < maxk; ++k) dp[0][k][i][j] = dp[1][k][i][j] = -inf;
        }
    }
    dp[0][0][0][0] = 0;
    for (int i = 0; i < maxn; ++i) dp[0][0][i][0] = dp[0][0][0][i] = 0;
    for (int c = 0; c <= k; ++c) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[0][c][i][j] = max(dp[0][c][i - 1][j], dp[0][c][i][j - 1]);
                if (a[i] == b[j] && c) dp[0][c][i][j] = max(dp[0][c][i][j], dp[0][c - 1][i - 1][j - 1] + 1);
                if (a[i] == b[j] && c) dp[1][c][i][j] = max(dp[1][c][i][j], dp[0][c - 1][i - 1][j - 1] + 1);
                if (a[i] == b[j]) dp[0][c][i][j] = max(dp[0][c][i][j], dp[1][c][i - 1][j - 1] + 1);
                if (a[i] == b[j]) dp[1][c][i][j] = max(dp[1][c][i][j], dp[1][c][i - 1][j - 1] + 1);
                // cout << "dp[0][" << c << "][" << i << "][" << j << "] = " << dp[0][c][i][j] << "    ";
                // cout << "dp[1][" << c << "][" << i << "][" << j << "] = " << dp[1][c][i][j] << endl;
            }
        }
    }
    int ans = 0;
    for (int c = 0; c <= k; ++c) for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) ans = max(ans, dp[0][c][i][j]); 
    }
    cout << ans << endl;
    return 0;
}