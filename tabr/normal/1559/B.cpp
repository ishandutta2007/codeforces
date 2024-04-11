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
        string s;
        cin >> s;
        const int inf = (int) 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(2, inf));
        dp[0][0] = dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'B') {
                dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1]);
            }
            if (s[i] != 'R') {
                dp[i + 1][1] = min(dp[i][0], dp[i][1] + 1);
            }
        }
        int t = 0;
        if (s[n - 1] != '?') {
            if (s[n - 1] == 'B') {
                t = 1;
            }
        } else if (dp[n][0] > dp[n][1]) {
            t = 1;
        }
        string x = "RB";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '?') {
                s[i] = x[t];
            } else {
                assert(s[i] == x[t]);
            }
            if (dp[i + 1][t] == dp[i][t ^ 1]) {
                t ^= 1;
            } else if (dp[i + 1][t] == dp[i][t] + 1) {
            } else {
                assert(false);
            }
        }
        cout << s << '\n';
    }
    return 0;
}