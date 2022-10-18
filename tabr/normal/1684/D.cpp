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
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        for (int i = 0; i < n; i++) {
            a[i] -= n - 1 - i;
        }
        sort(a.rbegin(), a.rend());
        long long ans = sum;
        for (int i = 0; i < k; i++) {
            sum -= a[i];
            sum -= i;
            ans = min(ans, sum);
        }
        cout << ans << '\n';
        // const long long inf = (long long) 1e18;
        // vector<long long> dp(1);
        // for (int i = 0; i < n; i++) {
        //     vector<long long> new_dp(i + 2, inf);
        //     for (int j = 0; j <= i; j++) {
        //         new_dp[j + 1] = min(new_dp[j + 1], dp[j]);
        //         new_dp[j] = min(new_dp[j], dp[j] + a[i] + j);
        //     }
        //     swap(dp, new_dp);
        //     debug(dp);
        // }
    }
    return 0;
}