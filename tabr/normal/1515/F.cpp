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
    int n, m;
    cin >> n >> m;
    long long c;
    dsu uf(n);
    cin >> c;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> u(m), v(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        g[u[i]].emplace_back(i);
        g[v[i]].emplace_back(i);
    }
    if (accumulate(a.begin(), a.end(), 0LL) < c * (n - 1)) {
        cout << "NO" << '\n';
        return 0;
    }
    vector<int> ans;
    set<pair<long long, int>> st;
    for (int i = 0; i < n; i++) {
        st.emplace(a[i], i);
    }
    while ((int)ans.size() < n - 1 || !st.empty()) {
        auto [b, i] = *st.rbegin();
        st.erase({b, i});
        if (g[i].empty()) {
            continue;
        }
        int id = g[i].back();
        g[i].pop_back();
        u[id] = uf.get(u[id]);
        v[id] = uf.get(v[id]);
        int j = uf.get(i ^ u[id] ^ v[id]);
        if (i != j) {
            if (a[i] + a[j] < c) {
                assert(false);
                g[i].insert(g[i].begin(), id);
                continue;
            }
            ans.emplace_back(id);
            st.erase({a[j], j});
            if (g[i].size() < g[j].size()) {
                swap(i, j);
            }
            uf.unite(j, i);
            a[i] = a[i] + a[j] - c;
            a[j] = -1;
            st.emplace(a[i], i);
            g[i].insert(g[i].end(), g[j].begin(), g[j].end());
            g[j].clear();
        } else {
            st.emplace(b, i);
        }
    }
    cout << "YES" << '\n';
    for (int i : ans) {
        cout << i + 1 << '\n';
    }
    return 0;
}