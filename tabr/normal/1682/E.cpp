#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> topsort(const vector<vector<int>> &g) {
    int n = (int) g.size();
    vector<int> deg(n);
    for (int v = 0; v < n; v++) {
        for (int to : g[v]) {
            deg[to]++;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            res.emplace_back(i);
        }
    }
    for (int i = 0; i < (int) res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int) res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(i);
        g[y].emplace_back(i);
        edges.emplace_back(x, y);
    }
    vector<vector<int>> f(m);
    vector<int> was(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        if (was[i]) {
            continue;
        }
        int v = i;
        vector<int> a;
        while (!was[v]) {
            a.emplace_back(v);
            was[v] = 1;
            v = p[v];
        }
        int sz = (int) a.size();
        for (int j = 0; j < sz; j++) {
            pos[a[j]] = j;
        }
        for (int j = 0; j < sz; j++) {
            int x = a[j];
            sort(g[x].begin(), g[x].end(), [&](int id, int jd) {
                int toi = x ^ edges[id].first ^ edges[id].second;
                int toj = x ^ edges[jd].first ^ edges[jd].second;
                int difi = (pos[toi] - j + sz) % sz;
                int difj = (pos[toj] - j + sz) % sz;
                return difi < difj;
            });
            for (int k = 0; k < (int) g[x].size() - 1; k++) {
                f[g[x][k]].emplace_back(g[x][k + 1]);
            }
        }
    }
    auto c = topsort(f);
    assert(!c.empty());
    for (int i = 0; i < m; i++) {
        cout << c[i] + 1 << " \n"[i == m - 1];
    }
    return 0;
}