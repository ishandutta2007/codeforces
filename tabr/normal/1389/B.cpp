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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, z;
        cin >> n >> k >> z;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<ll>> dp(n, vector<ll>(z + 1));
        dp[0][0] = a[0];
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j <= z; j++) {
                if (i - 2 * j < 0) {
                    continue;
                }
                if (i - 2 * j != 0) {
                    dp[i - 2 * j][j] = dp[i - 2 * j - 1][j] + a[i - 2 * j];
                }
                if (j) {
                    dp[i - 2 * j][j] = max(dp[i - 2 * j][j], dp[i - 2 * j + 1][j - 1] + a[i - 2 * j]);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= z; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}