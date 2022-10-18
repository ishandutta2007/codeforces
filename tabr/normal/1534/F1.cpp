#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> scc(const vector<vector<int>> &g, int &cnt) {
    int n = (int) g.size();
    cnt = 0;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(w);
    vector<vector<int>> c(w);
    vector<string> s(h);
    vector<vector<int>> g;
    vector<int> px, py;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                px.emplace_back(i);
                py.emplace_back(j);
                a[j].emplace_back(i);
                c[j].emplace_back((int) g.size());
                g.emplace_back();
            }
        }
    }
    vector<int> b(w);
    for (int i = 0; i < w; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j + 1 < (int) a[i].size(); j++) {
            g[c[i][j]].emplace_back(c[i][j + 1]);
            if (a[i][j] + 1 == a[i][j + 1]) {
                g[c[i][j + 1]].emplace_back(c[i][j]);
            }
        }
        for (int j = 0; j < (int) a[i].size(); j++) {
            if (i != 0) {
                int k = (int) (lower_bound(a[i - 1].begin(), a[i - 1].end(), a[i][j]) - a[i - 1].begin());
                if (k != (int) c[i - 1].size()) {
                    g[c[i][j]].emplace_back(c[i - 1][k]);
                }
            }
            if (i != w - 1) {
                int k = (int) (lower_bound(a[i + 1].begin(), a[i + 1].end(), a[i][j]) - a[i + 1].begin());
                if (k != (int) c[i + 1].size()) {
                    g[c[i][j]].emplace_back(c[i + 1][k]);
                }
            }
        }
    }
    int cnt;
    vector<int> sc = scc(g, cnt);
    vector<vector<int>> f(cnt);
    for (int i = 0; i < (int) g.size(); i++) {
        for (int j : g[i]) {
            if (sc[i] != sc[j]) {
                f[sc[i]].emplace_back(sc[j]);
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        sort(f[i].begin(), f[i].end());
        f[i].resize(unique(f[i].begin(), f[i].end()) - f[i].begin());
    }
    swap(f, g);
    int ans = 0;
    vector<int> was(g.size());
    function<void(int, int)> dfs = [&](int v, int p) {
        was[v] = 1;
        for (int to : g[v]) {
            if (to == p || was[to]) {
                continue;
            }
            dfs(to, v);
        }
    };
    for (int i = 0; i < (int) g.size(); i++) {
        if (was[i]) {
            continue;
        }
        ans++;
        dfs(i, -1);
    }
    cout << ans << '\n';
    return 0;
}