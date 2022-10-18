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
    vector<string> s(n);
    vector<int> a(n);
    vector<int> mn(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int d = 0;
        for (char c : s[i]) {
            if (c == '(') {
                d++;
            } else {
                d--;
            }
            mn[i] = min(mn[i], d);
        }
        a[i] = d;
    }
    vector<int> c(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                c[mask] += a[i];
            }
        }
    }
    vector<vector<int>> add(n, vector<int>(1 << n));
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> p;
        for (int mask = 0; mask < (1 << n); mask++) {
            p.emplace_back(c[mask], mask);
        }
        sort(p.rbegin(), p.rend());
        map<int, int> mp;
        int x = 0;
        for (char d : s[i]) {
            if (d == '(') {
                x++;
            } else {
                x--;
            }
            mp[x]++;
            while (!p.empty() && x + p.back().first < 0) {
                if (mp.count(-p.back().first)) {
                    add[i][p.back().second] = mp[-p.back().first];
                }
                p.pop_back();
            }
        }
        while (!p.empty()) {
            if (mp.count(-p.back().first)) {
                add[i][p.back().second] = mp[-p.back().first];
            }
            p.pop_back();
        }
    }
    vector<int> dp(1 << n, -(int) 1e9);
    dp[0] = 0;
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            ans = max(ans, dp[mask] + add[i][mask]);
            if (c[mask] + mn[i] >= 0) {
                dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + add[i][mask]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}