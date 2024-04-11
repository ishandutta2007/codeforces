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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<int> depth(n);
        vector<int> was(n);
        vector<int> pv(n);
        function<void(int, int)> dfs = [&](int v, int p) {
            was[v] = 1;
            for (int to : g[v]) {
                if (was[to]) {
                    continue;
                }
                pv[to] = v;
                depth[to] = depth[v] + 1;
                dfs(to, v);
            }
        };
        pv[0] = -1;
        dfs(0, -1);
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (depth[i] + 1 == (n + 1) / 2) {
                ok = true;
                cout << "PATH" << '\n';
                cout << (n + 1) / 2 << '\n';
                int v = i;
                while (v != -1) {
                    cout << v + 1 << " ";
                    v = pv[v];
                }
                cout << '\n';
                break;
            }
        }
        if (ok) {
            continue;
        }
        int x = ((n + 1) / 2 + 1) / 2;
        cout << "PAIRING" << '\n';
        cout << x << '\n';
        vector<vector<int>> a((n + 1) / 2);
        for (int i = 0; i < n; i++) {
            a[depth[i]].emplace_back(i);
        }
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j + 1 < a[i].size(); j += 2) {
                if (x == 0) {
                    break;
                }
                cout << a[i][j] + 1 << " " << a[i][j + 1] + 1 << '\n';
                x--;
            }
            if (x == 0) {
                break;
            }
        }
        assert(x == 0);
    }
    return 0;
}