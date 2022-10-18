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
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    vector<int> a(n);
    ll ans = 0;
    vector<int> sz(n);
    int s = -1;
    vector<int> order;
    function<void(int, int)> dfs = [&](int v, int p) {
        order.emplace_back(v);
        sz[v]++;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
            sz[v] += sz[to];
        }
        if (s == -1 && n - sz[v] <= n / 2) {
            s = v;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                if (sz[to] > n / 2) {
                    s = -1;
                    break;
                }
            }
        }
        ans += min(sz[v], n - sz[v]);
    };
    dfs(0, -1);
    ans *= 2;
    cout << ans << '\n';
    order.clear();
    dfs(s, -1);
    for (int i = 0; i < n; i++) {
        a[order[i]] = order[(i + n / 2) % n];
    }
    for (int i : a) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}