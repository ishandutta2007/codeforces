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

int n;
vector<Vi> G;
Vi col, dp;

void dfs(int v, int p) {
    dp[v] = col[v];
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        dp[v] += max(dp[e], 0);
    }
}

void dfs2(int v, int p) {
    each(e, G[v]) if (e != p) {
        dp[e] += max(dp[v] - max(dp[e], 0), 0);
        dfs2(e, v);
    }
}

void run() {
    cin >> n;
    G.resize(n);
    col.resize(n);

    each(c, col) {
        cin >> c;
        c = (c ? 1 : -1);
    }

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    dp.resize(n);
    dfs(0, -1);
    dfs2(0, -1);
    each(k, dp) cout << k << ' ';
    cout << '\n';
}