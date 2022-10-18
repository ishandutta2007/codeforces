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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; i--) {
            vector<int> b(n + 10);
            for (int j = i; j < n; j++) {
                b[min(n + 9, a[j])] = 1;
                for (int l = 0; l < n + 9; l++) {
                    if (!b[l]) {
                        dp[i][j + 1] = l + 1;
                        break;
                    }
                }
                for (int l = i + 1; l < j + 1; l++) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][l] + dp[l][j + 1]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans += dp[i][j + 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}