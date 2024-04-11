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
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<vector<int>> d(2, vector<int>(n));
    ll ans = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        if (b[v] != c[v]) {
            d[c[v]][v]++;
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            a[to] = min(a[to], a[v]);
            dfs(to, v);
            for (int j = 0; j < 2; j++) {
                d[j][v] += d[j][to];
            }
        }
        ll dif = min(d[0][v], d[1][v]);
        ans += a[v] * dif * 2;
        d[0][v] -= dif;
        d[1][v] -= dif;
    };
    dfs(0, -1);
    if (d[0][0] + d[1][0] != 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}