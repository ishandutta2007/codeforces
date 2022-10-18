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
    long long t;
    cin >> n >> t;
    vector<long long> g(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> c[i];
    }
    vector<long long> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> d[i];
    }
    vector<long long> pref(n);
    for (int i = 0; i < n - 1; i++) {
        pref[i + 1] = pref[i] + d[i];
    }
    for (int i = 0; i < n; i++) {
        c[i] += pref[i];
        c[i] %= t;
    }
    set<tuple<long long, long long, long long>> s0, s1;
    auto Add = [&](long long x, long long y, long long z) {
        s0.emplace(x, y, z);
        s1.emplace(y, x, z);
    };
    auto Remove = [&](tuple<long long, long long, long long> x) {
        s0.erase(x);
        swap(get<0>(x), get<1>(x));
        s1.erase(x);
    };
    if (c[0] < g[0]) {
        Add(0, g[0] - c[0], 0);
    }
    if (0 < c[0]) {
        Add(t - c[0], min(t, t - c[0] + g[0]), 0);
    }
    for (int i = 1; i < n; i++) {
        long long best = (long long) 9e18;
        vector<pair<long long, long long>> segs;
        segs.emplace_back(g[i] - c[i], t - c[i]);
        segs.emplace_back(t - c[i] + g[i], t);
        for (auto [beg, end] : segs) {
            beg = max(beg, 0LL);
            if (beg >= end) {
                continue;
            }
            while (true) {
                auto iter = s0.lower_bound(make_tuple(beg, -1, -1));
                if (iter == s0.end()) {
                    break;
                }
                auto p = *iter;
                if (get<0>(p) >= end) {
                    break;
                }
                Remove(p);
                if (end < get<1>(p)) {
                    Add(end, get<1>(p), get<2>(p));
                }
                if (get<0>(p) < beg) {
                    Add(get<0>(p), beg, get<2>(p));
                }
                long long now = min(end, get<1>(p) - 1);
                if (now <= t - c[i]) {
                    best = min(best, get<2>(p) + (t - c[i]) - now);
                } else {
                    best = min(best, get<2>(p) + t + (t - c[i]) - now);
                }
            }
            while (true) {
                auto iter = s1.lower_bound(make_tuple(beg + 1, -1, -1));
                if (iter == s1.end()) {
                    break;
                }
                auto p = *iter;
                swap(get<0>(p), get<1>(p));
                if (get<0>(p) >= end) {
                    break;
                }
                Remove(p);
                if (end < get<1>(p)) {
                    Add(end, get<1>(p), get<2>(p));
                }
                if (get<0>(p) < beg) {
                    Add(get<0>(p), beg, get<2>(p));
                }
                long long now = min(end, get<1>(p) - 1);
                if (now <= t - c[i]) {
                    best = min(best, get<2>(p) + (t - c[i]) - now);
                } else {
                    best = min(best, get<2>(p) + t + (t - c[i]) - now);
                }
            }
        }
        if (best < (long long) 8e18) {
            Add((t - c[i]) % t, (t - c[i]) % t + 1, best);
        }
    }
    long long ans = (long long) 9e18;
    for (auto p : s0) {
        ans = min(ans, get<2>(p));
    }
    ans += pref[n - 1];
    cout << ans << '\n';
    return 0;
}