#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> topsort(vector<vector<int>> g) {
    int n = g.size();
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> g(n), rg(n);
    vector<int> can(n, 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        g[a[i]].emplace_back(b[i]);
        rg[b[i]].emplace_back(a[i]);
    }
    vector<int> x = topsort(g);
    if (x.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> was(n);
    string ans = string(n, 'E');
    int k = 0;
    function<void(int, int)> dfs = [&](int v, int q) {
        if (q == 1) {
            for (int to : g[v]) {
                if (was[to] & q) {
                    continue;
                }
                was[to] |= q;
                dfs(to, q);
            }
        } else {
            for (int to : rg[v]) {
                if (was[to] & q) {
                    continue;
                }
                was[to] |= q;
                dfs(to, q);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            ans[i] = 'A';
            was[i] = 3;
            k++;
        }
        dfs(i, 1);
        dfs(i, 2);
    }
    cout << k << '\n';
    cout << ans << '\n';
    return 0;
}