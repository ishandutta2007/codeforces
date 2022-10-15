#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m, c, c0;
        cin >> n >> m >> c >> c0;
        vector<int> t(n), a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> t[i] >> a[i] >> b[i];
        }
        t.push_back(m);
        a.push_back(0);
        b.push_back(0);
        ++n;
        vector<int> I(n);
        iota(begin(I), end(I), 0);
        sort(begin(I), end(I), [&](int i, int j) { return t[i] < t[j]; });
        map<int, int> mp;
        mp[0] = c0;
        int last = 0, tank = c0;
        ll cost = 0;
        bool good = true;
        for (auto i : I) {
            int need = t[i] - last;
            while (need > 0) {
                if (empty(mp)) {
                    good = false;
                    break;
                }
                auto iter = begin(mp);
                int take = min(iter->second, need);
                cost += 1LL * take * iter->first;
                need -= take;
                tank -= take;
                iter->second -= take;
                if (iter->second == 0) mp.erase(iter);
            }
            last = t[i];
            tank += a[i];
            mp[b[i]] += a[i];
            while (tank > c) {
                auto iter = prev(end(mp));
                int take = min(tank - c, iter->second);
                tank -= take;
                iter->second -= take;
                if (iter->second == 0) mp.erase(iter);
            }
        }
        if (not good) cost = -1;
        cout << cost << '\n';
    }
    exit(0);
}