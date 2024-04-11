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
    iota(a.begin(), a.end(), 0);
    ll ans = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            dfs(to, v);
        }
        if (p != -1 && a[v] == v) {
            swap(a[v], a[p]);
            ans += 2;
        }
    };
    dfs(0, -1);
    debug(ans, a);
    if (a[0] == 0) {
        ans += 2;
        swap(a[0], a[g[0][0]]);
    }
    cout << ans << '\n';
    for (int i : a) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}