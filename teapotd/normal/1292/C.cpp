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

vector<Vi> G;
Vi par, pre, post, sub;
int n, cnt;
ll buf[3005][3005];
int before[3005][3005];

void dfs(int v, int p) {
    sub[v] = 1;
    par[v] = p;
    pre[v] = ++cnt;
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        sub[v] += sub[e];
    }
    post[v] = ++cnt;
}

void dfs2(int v, int p, int root) {
    before[root][v] = p;
    each(e, G[v]) if (e != p) dfs2(e, v, root);
}

bool anc(int p, int v) {
    return pre[p] <= pre[v] && post[v] <= post[p];
}

ll dp(int u, int v) {
    ll& val = buf[u][v];
    if (val != -1) return val;

    if (u == v) {
        return val = 0;
    }

    if (anc(v, u)) {
        return val = dp(v, u);
    }

    if (anc(u, v)) {
        int prv = before[v][u];
        val = max(dp(u, par[v]), dp(prv, v)) + ll(n-sub[prv])*sub[v];
    } else {
        val = max(dp(u, par[v]), dp(par[u], v)) + ll(sub[u])*sub[v];
    }

    return val;
}

void run() {
    cin >> n;
    G.resize(n);
    pre.resize(n);
    post.resize(n);
    par.resize(n);
    sub.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    rep(i, 0, n) rep(j, 0, n) buf[i][j] = -1;
    dfs(0, -1);
    rep(i, 0, n) dfs2(i, -1, i);

    ll ans = 0;
    rep(i, 0, n) rep(j, 0, n) ans = max(ans, dp(i, j));
    cout << ans << '\n';
}