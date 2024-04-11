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
        vector<int> a(n + 3);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(2, vector<int>(n + 3, 1e9));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            dp[1][i + 1] = min(dp[1][i + 1], dp[0][i] + a[i]);
            dp[0][i + 1] = min(dp[0][i + 1], dp[1][i]);
            dp[1][i + 2] = min(dp[1][i + 2], dp[0][i] + a[i] + a[i + 1]);
            dp[0][i + 2] = min(dp[0][i + 2], dp[1][i]);
        }
        cout << min(dp[0][n], dp[1][n]) << '\n';
    }
    return 0;
}