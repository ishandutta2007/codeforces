#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> scc(vector<vector<int>> g, int &cnt) {
    int n = (int)g.size();
    cnt = 0;
    vector<vector<int>> rg(n);
    vector<int> order, c(n, -1);
    vector<bool> was(n);
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            rg[j].emplace_back(i);
        }
    }
    function<void(int)> dfs1 = [&](int v) {
        was[v] = true;
        for (int u : g[v]) {
            if (!was[u]) {
                dfs1(u);
            }
        }
        order.emplace_back(v);
    };
    function<void(int)> dfs2 = [&](int v) {
        for (int u : rg[v]) {
            if (c[u] == -1) {
                c[u] = c[v];
                dfs2(u);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            dfs1(i);
        }
    }
    for (int id = n - 1; id >= 0; id--) {
        int i = order[id];
        if (c[i] == -1) {
            c[i] = cnt++;
            dfs2(i);
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), g_scc(n);
    vector<int> a(m), b(m);
    vector<long long> l(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y >> l[i];
        x--, y--;
        g_scc[x].emplace_back(y);
        g[x].emplace_back(i);
        a[i] = x;
        b[i] = y;
    }
    int k;
    vector<int> c = scc(g_scc, k);
    debug(c);
    vector<long long> f(k, -1);
    vector<long long> d(n, -1);
    for (int i = 0; i < n; i++) {
        if (f[c[i]] != -1) {
            continue;
        }
        vector<long long> cl;
        function<void(int)> dfs = [&](int v) {
            for (int id : g[v]) {
                int to = v ^ a[id] ^ b[id];
                if (c[to] != c[v]) {
                    continue;
                } else if (d[to] != -1) {
                    cl.emplace_back(d[v] + l[id] - d[to]);
                    continue;
                }
                d[to] = d[v] + l[id];
                dfs(to);
            }
        };
        d[i] = 0;
        dfs(i);
        f[c[i]] = 0;
        for (auto e : cl) {
            f[c[i]] = gcd(f[c[i]], e);
        }
    }
    debug(f);
    int q;
    cin >> q;
    while (q--) {
        int v;
        long long s, t;
        cin >> v >> s >> t;
        v--;
        long long gg = gcd(f[c[v]], t);
        if (s % gg == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}