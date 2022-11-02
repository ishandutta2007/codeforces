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
ll ansMin, ansMax;
vector<vector<Pii>> G;

int dfs(int v, int p) {
    int ret = 1;

    each(e, G[v]) if (e.x != p) {
        int s = dfs(e.x, v);
        ret += s;
        if (s % 2) ansMin += e.y;
        ansMax += ll(e.y) * min(s, n-s);
    }

    return ret;
}

void solve() {
    cin >> n;
    n *= 2;
    G.assign(n, {});

    rep(i, 1, n) {
        int u, v, w; cin >> u >> v >> w;
        G[u-1].pb({v-1, w});
        G[v-1].pb({u-1, w});
    }

    ansMin = ansMax = 0;
    dfs(0, -1);
    cout << ansMin << ' ' << ansMax << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}