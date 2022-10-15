#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    enum Type {leave, enter};
    vector<tuple<int, Type, int>> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.emplace_back(l, enter, i);
        events.emplace_back(r + 1, leave, i);
    }
    sort(begin(events), end(events));
    vector<int> o(1 << k);
    for (int mask = 1; mask < (1 << k); ++mask) {
        int lsb = mask & -mask;
        o[mask] = 1 ^ o[mask ^ lsb];
    }
    vector<int> dp(1 << k, -m), I(k, -1);
    int last = 0;
    dp[0] = 0;
    for (auto [x, t, i] : events) {
        if (last != x) {
            for (int mask = 0; mask < (1 << k); ++mask) {
                dp[mask] += (x - last) * o[mask];
            }
            last = x;
        }
        if (t == enter) {
            int j = 0;
            while (I[j] != -1) ++j;
            I[j] = i;
            for (int mask = 0; mask < (1 << k); ++mask) {
                if (~mask >> j & 1) {
                    chmax(dp[mask | 1 << j], dp[mask]);
                }
            }
        }
        else {
            int j = 0;
            while (I[j] != i) ++j;
            I[j] = -1;
            for (int mask = 0; mask < (1 << k); ++mask) {
                if (mask >> j & 1) {
                    chmax(dp[mask ^ (1 << j)], dp[mask]);
                    dp[mask] = -m;
                }
            }
        }
    }
    int ans = *max_element(begin(dp), end(dp));
    cout << ans << endl;
    exit(0);
}