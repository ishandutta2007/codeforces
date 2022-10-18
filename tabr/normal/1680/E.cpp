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
        int n;
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        long long ans = (long long) 1e18;
        vector<vector<vector<long long>>> c(2);
        for (int z = 0; z < 2; z++) {
            vector<vector<long long>> dp(n, vector<long long>(2));
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (found) {
                    for (int j = 0; j < 2; j++) {
                        dp[i][j] = dp[i - 1][j] + 1 + (s[j ^ 1][i] == '*');
                        dp[i][j] = min(dp[i][j], dp[i - 1][j ^ 1] + 2);
                    }
                } else {
                    if (s[0][i] == '*' || s[1][i] == '*') {
                        dp[i][0] = (s[1][i] == '*');
                        dp[i][1] = (s[0][i] == '*');
                        found = true;
                    } else {
                        dp[i][0] = dp[i][1] = 0;
                    }
                }
                dp[i][0] = min(dp[i][0], dp[i][1] + 1);
                dp[i][1] = min(dp[i][1], dp[i][0] + 1);
            }
            swap(c[z], dp);
            reverse(s[0].begin(), s[0].end());
            reverse(s[1].begin(), s[1].end());
        }
        for (int i = 0; i < n; i++) {
            ans = min(ans, c[0][i][0] + c[1][n - 1 - i][0]);
            ans = min(ans, c[0][i][1] + c[1][n - 1 - i][1]);
        }
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, c[0][i][0] + c[1][n - 2 - i][0] + 1);
            ans = min(ans, c[0][i][1] + c[1][n - 2 - i][1] + 1);
        }
        if (ans == 2) {
            int d = 0;
            for (int i = 0; i < n; i++) {
                if (s[0][i] == '*' || s[1][i] == '*') {
                    d++;
                }
            }
            if (d == 1) {
                ans = 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}