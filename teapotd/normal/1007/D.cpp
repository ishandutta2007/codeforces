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

struct SAT2 : Vi {
    vector<Vi> G;
    Vi order, flags;

    SAT2(int n = 0) : G(n*2) {}

    int addVar() {
        G.resize(sz(G)+2); return sz(G)/2;
    }

    void imply(int i, int j) {
        i = max(i*2-1, -i*2-2);
        j = max(j*2-1, -j*2-2);
        G[i].pb(j); G[j^1].pb(i^1);
    }

    void either(int i, int j) { imply(-i, j); }

    bool solve() {
        assign(sz(G)/2+1, -1);
        flags.assign(sz(G), 0);
        rep(i, 0, sz(G)) dfs(i);
        while (!order.empty()) {
            if (!propag(order.back()^1, 1)) return 0;
            order.pop_back();
        }
        return 1;
    }

    void dfs(int i) {
        if (flags[i]) return;
        flags[i] = 1;
        each(e, G[i]) dfs(e);
        order.pb(i);
    }

    bool propag(int i, bool first) {
        if (!flags[i]) return 1;
        flags[i] = 0;
        if (at(i/2+1) >= 0) return first;
        at(i/2+1) = i&1;
        each(e, G[i]) if (!propag(e, 0)) return 0;
        return 1;
    }
};

struct HLD {
    Vi par, size, depth, pos, chBegin, chEnd, order;
    HLD() {}

    HLD(vector<Vi>& G, int root)
            : par(sz(G)), size(sz(G)),
              depth(sz(G)), pos(sz(G)),
              chBegin(sz(G)), chEnd(sz(G)) {
        dfs(G, root, -1);
        decomp(G, root, -1, 0);
    }

    void dfs(vector<Vi>& G, int v, int p) {
        par[v] = p;
        size[v] = 1;
        depth[v] = p < 0 ? 0 : depth[p]+1;
        int& fs = G[v][0];
        if (fs == p) swap(fs, G[v].back());
        each(e, G[v]) if (e != p) {
            dfs(G, e, v);
            size[v] += size[e];
            if (size[e] > size[fs]) swap(e, fs);
        }
    }

    void decomp(vector<Vi>& G, int v, int p, int chb) {
        pos[v] = sz(order);
        chBegin[v] = chb;
        chEnd[v] = pos[v]+1;
        order.pb(v);
        each(e, G[v]) if (e != p) {
            if (e == G[v][0]) {
                decomp(G, e, v, chb);
                chEnd[v] = chEnd[e];
            } else {
                decomp(G, e, v, sz(order));
            }
        }
    }

    int chRoot(int v) {return order[chBegin[v]];}

    template<class T>
    void iterPath(int a, int b, T func) {
        while (chBegin[a] != chBegin[b]) {
            int ha = chRoot(a), hb = chRoot(b);
            if (depth[ha] > depth[hb]) {
                func(chBegin[a], pos[a]+1);
                a = par[ha];
            } else {
                func(chBegin[b], pos[b]+1);
                b = par[hb];
            }
        }
        if (pos[a] > pos[b]) swap(a, b);
        func(pos[a]+1, pos[b]+1);
    }
};

SAT2 sat;
vector<int> first, tree;
int len;

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;

    if (b >= vb && e <= ve) {
        int tmp = sat.addVar();
        sat.imply(tree[i], tmp);
        sat.imply(val, -tree[i]);
        sat.imply(val, tmp);
        tree[i] = tmp;
        return;
    }

    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
}

void run() {
    int n; cin >> n;
    vector<Vi> G(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    int m; cin >> m;
    sat = {m};

    for (len = 1; len < n; len *= 2);
    first.resize(len*2);
    tree.resize(len*2);
    rep(i, 1, len*2) first[i] = tree[i] = sat.addVar();

    HLD hld(G, 0);

    rep(i, 1, m+1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        hld.iterPath(a-1, b-1, [&](int vb, int ve) { add(vb, ve, i); });
        hld.iterPath(c-1, d-1, [&](int vb, int ve) { add(vb, ve, -i); });
    }

    rep(i, 2, len*2) {
        sat.imply(tree[i/2], first[i]);
    }

    if (sat.solve()) {
        cout << "YES\n";
        rep(i, 1, m+1) cout << 2-sat[i] << '\n';
    } else {
        cout << "NO\n";
    }
}