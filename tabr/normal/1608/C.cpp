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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> x(n);
        iota(x.begin(), x.end(), 0);
        auto y = x;
        sort(x.begin(), x.end(), [&](int i, int j) { return a[i] > a[j]; });
        sort(y.begin(), y.end(), [&](int i, int j) { return b[i] > b[j]; });
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            g[x[i]].emplace_back(x[i + 1]);
            g[y[i]].emplace_back(y[i + 1]);
        }
        auto c = scc(g);
        for (int i = 0; i < n; i++) {
            if (c[i] == 0) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << '\n';
    }
    return 0;
}