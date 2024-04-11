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
    int n;
    cin >> n;
    vector<int> h(n);
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
    int r = (int) (max_element(h.begin(), h.end()) - h.begin());
    long long ans = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        vector<int> c;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            c.emplace_back(dfs(to, v));
        }
        if (c.empty()) {
            return h[v];
        }
        sort(c.rbegin(), c.rend());
        if (p == -1) {
            if (g[v].size() == 1) {
                ans += h[v];
                ans += max(h[v], c[0]);
                return 0;
            }
            for (int i = 2; i < (int) c.size(); i++) {
                ans += c[i];
            }
            ans += max(h[v], c[0]);
            ans += max(h[v], c[1]);
            return 0;
        }
        for (int i = 1; i < (int) c.size(); i++) {
            ans += c[i];
        }
        return max(h[v], c[0]);
    };
    dfs(r, -1);
    cout << ans << '\n';
    return 0;
}