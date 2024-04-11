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
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<int> a;
        vector<int> cut(n);
        auto dfs = [&](auto &&self, int v, int p) -> void {
            int b = 0;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                self(self, to, v);
                if (cut[to]) {
                    continue;
                } else {
                    b++;
                }
            }
            if (v != 0) {
                if (b != 0) {
                    a.emplace_back(b);
                    cut[v] = 1;
                }
            } else {
                for (int i = 0; i < b; i++) {
                    a.emplace_back(0);
                }
            }
        };
        dfs(dfs, 0, -1);
        int s = accumulate(a.begin(), a.end(), 0);
        sort(a.begin(), a.end());
        int t = 0;
        int u = 0;
        for (int i : a) {
            if (i == 0) {
                t++;
            } else {
                u++;
            }
        }
        if (t >= 1) {
            cout << s + t - u << '\n';
        } else {
            cout << s + t - (u - 1) << '\n';
        }
    }
    return 0;
}