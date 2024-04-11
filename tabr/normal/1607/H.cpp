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
        vector<int> a(n), b(n), m(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> m[i];
            mp[a[i] + b[i] - m[i]].emplace_back(i);
        }
        vector<int> x(n), y(n);
        int ans = 0;
        for (auto [key, val] : mp) {
            vector<pair<int, int>> c;
            for (int i : val) {
                c.emplace_back(max(0, a[i] - m[i]), a[i] - max(0, m[i] - b[i]));
            }
            sort(c.begin(), c.end(), [&](auto i, auto j) {
                return i.second < j.second;
            });
            vector<int> d;
            for (auto p : c) {
                if (d.empty() || d.back() < p.first) {
                    d.emplace_back(p.second);
                    ans++;
                }
            }
            for (int i : val) {
                int z = *lower_bound(d.begin(), d.end(), max(0, a[i] - m[i]));
                x[i] = a[i] - z;
                y[i] = m[i] - x[i];
            }
        }
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << x[i] << " " << y[i] << '\n';
        }
    }
    return 0;
}