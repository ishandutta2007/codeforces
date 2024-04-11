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

struct FAU {
    Vi G;
    FAU(int n = 0) : G(n, -1) {}
    int size(int i) { return -G[find(i)]; }
    int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return 0;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return 1;
    }
};

int n;
vector<Pii> elems;

bool can(int bits) {
    int mask = (1<<bits)-1;
    FAU fau(1 << bits);
    Vi deg(1 << bits);

    each(e, elems) {
        fau.join(e.x & mask, e.y & mask);
        deg[e.x & mask]++;
        deg[e.y & mask]++;
    }

    vector<bool> seen(1 << bits);
    int comps = 0;

    rep(i, 0, sz(deg)) {
        if (deg[i] % 2) {
            return 0;
        }
        int j = fau.find(i);
        if (deg[i] > 0 && !seen[j]) {
            seen[j] = 1;
            comps++;
        }
    }

    return comps == 1;
}

vector<Vi> G;
Vi ind, walk;
vector<Pii> edges;
vector<bool> seen;

void euler(int v) {
    while (true) {
        int i = ind[v];
        if (i >= sz(G[v])) break;

        int e = G[v][i];
        ind[v]++;
        if (seen[e]) continue;

        seen[e] = 1;
        euler(edges[e].x == v ? edges[e].y : edges[e].x);

        if (edges[e].x == v) {
            walk.pb(2*(e+1));
            walk.pb(2*(e+1)-1);
        } else {
            walk.pb(2*(e+1)-1);
            walk.pb(2*(e+1));
        }
    }
}

void solve(int bits) {
    int mask = (1<<bits) - 1;
    G.resize(1 << bits);
    ind.resize(1 << bits);

    rep(i, 0, sz(elems)) {
        int u = elems[i].x & mask;
        int v = elems[i].y & mask;
        edges.pb({u, v});
        G[u].pb(sz(edges)-1);
        G[v].pb(sz(edges)-1);
    }

    seen.resize(sz(edges));
    rep(i, 0, sz(G)) euler(i);

    cout << bits << '\n';
    each(j, walk) cout << j << ' ';
    cout << '\n';
}

void run() {
    cin >> n;
    elems.resize(n);

    each(e, elems) {
        cin >> e.x >> e.y;
    }

    for (int i = 20; i >= 0; i--) {
        if (can(i)) {
            solve(i);
            return;
        }
    }

    assert(0);
}