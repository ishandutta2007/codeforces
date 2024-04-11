#include <bits/stdc++.h>
using namespace std;
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
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            g[p].emplace_back(i);
        }
        vector<long long> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        int ans = 0;
        vector<long long> t(n);
        function<void(int, int)> Dfs = [&](int v, int p) {
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                Dfs(to, v);
            }
            if (t[v] < l[v]) {
                ans++;
                t[v] = r[v];
            } else {
                t[v] = min(t[v], r[v]);
            }
            if (p != -1) {
                t[p] += t[v];
            }
        };
        Dfs(0, -1);
        cout << ans << '\n';
    }
    return 0;
}