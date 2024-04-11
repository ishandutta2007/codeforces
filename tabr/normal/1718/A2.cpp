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
        int ans = 0;
        for (int i = 0, j = 0; i < n; i = j) {
            if (a[i] == 0) {
                j = i + 1;
                continue;
            }
            while (j < n && a[j] != 0) {
                j++;
            }
            vector<int> b;
            b.emplace_back(0);
            for (int k = i; k < j; k++) {
                b.emplace_back(b.back() ^ a[k]);
            }
            debug(b);
            int sz = j - i;
            const int inf = (int) 1e9;
            vector<int> dp(sz + 1, inf);
            dp[0] = 0;
            map<int, int> mp;
            mp[0] = 0;
            for (int x = 1; x <= sz; x++) {
                dp[x] = dp[x - 1];
                if (mp.count(b[x])) {
                    dp[x] = min(dp[x], mp[b[x]] - 1);
                }
                mp[b[x]] = min(mp[b[x]], dp[x]);
                /*
                for (int y = x + 1; y < sz + 1; y++) {
                    if (b[x] == b[y]) {
                        dp[y] = min(dp[y], dp[x] - 1);
                    } else {
                        dp[y] = min(dp[y], dp[x]);
                    }
                }
                */
            }
            ans += dp[sz] + sz;
        }
        cout << ans << '\n';
    }
    return 0;
}