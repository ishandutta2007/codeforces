#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

struct Solution {
    int n, k, gt, x, y;
    vector<vector<int>> g;
    vector<pi> edg;
    vector<int> tl, tr, par, s;

    Solution(int n, int k, int x0, int y0, vector<pi> edg0, vector<int> a0) : 
        n(n), k(k), gt(0), x(x0-1), y(y0-1),
        g(n), edg(edg0), tl(n), tr(n), par(n), s(a0) {
        for (int& x : s) x--;

        for (auto& [a, b] : edg) {
            g[a-1].push_back(b-1);
            g[b-1].push_back(a-1);
            a--, b--;
        }
    }

    void dfs(int v, int p = -1) {
        tl[v] = gt++;
        par[v] = p;
        for (int to : g[v]) {
            if (to != p) dfs(to, v);
        }
        tr[v] = gt;
    }

    int solve() {
        dfs(x);

        vector<int> ps(n+1);

        for (int v : s) ps[tl[v]+1]++;
        for (int i = 0; i < n; ++i) ps[i+1] += ps[i];

        int ans = 0;
        for (auto [a, b] : edg) {
            if (par[a] == b) swap(a, b);

            if (tl[b] <= tl[y] && tr[y] <= tr[b]) {
                ans++;
            } else {
                if (ps[tr[b]] != ps[tl[b]]) ans += 2;
            }
        }

        return ans;
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        int x, y; cin >> x >> y;

        vector<int> a(k);
        for (int& x : a) cin >> x;

        vector<pi> edg(n-1);
        for (auto& [a, b] : edg) cin >> a >> b;

        Solution sol(n, k, x, y, edg, a);
        int ans = sol.solve();
        cout << ans << '\n';
    }
}