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
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        const long long inf = (long long) 1e18;
        long long ans = inf;
        for (int z = 0; z < 2; z++) {
            vector<long long> dp(3, inf);
            dp[0] = 0;
            dp[1] = abs(1 - a[0]);
            dp[2] = (x - 1) + abs(x - a[0]);
            for (int i = 0; i < n - 1; i++) {
                vector<long long> new_dp(3, inf);
                long long dif = abs(a[i + 1] - a[i]);
                for (int j = 0; j < 3; j++) {
                    new_dp[j] = dp[j] + dif;
                }
                new_dp[1] = min(new_dp[1], dp[0] + abs(a[i] - 1) + abs(1 - a[i + 1]));
                new_dp[2] = min(new_dp[2], dp[1] + abs(a[i] - x) + abs(x - a[i + 1]));
                new_dp[2] = min(new_dp[2], dp[0] + abs(a[i] - 1) + (x - 1) + abs(x - a[i + 1]));
                swap(dp, new_dp);
            };
            ans = min(ans, dp[2]);
            ans = min(ans, dp[1] + abs(x - a[n - 1]));
            ans = min(ans, dp[0] + (x - 1) + abs(x - a[n - 1]));
            reverse(a.begin(), a.end());
        }
        cout << ans << '\n';
    }
    return 0;
}