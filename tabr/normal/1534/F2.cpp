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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(w);
    vector<vector<int>> c(w);
    vector<vector<int>> g;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') {
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
    vector<int> cc = scc(g);
    g = scc_graph(g, cc);
    int inf = (int) 1e9;
    vector<int> l(cc.size(), inf), r(cc.size(), -inf);
    for (int i = 0; i < w; i++) {
        if (c[i].empty()) {
            continue;
        }
        l[cc[c[i][0]]] = min(l[cc[c[i][0]]], i);
        r[cc[c[i][0]]] = max(r[cc[c[i][0]]], i);
    }
    for (int i = 0; i < (int) g.size(); i++) {
        for (int j : g[i]) {
            l[j] = min(l[i], l[j]);
            r[j] = max(r[i], r[j]);
        }
    }
    vector<pair<int, int>> seg;
    for (int i = 0; i < w; i++) {
        if (b[i] != 0) {
            int j = (int) c[i].size() - b[i];
            seg.emplace_back(l[cc[c[i][j]]], r[cc[c[i][j]]] + 1);
        }
    }
    sort(seg.begin(), seg.end(), [&](auto i, auto j) {
        if (i.second == j.second) {
            return i.first < j.first;
        }
        return i.second < j.second;
    });
    int ans = 0;
    int now = -1;
    for (auto [ll, rr] : seg) {
        if (now <= ll) {
            ans++;
            now = rr;
        }
    }
    cout << ans << '\n';
    return 0;
}