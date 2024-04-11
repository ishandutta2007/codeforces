#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> scc(vector<vector<int>> g, int& cnt) {
    int n = g.size();
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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a != b) g[a].emplace_back(b);
        }
        int cnt;
        vector<int> t = scc(g, cnt);
        if (cnt == 1) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
            vector<int> a, b;
            for (int i = 0; i < n; i++) {
                if (t[i] == 0) {
                    b.emplace_back(i + 1);
                } else {
                    a.emplace_back(i + 1);
                }
            }
            cout << a.size() << " " << b.size() << '\n';
            for (int i : a) {
                cout << i << " ";
            }
            cout << '\n';
            for (int i : b) {
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}