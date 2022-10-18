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
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = 1e18;
        vector<string> t = {"LL", "LR", "RL", "RR"};
        vector<vector<int>> a = {{1, 3}, {0, 1, 3}, {0, 1, 2}, {0, 2}};
        vector<int> b = {2, 1, 0, 3};
        for (int l = 0; l < 4; l++) {
            vector<ll> dp(4, 1e9);
            ll x = 0;
            for (int i = 0; i < 2; i++) {
                x += (s[i] != t[l][i]);
            }
            dp[b[l]] = x;
            for (int i = 2; i < n; i++) {
                vector<ll> ndp(4);
                ndp[2] = dp[0] + (s[i] != 'L');
                ndp[3] = dp[1] + (s[i] != 'R');
                ndp[0] = min(dp[1], dp[3]) + (s[i] != 'L');
                ndp[1] = min(dp[0], dp[2]) + (s[i] != 'R');
                swap(dp, ndp);
            }
            for (int i : a[l]) {
                ans = min(ans, dp[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}