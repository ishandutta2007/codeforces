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

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<Vi> G;
vector<char> state;
Vi ans;

vector<multiset<int>> up;
Vi pre, cand;
vector<bool> nice;
int cnt;

bool dfs(int v) {
    if (state[v]) return state[v] == 1;
    state[v] = 1;
    each(e, G[v]) if (!dfs(e)) return 0;
    state[v] = 2;
    return 1;
}

void go(int v) {
    state[v] = 1;
    pre[v] = ++cnt;

    each(e, G[v]) {
        if (state[e]) {
            up[v].insert(e);
        } else {
            go(e);
            if (sz(up[e]) > sz(up[v])) up[e].swap(up[v]);
            each(x, up[e]) up[v].insert(x);
            up[e].clear();
        }
    }
    
    up[v].erase(v);

    if (sz(up[v]) == 1) {
        cand[v] = *up[v].begin();
    }
}

void propag(int v) {
    if (state[v]) return;
    state[v] = 1;
    if (cand[v] != -1) {
        nice[v] = nice[cand[v]];
    }
    each(e, G[v]) propag(e);
}

bool check() {
    int root = int(rnd() % n);
    state.assign(n, 0);
    if (!dfs(root)) return 0;

    state.assign(n, 0);
    pre.assign(n, -1);
    cand.assign(n, -1);
    up.assign(n, {});
    cnt = 0;
    go(root);

    state.assign(n, 0);
    nice.assign(n, 0);
    nice[root] = 1;
    propag(root);

    deb(root);
    ans.clear();
    rep(i, 0, n) if (nice[i]) ans.pb(i);
    return 1;
}

void solve() {
    cin >> n >> m;
    G.assign(n, {});
    ans.clear();

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
    }

    rep(t, 0, 200) {
        if (check()) break;
        ans.clear();
    }

    if (ans.empty() || sz(ans)*5 < n) {
        cout << "-1\n";
    } else {
        sort(all(ans));
        each(a, ans) cout << a+1 << ' ';
        cout << '\n';
    }

    deb(0);
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}