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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        vector<vector<int>> a(k);
        vector<int> b(k, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                for (int j = 0; j < k; j++) {
                    if (s[i] != (char) ('a' + j)) {
                        b[j] = i;
                    }
                }
            }
            for (int j = 0; j < k; j++) {
                if (i - mid + 1 > b[j]) {
                    a[j].emplace_back(i - mid + 1);
                }
            }
        }
        int inf = (int) 1e9;
        vector<int> dp(1 << k, inf);
        dp[0] = -mid;
        for (int mask = 1; mask < (1 << k); mask++) {
            for (int i = 0; i < k; i++) {
                if (mask & (1 << i)) {
                    if (dp[mask ^ (1 << i)] == inf) {
                        continue;
                    }
                    auto it = lower_bound(a[i].begin(), a[i].end(), dp[mask ^ (1 << i)] + mid);
                    if (it == a[i].end()) {
                        continue;
                    }
                    dp[mask] = min(dp[mask], *it);
                }
            }
        }
        debug(dp);
        if (dp.back() != inf) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';
    return 0;
}