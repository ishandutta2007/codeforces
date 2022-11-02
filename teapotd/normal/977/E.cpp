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

int n, m;
vector<Vi> G;
vector<bool> seen;
bool good;

void dfs(int v) {
    if (seen[v]) return;
    seen[v] = 1;
    if (sz(G[v]) != 2) good = 0;
    each(e, G[v]) dfs(e);
}

void run() {
    cin >> n >> m;
    G.resize(n);

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    seen.resize(n);
    int ans = 0;

    rep(i, 0, n) {
        if (!seen[i]) {
            good = 1;
            dfs(i);
            ans += good;
        }
    }

    cout << ans << endl;
}