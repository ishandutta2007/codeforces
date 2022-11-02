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

int n, k;
vector<Vi> G;
Vi par, depth, under;

void dfs(int v, int p, int d) {
    par[v] = p;
    depth[v] = d;
    under[v] = 1;
    each(e, G[v]) {
        if (e != p) {
            dfs(e, v, d+1);
            under[v] += under[e];
        }
    }
}

void run() {
    cin >> n >> k;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    par.resize(n);
    depth.resize(n);
    under.resize(n);
    dfs(0, -1, 0);

    Vi elems;
    rep(i, 0, n) {
        elems.pb(depth[i] - under[i] + 1);
    }

    sort(all(elems));
    ll ans = 0;

    rep(i, 0, k) {
        ans += elems.back();
        elems.pop_back();
    }

    cout << ans << endl;
}