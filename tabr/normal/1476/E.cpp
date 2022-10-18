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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mp[s[i]] = i;
    }
    vector<vector<int>> g(n + m);
    for (int i = 0; i < m; i++) {
        string t;
        int a;
        cin >> t >> a;
        a--;
        bool ok = false;
        for (int j = 0; j < (1 << k); j++) {
            string u = t;
            for (int l = 0; l < k; l++) {
                if (j & (1 << l)) {
                    u[l] = '_';
                }
            }
            if (mp.find(u) != mp.end()) {
                int p = mp[u];
                if (p == a) {
                    ok = true;
                } else {
                    g[n + i].emplace_back(p);
                }
            }
        }
        if (!ok) {
            cout << "NO" << '\n';
            return 0;
        }
        g[a].emplace_back(n + i);
    }
    int cs = 0;
    vector<int> c = scc(g, cs);
    if (cs != n + m) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    vector<int> ans(n + m);
    for (int i = 0; i < n + m; i++) {
        ans[c[i]] = i + 1;
    }
    for (int i = 0; i < n + m; i++) {
        if (ans[i] <= n) {
            cout << ans[i] << " ";
        }
    }
    cout << '\n';
    return 0;
}