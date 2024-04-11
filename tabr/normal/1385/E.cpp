#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> topsort(vector<vector<int>> g) {
    int n = (int)g.size();
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
    for (int i = 0; i < (int)res.size(); i++) {
        int v = res[i];
        for (int to : g[v]) {
            if (--deg[to] == 0) {
                res.emplace_back(to);
            }
        }
    }
    if ((int)res.size() != n) {
        return vector<int>();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> t(m), x(m), y(m);
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            cin >> t[i] >> x[i] >> y[i];
            x[i]--, y[i]--;
            if (t[i]) {
                g[x[i]].emplace_back(y[i]);
            }
        }
        vector<int> c = topsort(g);
        if (c.empty()) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[c[i]] = i;
        }
        for (int i = 0; i < m; i++) {
            if (d[x[i]] > d[y[i]]) {
                swap(x[i], y[i]);
            }
            cout << x[i] + 1 << " " << y[i] + 1 << '\n';
        }
    }
    return 0;
}