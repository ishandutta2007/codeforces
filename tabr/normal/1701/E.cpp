#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        const int inf = (int) 1e9;
        vector<vector<int>> dp(m + 1, vector<int>(3, inf));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 0; i <= n; i++) {
            vector<vector<int>> new_dp(m + 1, vector<int>(3, inf));
            for (int j = 0; j <= m; j++) {
                dp[j][1] = min(dp[j][1], dp[j][0]);
                dp[j][2] = min(dp[j][1], dp[j][2]);
                if (i + 1 <= n) {
                    new_dp[j][0] = min(new_dp[j][0], dp[j][0] + 2);
                }
                if (i + 1 <= n && j + 1 <= m && s[i] == t[j]) {
                    new_dp[j + 1][0] = min(new_dp[j + 1][0], dp[j][0] + 1);
                }
                if (i + 1 <= n && j + 1 <= m && s[i] == t[j]) {
                    new_dp[j + 1][1] = min(new_dp[j + 1][1], dp[j][1]);
                }
                if (i + 1 <= n) {
                    new_dp[j][2] = min(new_dp[j][2], dp[j][2] + 1);
                }
                if (i + 1 <= n && j + 1 <= m && s[i] == t[j]) {
                    new_dp[j + 1][2] = min(new_dp[j + 1][2], dp[j][2] + 1);
                }
            }
            if (i < n) {
                swap(dp, new_dp);
            }
        }
        if (dp[m][2] == inf) {
            cout << -1 << '\n';
        } else {
            cout << dp[m][2] << '\n';
        }
    }
    return 0;
}