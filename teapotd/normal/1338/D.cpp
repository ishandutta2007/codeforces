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

int n, ans;
vector<Vi> G;
Vi f, g;

void dfs(int v, int p) {
    int nch = sz(G[v]) - (p != -1);
    int sg = -1, sf = -1;
    g[v] = 0;
    f[v] = 1;

    each(e, G[v]) if (e != p) {
        dfs(e, v);
        int altG = max(f[e], g[e]) + nch - 1;
        int altF = 1 + g[e];

        if (altG >= g[v]) {
            sg = g[v];
            g[v] = altG;
        } else {
            sg = max(sg, altG);
        }

        if (altF >= f[v]) {
            sf = f[v];
            f[v] = altF;
        } else {
            sf = max(sf, altF);
        }
    }

    ans = max(ans, max(f[v], g[v]));
    if (sf != -1) ans = max(ans, f[v]+sf-1);
    if (sg != -1) ans = max(ans, g[v]+sg-nch + (p != -1));
}

void run() {
    cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    f.resize(n);
    g.resize(n);
    dfs(0, -1);
    cout << ans << '\n';
}