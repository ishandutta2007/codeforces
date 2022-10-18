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
        long long x, y;
        cin >> n >> x >> y;
        x = min(x, 2 * y);
        string a, b;
        cin >> a >> b;
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                t.emplace_back(i);
            }
        }
        if (t.size() % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        if (x >= y) {
            if (t.size() == 2 && t[1] - t[0] == 1) {
                cout << x << '\n';
            } else {
                cout << y * t.size() / 2 << '\n';
            }
            continue;
        }
        const long long inf = (long long) 1e18;
        vector<long long> dp(2, inf);
        dp[0] = 0;
        for (int i = 0; i < (int) t.size(); i++) {
            vector<long long> new_dp(2, inf);
            new_dp[0] = min(dp[0], dp[1]);
            if (i + 1 < (int) t.size()) {
                new_dp[1] = dp[0] - y + x * (t[i + 1] - t[i]);
            }
            swap(dp, new_dp);
        }
        long long ans = y * (int) t.size() / 2;
        ans += min(0LL, dp[0]);
        cout << ans << '\n';
    }
    return 0;
}