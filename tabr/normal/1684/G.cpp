#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct matching {
    vector<vector<int>> g;
    vector<int> pa;
    vector<int> pb;
    vector<int> was;
    int n, m;
    int res;
    int iter;

    matching(int _n, int _m) : n(_n), m(_m) {
        pa.assign(n, -1);
        pb.assign(m, -1);
        was.resize(n);
        g.resize(n);
        res = 0;
        iter = 0;
    }

    void add(int from, int to) {
        g[from].emplace_back(to);
    }

    bool dfs(int v) {
        was[v] = iter;
        for (int u : g[v]) {
            if (pb[u] == -1) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        for (int u : g[v]) {
            if (was[pb[u]] != iter && dfs(pb[u])) {
                pa[v] = u;
                pb[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        while (true) {
            iter++;
            int add = 0;
            for (int i = 0; i < n; i++) {
                if (pa[i] == -1 && dfs(i)) {
                    add++;
                }
            }
            if (add == 0) {
                break;
            }
            res += add;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> b(2);
    for (int i = 0; i < n; i++) {
        if (a[i] * 3LL <= m) {
            b[1].emplace_back(a[i]);
        } else {
            b[0].emplace_back(a[i]);
        }
    }
    int sz0 = (int) b[0].size();
    int sz1 = (int) b[1].size();
    if (sz0 > sz1) {
        cout << -1 << '\n';
        return 0;
    }
    matching mat(sz0, sz1);
    for (int i = 0; i < sz0; i++) {
        for (int j = 0; j < sz1; j++) {
            int x = b[0][i];
            int y = b[1][j];
            if (x % y != 0 || 2LL * x + y > m) {
                continue;
            }
            mat.add(i, j);
        }
    }
    if (mat.solve() != sz0) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int, int>> ans;
    vector<int> c(sz1);
    for (int i = 0; i < sz0; i++) {
        int j = mat.pa[i];
        assert(!c[j]);
        c[j] = 1;
        ans.emplace_back(b[0][i] + b[1][j], b[0][i] * 2 + b[1][j]);
    }
    for (int i = 0; i < sz1; i++) {
        if (c[i]) {
            continue;
        }
        ans.emplace_back(b[1][i] * 2, b[1][i] * 3);
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
    return 0;
}