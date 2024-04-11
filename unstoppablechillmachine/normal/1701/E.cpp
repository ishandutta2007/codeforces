#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int inf = 1e9 + 10;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, inf));
        vector<vector<int>> lcp(m + 1, vector<int>(n + 1, inf));
        vector<vector<bool>> can(m + 1, vector<bool>(n + 1, false));
        can[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j < n && can[i][j]) {
                    can[i][j + 1] = true;
                }
                if (j < n && i < m && s[j] == t[i] && can[i][j]) {
                    can[i + 1][j + 1] = true;
                }
            }
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (t[i] != s[j]) {
                    lcp[i][j] = 0;
                    continue;
                }
                lcp[i][j] = 1;
                if (i > 0 && j > 0) {
                    lcp[i][j] += lcp[i - 1][j - 1];
                }
            }
        }
        dp[0][n] = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = n; j >= 0; j--) {
                if (j > 0) {
                    dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + 1);
                }
                if (j > 0 && i < m && s[j - 1] == t[m - i - 1]) {
                    dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + 1);
                    if (lcp[m - i - 1][j - 1] == m - i && lcp[m - i - 1][j - 1] == j) {
                        dp[m][0] = min(dp[m][0], dp[i][j]);
                    } else {
                        int k = lcp[m - i - 1][j - 1];
                        dp[i + k][j - k] = min(dp[i + k][j - k], dp[i][j] + 1 + (j - k));
                        if (can[m - i][j]) {
                            dp[m][0] = min(dp[m][0], dp[i][j] + 1 + (j - k) + (j - m + i));
                        }
                    }
                }
            }
        }
        cout << (dp[m][0] == inf ? -1 : dp[m][0]) << '\n';
    }
    return 0;
}