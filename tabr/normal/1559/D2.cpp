#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu d1(n), d2(n);
    for (int i = 0; i < m1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d1.unite(x, y);
    }
    for (int i = 0; i < m2; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        d2.unite(x, y);
    }
    if (m1 < m2) {
        swap(d1, d2);
        swap(m1, m2);
    }
    vector<map<int, int>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        int p1 = d1.get(i), p2 = d2.get(i);
        x[p1][p2] = i;
        y[p2][p1] = i;
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        if (d1.get(i) == i) {
            st.emplace(-(int) x[i].size(), i);
        }
    }
    int z = n - 1 - max(m1, m2);
    cout << z << '\n';
    while (z--) {
        int a = st.begin()->second;
        st.erase(st.begin());
        int b = st.begin()->second;
        st.erase(st.begin());
        if (x[a].size() > x[b].size()) {
            swap(a, b);
        }
        auto p1 = *x[a].begin();
        pair<int, int> p2 = *x[b].begin();
        if (p1.first == p2.first) {
            p2 = *x[b].rbegin();
        }
        cout << p1.second + 1 << " " << p2.second + 1 << '\n';
        int c = p1.first;
        int d = p2.first;
        assert(c != d);
        if (y[c].size() > y[d].size()) {
            swap(c, d);
        }
        for (auto [fi, se] : x[a]) {
            x[b][fi] = se;
            y[fi].erase(a);
            y[fi][b] = se;
        }
        for (auto [fi, se] : y[c]) {
            y[d][fi] = se;
            x[fi].erase(c);
            x[fi][d] = se;
        }
        st.emplace(-(int) x[b].size(), b);
    }
    return 0;
}