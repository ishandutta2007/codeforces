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

struct DSU {
    struct Entry {
        int v, p, r, c;
    };

    Vi par, rank, col;
    vector<Entry> hist;

    DSU(int n) {
        par.resize(n, -1);
        rank.resize(n, 0);
        col.resize(n, 0);
    }

    Pii find(int v) {
        if (par[v] != -1) {
            Pii t = find(par[v]);
            if (col[v] == -1 || t.y == -1) return {t.x, -1};
            return {t.x, t.y ^ col[v]};
        }
        return {v, col[v]};
    }

    void push(int i) {
        hist.pb({i, par[i], rank[i], col[i]});
    }

    void revert(int i) {
        while (sz(hist) > i) {
            auto t = hist.back();
            hist.pop_back();
            par[t.v] = t.p;
            rank[t.v] = t.r;
            col[t.v] = t.c;
        }
    }

    bool join(int u, int v) {
        Pii a = find(u);
        Pii b = find(v);

        if (a.x == b.x) {
            if (a.y == b.y) {
                push(a.x);
                col[a.x] = -1;
                return 0;
            }
            return 1;
        }

        if (rank[a.x] < rank[b.x]) {
            swap(a, b);
            swap(u, v);
        }
        
        push(a.x);
        push(b.x);

        par[b.x] = a.x;
        rank[a.x] += (rank[a.x] == rank[b.x]);

        if (col[a.x] == -1 || col[b.x] == -1) {
            col[a.x] = -1;
        } else {
            col[b.x] ^= col[a.x] ^ (a.y == b.y);
        }

        return col[a.x] != -1;
    }
};

int n, m, k;
Vi group;
vector<Vi> G;

vector<Vi> groupComps;
Vi color, comp, compGroup;
vector<bool> bip, okGroup;
int nComps = 0;

bool dfs(int v, int c, int id) {
    if (color[v] != -1) {
        return color[v] == c;
    }

    bool ret = 1;
    color[v] = c;
    comp[v] = id;

    each(e, G[v]) if (group[v] == group[e]) {
        if (!dfs(e, !c, id)) {
            ret = 0;
        }
    }

    return ret;
}

void run() {
    cin >> n >> m >> k;

    G.resize(n);
    group.resize(n);

    each(j, group) {
        cin >> j;
        j--;
    }

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    color.resize(n, -1);
    comp.resize(n, -1);
    groupComps.resize(k);

    rep(i, 0, n) {
        if (comp[i] == -1) {
            bool good = dfs(i, 0, nComps);
            bip.pb(good);
            compGroup.pb(group[i]);
            groupComps[group[i]].pb(nComps);
            nComps++;
        }
    }

    ll tot = 0;

    each(g, groupComps) {
        bool ok = 1;
        each(j, g) {
            ok = ok && bip[j];
        }
        tot += ok;
        okGroup.pb(ok);
    }

    deb(tot);

    ll ans = tot * (tot-1) / 2;

    vector<pair<Pii, Pii>> cross;
    DSU dsu(n);

    rep(v, 0, n) {
        each(u, G[v]) {
            if (group[u] < group[v]) {
                cross.pb({ {group[u], group[v]} , {u, v} });
            } else if (group[u] == group[v]) {
                dsu.join(u, v);
            }
        }
    }

    sort(all(cross));
    int st = sz(dsu.hist);

    rep(i, 0, sz(cross)) {
        if (i > 0 && cross[i-1].x == cross[i].x) {
            continue;
        }

        int g1 = cross[i].x.x;
        int g2 = cross[i].x.y;
        if (!okGroup[g1] || !okGroup[g2]) {
            continue;
        }

        dsu.revert(st);
        bool ok = 1;

        rep(j, i, sz(cross)) {
            if (cross[i].x != cross[j].x) break;
            int u = cross[j].y.x;
            int v = cross[j].y.y;
            if (!dsu.join(u, v)) {
                ok = 0;
                break;
            }
        }

        if (!ok) {
            ans--;
        }
    }

    cout << ans << '\n';
}