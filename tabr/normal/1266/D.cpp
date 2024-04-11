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
    vector<vector<int>> ing(n), outg(n);
    vector<ll> inc(n), outc(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        ing[y].emplace_back(i);
        outg[x].emplace_back(i);
        inc[y] += z;
        outc[x] += z;
    }
    vector<pair<ll, int>> ie, oe;
    for (int i = 0; i < n; i++) {
        if (inc[i] == outc[i]) {
            continue;
        }
        if (inc[i] > outc[i]) {
            ie.emplace_back(inc[i] - outc[i], i);
        }
        if (inc[i] < outc[i]) {
            oe.emplace_back(outc[i] - inc[i], i);
        }
    }
    int pi = 0, po = 0;
    vector<pair<pair<int, int>, ll>> ans;
    while (pi < ie.size() && po < oe.size()) {
        if (ie[pi].first == oe[po].first) {
            ans.emplace_back(make_pair(ie[pi].second, oe[po].second), ie[pi].first);
            pi++, po++;
            continue;
        }
        if (ie[pi].first > oe[po].first) {
            ans.emplace_back(make_pair(ie[pi].second, oe[po].second), oe[po].first);
            ie[pi].first -= oe[po].first;
            po++;
        } else {
            ans.emplace_back(make_pair(ie[pi].second, oe[po].second), ie[pi].first);
            oe[po].first -= ie[pi].first;
            pi++;
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first.second + 1 << " " << e.first.first + 1 << " " << e.second << '\n';
    }
    return 0;
}