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
Vi par, pre, post, dep;
int cnt;

bool anc(int u, int v) {
    return pre[u] <= pre[v] && post[u] >= post[v];
}

void dfs(int v, int p, int d) {
    par[v] = p;
    dep[v] = d;
    pre[v] = ++cnt;
    each(e, G[v]) if (e != p) dfs(e, v, d+1);
    post[v] = ++cnt;
}

void run() {
    int n, m; cin >> n >> m;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    par.resize(n);
    dep.resize(n);
    pre.resize(n);
    post.resize(n);
    dfs(0, 0, 0);

    while (m--) {
        int k; cin >> k;
        Vi elems(k);
        each(e, elems) cin >> e, e--;
        sort(all(elems), [](int l, int r) { return dep[l] < dep[r]; });

        bool ok = 1;

        each(e, elems) {
            if (!anc(par[e], elems.back())) {
                ok = 0;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}