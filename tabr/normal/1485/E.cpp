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
        vector<vector<int>> to(n);
        vector<int> p(n, -1);
        for (int i = 1; i < n; i++) {
            cin >> p[i];
            p[i]--;
            to[p[i]].emplace_back(i);
        }
        vector<int> a(n);
        for (int i = 1; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> d(1);
        d[0].emplace_back(0);
        while (true) {
            vector<int> nxt;
            for (int i : d.back()) {
                for (int j : to[i]) {
                    nxt.emplace_back(j);
                }
            }
            if (nxt.empty()) {
                break;
            }
            d.emplace_back(nxt);
        }
        int inf = (int)2e9;
        vector<long long> dp(n), cmin(n), cmax(n);
        long long acmin = 0, acmax = 0;
        int amin = 0, amax = 0;
        for (auto v : d) {
            for (int i : v) {
                if (p[i] == -1) {
                    continue;
                }
                dp[i] = max(acmax - a[i], acmin + a[i]);
                dp[i] = max(dp[i], dp[p[i]] + max(a[i] - amin, amax - a[i]));
            }
            acmin = acmax = -inf;
            amin = inf;
            amax = -inf;
            for (int i : v) {
                int mn = inf, mx = -inf;
                for (int j : to[i]) {
                    mn = min(mn, a[j]);
                    mx = max(mx, a[j]);
                }
                cmin[i] = dp[i] - mn;
                cmax[i] = dp[i] + mx;
                acmin = max(acmin, cmin[i]);
                acmax = max(acmax, cmax[i]);
                amin = min(mn, amin);
                amax = max(mx, amax);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}