#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct edge {
    int v, c, w;
};
struct edge2 {
    int u, v, c, w;
    bool operator < (const edge2 & e) const {
        return c > e.c;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<edge>> g(n);
    vector<edge2> es;
    for(int i = 1; i < n; ++i) {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        --u, --v;
        g[u].push_back({v, c, w});
        g[v].push_back({u, c, w});
        es.push_back({u, v, c, w});
    }
    sort(es.begin(), es.end());

    int lg = 31 - __builtin_clz(n);
    vector<vector<int>> f(n, vector<int>(lg + 1, -1)), mx(n, vector<int>(lg + 1));
    vector<int> dep(n);
    function<void(int,int)> dfs = [&](int u, int fa) {
        for(auto [v, c, w] : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            f[v][0] = u; mx[v][0] = w;
            for(int i = 1; i <= lg; ++i) {
                f[v][i] = f[v][i - 1] == -1 ? -1 : f[f[v][i - 1]][i - 1];
                mx[v][i] = max(f[v][i - 1] == -1 ? 0 : mx[f[v][i - 1]][i - 1], mx[v][i - 1]);
            }
            dfs(v, u);
        }
    };
    dfs(0, -1);
    auto query_max = [&](int u, int v) {
        if(dep[u] < dep[v]) swap(u, v);
        int ret = 0;
        for(int i = lg, d = dep[u] - dep[v]; i >= 0; --i) {
            if(d >> i & 1) {
                ret = max(ret, mx[u][i]);
                u = f[u][i];
            }
        }
        if(u == v) return ret;
        for(int i = lg; i >= 0; --i) {
            if(f[u][i] != f[v][i]) {
                ret = max(ret, max(mx[u][i], mx[v][i]));
                u = f[u][i];
                v = f[v][i];
            }
        }
        ret = max(ret, max(mx[u][0], mx[v][0]));
        return ret;
    };
    vector<tuple<int,int,int>> qs(q);
    for(int i = 0; i < q; ++i) {
        auto &[x, u, id] = qs[i];
        cin >> x >> u;
        --u;
        id = i;
    }
    sort(qs.begin(), qs.end());
    reverse(qs.begin(), qs.end());

    vector<int> par(n), mxa(n), mxau(n), mxw(n);
    for(int i = 0; i < n; ++i) {
        par[i] = i;
        mxa[i] = a[i];
        mxau[i] = i;
        mxw[i] = 0;
    }
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    };
    auto merge = [&](int u, int v) {
        int x = find(u), y = find(v);
        if(x == y) return;
        if(mxa[x] > mxa[y]) mxw[y] = mxw[x];
        else if(mxa[x] == mxa[y]) mxw[y] = max(max(mxw[x], mxw[y]), query_max(mxau[x], mxau[y]));
        mxau[y] = mxa[x] > mxa[y] ? mxau[x] : mxau[y];
        mxa[y] = max(mxa[x], mxa[y]);
        par[x] = y;
    };

    vector<pair<int,int>> ans(q);
    int esi = 0;
    for(auto [x, u, id] : qs) {
        while(esi < es.size() && es[esi].c >= x) {
            merge(es[esi].u, es[esi].v);
            ++esi;
        }
        int p = find(u);
        ans[id].first = mxa[p];
        ans[id].second = max(mxw[p], query_max(u, mxau[p]));
    }

    for(auto [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
}