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
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        int k = (int) sqrt(2 * n) + 10;
        long long inf = (long long) 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
        dp[n][0] = inf;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            for (int j = 1; j <= k; j++) {
                if (i + j > n) {
                    break;
                }
                long long c = pref[i + j] - pref[i];
                if (c < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], c);
                }
            }
        }
        for (int i = k; i >= 0; i--) {
            if (dp[0][i] > 0) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}