#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int s;
    cin >> s;
    s--;
    vector<int> was(n), ok(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        was[v] = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (was[to]) {
                ok[v] = 1;
                continue;
            }
            dfs(to, v);
            if (ok[to]) {
                ok[v] = 1;
            }
        }
    };
    dfs(s, -1);
    ok[s] = 1;
    debug(ok);
    ll ans = 0;
    ll mx = 0;
    function<ll(int, int)> f = [&](int v, int p) {
        ll res = 0;
        for (int to : g[v]) {
            if (to == p || ok[to]) {
                continue;
            }
            res = max(res, f(to, v));
        }
        if (p != -1) {
            res += w[v];
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        if (ok[i]) {
            ans += w[i];
            mx = max(mx, f(i, -1));
        }
    }
    ans += mx;
    cout << ans << '\n';
    return 0;
}