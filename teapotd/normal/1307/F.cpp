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
    vector<Vi> jumps;
    Vi level, pre, post;
    int cnt{0}, depth;

    LCA() {}

    LCA(vector<Vi>& G, int root)
            : jumps(sz(G)), level(sz(G)),
              pre(sz(G)), post(sz(G)) {
        dfs(G, root, root);
        depth = int(log2(sz(G))) + 2;
        rep(j, 0, depth) each(v, jumps)
            v.pb(jumps[v[j]][j]);
    }

    void dfs(vector<Vi>& G, int v, int p) {
        level[v] = p == v ? 0 : level[p]+1;
        jumps[v].pb(p);
        pre[v] = ++cnt;
        each(e, G[v]) if (e != p) dfs(G, e, v);
        post[v] = ++cnt;
    }

    bool isAncestor(int a, int b) {
        return pre[a] <= pre[b] && post[b] <= post[a];
    }

    int operator()(int a, int b) {
        for (int j = depth; j--;)
            if (!isAncestor(jumps[a][j], b))
                a = jumps[a][j];
        return isAncestor(a, b) ? a : jumps[a][0];
    }

    int laq(int a, int lvl) {
        for (int j = depth; j--;)
            if (lvl <= level[jumps[a][j]])
                a = jumps[a][j];
        return a;
    }

    int distance(int a, int b, int c) {
        return level[a] + level[b] - level[c]*2;
    }

    int kthVertex(int a, int b, int c, int k) {
        if (level[a]-k >= level[c])
            return laq(a, level[a]-k);
        k += level[c]*2 - level[a];
        return (k > level[b] ? -1 : laq(b, k));
    }
};

vector<Vi> G;
vector<bool> good;
Vi comp;

void dfs(int v, int c) {
    if (!good[v] || comp[v] != -1) return;
    comp[v] = c;
    each(e, G[v]) dfs(e, c);
}

void addEdge(int i, int j) {
    G[i].pb(j);
    G[j].pb(i);
}

void run() {
    int n, k, r;
    cin >> n >> k >> r;

    G.resize(n*2-1);

    rep(i, 0, n-1) {
        int u, v; cin >> u >> v;
        addEdge(u-1, n+i);
        addEdge(v-1, n+i);
    }

    n = sz(G);

    queue<int> que;
    Vi dist(n, -1);

    rep(i, 0, r) {
        int v; cin >> v;
        v--;
        que.push(v);
        dist[v] = 0;
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each(e, G[v]) {
            if (dist[e] == -1) {
                dist[e] = dist[v]+1;
                que.push(e);
            }
        }
    }

    good.resize(n);
    rep(i, 0, n) good[i] = dist[i] <= k;

    comp.resize(n, -1);
    int cnt = 0;

    rep(i, 0, n) if (comp[i] == -1) {
        dfs(i, cnt++);
    }

    LCA lca(G, 0);
    int q; cin >> q;

    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;

        int c = lca(a, b);
        bool ok;

        if (lca.distance(a, b, c) <= k*2) {
            ok = 1;
        } else {
            int u = lca.kthVertex(a, b, c, k);
            int v = lca.kthVertex(b, a, c, k);
            ok = (good[u] && good[v] && comp[u] == comp[v]);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}