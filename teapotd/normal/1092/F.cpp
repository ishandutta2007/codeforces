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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

vector<Vi> G;
vector<ll> w, sum, ans;

void dfs(int v, int p) {
    sum[v] = w[v];
    ans[v] = 0;
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        sum[v] += sum[e];
        ans[v] += ans[e] + sum[e];
    }
}

void dfs2(int v, int p) {
    each(e, G[v]) if (e != p) {
        ans[e] += ans[v] - (ans[e] + sum[e]) + sum[0] - sum[e];
        dfs2(e, v);
    }
}

void run() {
    int n; cin >> n;
    G.resize(n);
    w.resize(n);
    each(e, w) cin >> e;
    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    sum.resize(n);
    ans.resize(n);
    dfs(0, -1);
    dfs2(0, -1);
    cout << *max_element(all(ans)) << '\n';
}