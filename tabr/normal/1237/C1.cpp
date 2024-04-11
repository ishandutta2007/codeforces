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
    map<int, map<int, set<pair<int, int>>>> st;
    map<int, multiset<int>> mst;
    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        st[x][y].emplace(z, i + 1);
        mst[x].emplace(y);
        xs[i] = x;
    }
    sort(xs.begin(), xs.end());
    for (int i = 0; i < n; i += 2) {
        int ys = *mst[xs[i]].begin();
        mst[xs[i]].erase(mst[xs[i]].begin());
        auto p = *st[xs[i]][ys].begin();
        st[xs[i]][ys].erase(p);
        int xt = xs[i + 1];
        auto it = mst[xt].lower_bound(ys);
        if (it == mst[xt].end()) {
            it = prev(it);
        }
        int yt = *it;
        mst[xt].erase(it);
        auto jt = st[xt][yt].lower_bound({p.first, -1});
        if (jt == st[xt][yt].end()) {
            jt = prev(jt);
        }
        auto q = *jt;
        st[xt][yt].erase(jt);
        cout << p.second << " " << q.second << '\n';
    }
    return 0;
}