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

int n, a, b, da, db;
vector<Vi> G;
Vi dist;

void dfs(int v, int p, int d) {
    dist[v] = d;
    each(e, G[v]) if (e != p) dfs(e, v, d+1);
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    a--; b--;
    G.assign(n, {});

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    dist.assign(n, 1e9);
    dfs(a, -1, 0);

    bool ok = (db > da*2 && dist[b] > da);

    if (ok) {
        Pii best = {-1, -1};
        rep(i, 0, n) best = max(best, mp(dist[i], i));
        dfs(best.y, -1, 0);
        rep(i, 0, n) best = max(best, mp(dist[i], i));
        ok = (best.x > da*2);
    }

    cout << (ok ? "Bob\n" : "Alice\n");
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}