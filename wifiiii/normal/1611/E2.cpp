#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k);
        vector<vector<int>> g(n);
        for(int i = 0; i < k; ++i) cin >> a[i], --a[i];
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> dfn(n), dep(n); int tot = 0;
        int lg = 32 - __builtin_clz(n);
        vector<vector<int>> f(n, vector<int>(lg, -1));
        vector<int> p(n);
        function<void(int,int)> dfs = [&](int u, int fa) {
            dfn[u] = tot++;
            p[u] = u;
            for(int v : g[u]) {
                if(v == fa) continue;
                f[v][0] = u;
                for(int i = 1; i < lg; ++i) {
                    if(f[v][i-1] != -1) f[v][i] = f[f[v][i-1]][i-1];
                }
                dep[v] = dep[u] + 1;
                dfs(v, u);
                p[u] = p[v];
            }
        };
        dfs(0, -1);
        auto lca = [&](int u, int v) {
            if(dep[u] < dep[v]) swap(u, v);
            for(int d = dep[u] - dep[v], i = lg - 1; i >= 0; --i) {
                if(d >> i & 1) u = f[u][i];
            }
            if(u == v) return u;
            for(int i = lg - 1; i >= 0; --i) {
                if(f[u][i] != -1 && f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
            }
            return f[u][0];
        };
        auto d = [&](int u, int v) {return dep[u] + dep[v] - 2 * dep[lca(u, v)];};
        vector<int> l;
        for(int i = 1; i < n; ++i) {
            if(g[i].size() == 1) l.push_back(i);
        }
        sort(l.begin(), l.end(), [&](int i, int j) {return dfn[i] < dfn[j];});
        vector<pair<int,int>> seg(k);
        for(int i = 0; i < k; ++i) {
            int u = a[i];
            int x = lower_bound(l.begin(), l.end(), p[u], [&](int i, int j) {return dfn[i] < dfn[j];}) - l.begin();
            int lb, rb;
            {
                int lo = 0, hi = x;
                while(lo < hi) {
                    int mid = (lo + hi) / 2;
                    if(d(u, l[mid]) <= dep[l[mid]]) hi = mid;
                    else lo = mid + 1;
                }
                lb = lo;
            }
            {
                int lo = x, hi = l.size() - 1;
                while(lo < hi) {
                    int mid = (lo + hi + 1) / 2;
                    if(d(u, l[mid]) <= dep[l[mid]]) lo = mid;
                    else hi = mid - 1;
                }
                rb = lo;
            }
            seg[i] = {lb, rb};
        }
        sort(seg.begin(), seg.end());
        int cur = 0, mx = 0, ok = 1, ans = 0;
        seg.push_back({l.size(), l.size()});
        for(auto [x, y] : seg) {
            if(x <= cur) {
                mx = max(mx, y + 1);
            } else {
                ans += 1;
                cur = mx;
                if(x > mx) ok = 0;
                mx = max(mx, y + 1);
            }
        }
        if(ok) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}