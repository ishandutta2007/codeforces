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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> depth(n), sz(n, 1), val(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        val[v] = depth[v];
        for (int to : g[v]) {
            if (to == p) continue;
            depth[to] = depth[v] + 1;
            dfs(to, v);
            sz[v] += sz[to];
        }
        val[v] -= sz[v] - 1;
    };
    dfs(0, -1);
    sort(val.rbegin(), val.rend());
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += val[i];
    }
    cout << ans << '\n';
    return 0;
}