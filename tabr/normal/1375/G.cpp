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
    vector<int> depth(n);
    function<void(int, int)> dfs = [&](int v, int p) {
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            depth[to] = depth[v] + 1;
            dfs(to, v);
        }
    };
    dfs(0, -1);
    vector<int> a(2, -1);
    for (int i = 0; i < n; i++) {
        a[depth[i] % 2]++;
    }
    cout << min(a[0], a[1]) << '\n';
    return 0;
}