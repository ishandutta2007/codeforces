#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, vis[maxn];
vector<ll> adj[maxn], adju[maxn], v;

void dfs1(ll s) {
    if (vis[s] == 1) return;
    vis[s] = 1; v.pb(s);
    for (auto u : adju[s]) dfs1(u);
}

void dfs2(ll s) {
    // cout << "dfs " << s _ vis[s] << nl;
    if (vis[s] == 2) return;
    if (vis[s] == 1) {
        m = 1; return;
    }
    vis[s] = 1;
    for (auto u : adj[s]) dfs2(u);
    vis[s] = 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b; adj[a].pb(b);
        adju[a].pb(b); adju[b].pb(a);
    }

    for (i = 1; i <= n; i++) {
        if (vis[i] != 0) continue;
        v.clear(); m = 0; dfs1(i);
        for (auto u : v) vis[u] = 0;
        for (auto u : v) dfs2(u);
        k = v.size();
        // cout << i _ k _ m << nl;
        res += k + m - 1;
    }

    cout << res << nl;

    return 0;
}