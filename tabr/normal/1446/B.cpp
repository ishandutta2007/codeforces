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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = max(0, max(dp[i + 1][j], dp[i][j + 1]) - 1);
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
            }
            ans = max(ans, dp[i + 1][j + 1]);
        }
    }
    cout << ans << '\n';
    return 0;
}