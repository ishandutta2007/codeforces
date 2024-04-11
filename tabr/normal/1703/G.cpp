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
        long long k;
        cin >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        const long long inf = (long long) 1e18;
        vector<long long> dp(35, -inf);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> new_dp(35, -inf);
            for (int j = 0; j < 35; j++) {
                new_dp[j] = max(new_dp[j], dp[j] + (a[i] >> j) - k);
                if (j + 1 < 35) {
                    new_dp[j + 1] = max(new_dp[j + 1], dp[j] + (a[i] >> (j + 1)));
                } else {
                    new_dp[j] = max(new_dp[j], dp[j] + (a[i] >> (j + 1)));
                }
            }
            swap(dp, new_dp);
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}