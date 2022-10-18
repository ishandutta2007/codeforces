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
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> p(n), h(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<ll> a(n), ok(n), ng(n);
        function<void(int, int)> dfs = [&](int v, int pr) {
            a[v] = p[v];
            for (int to : g[v]) {
                if (to == pr) {
                    continue;
                }
                dfs(to, v);
                a[v] += a[to];
            }
        };
        dfs(0, -1);
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            ok[i] = a[i] + h[i];
            ng[i] = a[i] - h[i];
            if (ok[i] % 2 == 1 || ng[i] % 2 == 1 || ok[i] < 0 || ng[i] < 0) {
                ans = "NO";
            }
            ok[i] /= 2;
            ng[i] /= 2;
        }
        debug(ng, ans);
        function<void(int, int)> check = [&](int v, int pr) {
            ll x = 0;
            for (int to : g[v]) {
                if (to == pr) {
                    continue;
                }
                x += ng[to];
                check(to, v);
            }
            if (x < ng[v] - p[v]) {
                debug(v);
                ans = "NO";
            }
        };
        check(0, -1);
        cout << ans << '\n';
    }
    return 0;
}