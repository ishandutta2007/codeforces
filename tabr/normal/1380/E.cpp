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
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    vector<set<pair<int, int>>> x(m);
    vector<vector<pair<int, int>>> z(m);
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--;
        if (z[t[i]].empty() || z[t[i]].back().second + 1 != i) {
            z[t[i]].emplace_back(i, i);
            res++;
        } else {
            z[t[i]].back().second++;
        }
    }
    for (int i = 0; i < m; i++) {
        x[i] = set<pair<int, int>>(z[i].begin(), z[i].end());
    }
    res--;
    cout << res << '\n';
    for (int i = 1; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        swap(a, b);
        if (x[a].size() > x[b].size()) {
            swap(x[a], x[b]);
        }
        for (auto p : x[a]) {
            auto it = x[b].upper_bound(p);
            if (it != x[b].end()) {
                auto q = *it;
                if (q.first == p.second + 1) {
                    res--;
                }
            }
            it = x[b].upper_bound(p);
            if (it != x[b].begin()) {
                it = prev(it);
                auto q = *it;
                if (q.second + 1 == p.first) {
                    res--;
                }
            }
        }
        for (auto p : x[a]) {
            x[b].emplace(p);
        }
        cout << res << '\n';
    }
    return 0;
}