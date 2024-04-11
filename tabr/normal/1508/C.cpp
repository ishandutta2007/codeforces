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
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    int all = 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        if (u[i] > v[i]) {
            swap(u[i], v[i]);
        }
        g[u[i]].emplace_back(v[i]);
        g[v[i]].emplace_back(u[i]);
        all ^= w[i];
    }
    dsu uf(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.emplace(i);
    }
    int cnt = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (!st.count(i)) {
            continue;
        }
        cnt++;
        for (int to : g[i]) {
            a[to]++;
        }
        st.erase(i);
        while (true) {
            vector<int> del;
            for (int j : st) {
                if (a[j] != cnt) {
                    del.emplace_back(j);
                }
            }
            if (del.empty()) {
                break;
            }
            for (int j : del) {
                uf.unite(i, j);
                st.erase(j);
                for (int to : g[j]) {
                    a[to]++;
                }
                cnt++;
            }
        }
    }
    int es = n;
    for (int i = 0; i < n; i++) {
        if (i != uf.get(i)) {
            continue;
        }
        es--;
    }
    if (es < 1LL * n * (n - 1) / 2 - m) {
        all = 0;
    }
    long long ans = 0;
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return w[i] < w[j];
    });
    vector<int> t;
    for (int i : order) {
        auto [from, to, cost] = tie(u[i], v[i], w[i]);
        if (uf.unite(from, to)) {
            ans += cost;
            t.emplace_back(i);
        }
    }
    uf = dsu(n);
    for (int i : t) {
        auto [from, to, cost] = tie(u[i], v[i], w[i]);
        uf.unite(from, to);
    }
    for (int i : order) {
        auto [from, to, cost] = tie(u[i], v[i], w[i]);
        if (uf.unite(from, to) && cost < all) {
            ans += cost;
            all = 0;
        }
    }
    ans += all;
    cout << ans << '\n';
    return 0;
}