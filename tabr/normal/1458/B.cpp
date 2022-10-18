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
    int n;
    cin >> n;
    cout << fixed << setprecision(12);
    int inf = (int)1e9;
    int m = 20020;
    vector<vector<int>> dp(n + 1, vector<int>(m, inf));
    dp[0][0] = 0;
    int all = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        all += 2 * b;
        a = 2 * (a - b);
        vector<vector<int>> new_dp(n + 1, vector<int>(m, inf));
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k + a < m; k++) {
                if (dp[j][k] == inf) {
                    continue;
                }
                new_dp[j + 1][k + a] = min(new_dp[j + 1][k + a], dp[j][k]);
                new_dp[j][k] = min(new_dp[j][k], dp[j][k] + b);
            }
        }
        swap(dp, new_dp);
    }
    cout << fixed << setprecision(12);
    for (int i = 1; i <= n; i++) {
        int ans = all;
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == inf) {
                continue;
            }
            ans = min(ans, dp[i][j] + max(dp[i][j] - j, 0));
        }
        cout << 0.5L * (all - ans) << " ";
    }
    cout << '\n';
    return 0;
}