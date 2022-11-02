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

constexpr ll INF = 1e18;
using Pll = pair<ll, ll>;

vector<Vi> G;
vector<ll> vals;
vector<vector<ll>> ans;
vector<vector<Pll>> dp;
vector<Pll> tmp;

void dfs(int v, int p) {
    dp[v] = { {0, vals[v]} };

    each(e, G[v]) if (e != p) {
        dfs(e, v);

        tmp.assign(sz(dp[v]) + sz(dp[e]) - 1, mp(-INF, -INF));

        rep(m1, 0, sz(dp[v])) rep(m2, 0, sz(dp[e])) {
            ll a = dp[v][m1].x + dp[e][m2].x;
            ll b = dp[v][m1].y + dp[e][m2].y;
            tmp[m1+m2] = max(tmp[m1+m2], mp(a, b));
        }

        dp[v].swap(tmp);
    }

    dp[v].pb({-INF, -INF});
    ans[v].resize(sz(dp[v]));

    for (int i = sz(dp[v])-2; i >= 0; i--) {
        ll a = dp[v][i].x + (dp[v][i].y > 0);
        dp[v][i+1] = max(dp[v][i+1], mp(a, 0LL));
        ans[v][i+1] = a;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vals.resize(n);
    G.assign(n, {});

    rep(i, 0, n) {
        int b; cin >> b;
        vals[i] = -b;
    }

    rep(i, 0, n) {
        int w; cin >> w;
        vals[i] += w;
    }

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    dp.assign(n, {});
    ans.assign(n, {});
    dfs(0, -1);

    deb(vals, dp, ans);
    cout << ans[0][m] << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}