#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

struct LCA {
    Vi par, jmp, depth, pre, post;
    int cnt{0};

    LCA() {}

    LCA(vector<Vi>& G, int v) : par(sz(G), -1), jmp(sz(G), v), depth(sz(G)), pre(sz(G)), post(sz(G)) {
        dfs(G, v);
    }

    void dfs(vector<Vi>& G, int v) {
        int j = jmp[v], k = jmp[j], x =
            depth[v]+depth[k] == depth[j]*2 ? k : v;
        pre[v] = ++cnt;
        each(e, G[v]) if (!pre[e]) {
            par[e] = v; jmp[e] = x;
            depth[e] = depth[v]+1;
            dfs(G, e);
        }
        post[v] = ++cnt;
    }

    int laq(int v, int d) {
        while (depth[v] > d)
            v = depth[jmp[v]] < d ? par[v] : jmp[v];
        return v;
    }

    int operator()(int a, int b) {
        if (depth[a] > depth[b]) swap(a, b);
        b = laq(b, depth[a]);
        while (a != b) {
            if (jmp[a] == jmp[b])
                a = par[a], b = par[b];
            else
                a = jmp[a], b = jmp[b];
        }
        return a;
    }

    int dist(int a, int b) {
        return depth[a] + depth[b] - depth[operator()(a, b)]*2;
    }
};

void run() {
    int n; cin >> n;
    vector<Vi> G(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    LCA lca(G, 0);
    int q; cin >> q;

    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;

        int dist1 = lca.dist(a, b);
        int dist2 = lca.dist(a, x) + lca.dist(b, y) + 1;
        int dist3 = lca.dist(a, y) + lca.dist(b, x) + 1;

        bool ans = 0;

        if (k >= dist1 && (k%2 == dist1%2)) ans = 1;
        if (k >= dist2 && (k%2 == dist2%2)) ans = 1;
        if (k >= dist3 && (k%2 == dist3%2)) ans = 1;

        cout << (ans ? "YES\n" : "NO\n");
    }
}