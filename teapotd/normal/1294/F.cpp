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

int n, ans, bestV;
vector<Vi> G;
Vi depth, deep;

void dfs(int v, int p) {
    depth[v] = 0;
    deep[v] = v;
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        if (depth[e]+1 > depth[v]) {
            depth[v] = depth[e]+1;
            deep[v] = deep[e];
        }
    }
}

void solve(int v, int p, int up) {
    int gr1 = up, gr2 = 0, gr3 = 0;

    each(e, G[v]) if (e != p) {
        int d = depth[e]+1;
        if (d >= gr1) {
            gr3 = gr2;
            gr2 = gr1;
            gr1 = d;
        } else if (d >= gr2) {
            gr3 = gr2;
            gr2 = d;
        } else {
            gr3 = max(gr3, d);
        }
    }

    int alt = gr1+gr2+gr3;
    if (alt > ans && sz(G[v]) >= 2) {
        ans = alt;
        bestV = v;
    }

    each(e, G[v]) if (e != p) {
        int kek = (depth[e]+1 == gr1 ? gr2 : gr1);
        solve(e, v, kek+1);
    }
}

void run() {
    cin >> n;
    G.resize(n);
    depth.resize(n);
    deep.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    ans = -1;
    bestV = -1;
    dfs(0, -1);
    solve(0, -1, 0);

    dfs(bestV, -1);

    vector<Pii> tmp;
    each(e, G[bestV]) tmp.pb({depth[e], deep[e]});
    sort(all(tmp));

    Vi ret;
    rep(i, 0, min(3, sz(tmp))) ret.pb(tmp[sz(tmp)-i-1].y);
    ret.resize(3, bestV);

    cout << ans << '\n';
    each(v, ret) cout << v+1 << ' ';
    cout << '\n';
}