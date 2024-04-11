#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> scc(const vector<vector<int>> &g) {
    int n = (int) g.size();
    int cnt = 0;
    vector<vector<int>> rev_g(n);
    vector<int> order;
    vector<int> res(n, -1);
    vector<bool> was(n);
    for (int i = 0; i < n; i++) {
        for (int j : g[i]) {
            rev_g[j].emplace_back(i);
        }
    }
    function<void(int)> dfs1 = [&](int v) {
        was[v] = true;
        for (int to : g[v]) {
            if (!was[to]) {
                dfs1(to);
            }
        }
        order.emplace_back(v);
    };
    function<void(int)> dfs2 = [&](int v) {
        for (int to : rev_g[v]) {
            if (res[to] == -1) {
                res[to] = res[v];
                dfs2(to);
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
        if (res[i] == -1) {
            res[i] = cnt++;
            dfs2(i);
        }
    }
    return res;
}

vector<vector<int>> scc_graph(const vector<vector<int>> &g, const vector<int> &c) {
    vector<vector<int>> new_g(c.size());
    for (int i = 0; i < (int) g.size(); i++) {
        for (int j : g[i]) {
            if (c[i] < c[j]) {
                new_g[c[i]].emplace_back(c[j]);
            }
        }
    }
    for (int i = 0; i < (int) new_g.size(); i++) {
        sort(new_g[i].begin(), new_g[i].end());
        new_g[i].resize(unique(new_g[i].begin(), new_g[i].end()) - new_g[i].begin());
    }
    return new_g;
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
        vector<int> lp(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            if (x == y) {
                lp[x] = 1;
            }
        }
        vector<int> c = scc(g);
        int cc = *max_element(c.begin(), c.end()) + 1;
        auto f = scc_graph(g, c);
        vector<int> cnt(cc);
        vector<int> id(cc);
        vector<int> ans(cc);
        for (int i = 0; i < n; i++) {
            cnt[c[i]]++;
            id[c[i]] = i;
        }
        ans[c[0]] = 1;
        for (int i = c[0]; i < cc; i++) {
            if (ans[i] == 0) {
                continue;
            }
            if (cnt[i] != 1) {
                ans[i] = -1;
            } else if (lp[id[i]]) {
                ans[i] = -1;
            }
            for (int j : f[i]) {
                if (ans[i] != 1) {
                    if (ans[j] != -1) {
                        ans[j] = ans[i];
                    }
                } else {
                    if (ans[j] == 0) {
                        ans[j] = 1;
                    } else if (ans[j] == 1) {
                        ans[j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[c[i]] << " ";
        }
        cout << '\n';
    }
    return 0;
}