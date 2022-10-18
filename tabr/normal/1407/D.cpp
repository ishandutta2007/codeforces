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
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    vector<int> inc, dec;
    inc.emplace_back(h[0]);
    dec.emplace_back(h[0]);
    vector<int> x, y;
    x.emplace_back(1);
    y.emplace_back(1);
    for (int i = 1; i < n; i++) {
        debug(i, inc, dec);
        dp[i] = dp[i - 1] + 1;
        if (h[i - 1] < h[i]) {
            while (!dec.empty() && dec.back() < h[i]) {
                dec.pop_back();
                dp[i] = min(dp[i], y.back());
                y.pop_back();
            }
            if (!y.empty()) {
                dp[i] = min(dp[i], y.back());
            }
        } else if (h[i - 1] > h[i]) {
            while (!inc.empty() && inc.back() > h[i]) {
                inc.pop_back();
                dp[i] = min(dp[i], x.back());
                x.pop_back();
            }
            if (!x.empty()) {
                dp[i] = min(dp[i], x.back());
            }
        }
        while (!inc.empty() && inc.back() >= h[i]) {
            inc.pop_back();
            x.pop_back();
        }
        while (!dec.empty() && dec.back() <= h[i]) {
            dec.pop_back();
            y.pop_back();
        }
        inc.emplace_back(h[i]);
        dec.emplace_back(h[i]);
        x.emplace_back(dp[i] + 1);
        y.emplace_back(dp[i] + 1);
    }
    cout << dp[n - 1] << '\n';
    return 0;
}