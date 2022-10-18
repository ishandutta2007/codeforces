#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<int> a(n);
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    for (int d = 1; d < n; d++) {
        for (int i = 0; i + d < n; i++) {
            for (int j = 0; j < d; j++) {
                if (dp[i][i + j] == dp[i + j + 1][i + d] && dp[i][i + j] != -1) {
                    dp[i][i + d] = dp[i][i + j] + 1;
                }
            }
        }
    }
    vector<int> ans(n + 1, 1e9);
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp[i][j] != -1) {
                ans[j + 1] = min(ans[j + 1], ans[i] + 1);
            }
        }
    }
    cout << ans[n] << '\n';
    return 0;
}