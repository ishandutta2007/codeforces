#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 2010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], dist[maxn];
bool vis[maxn];
vector<array<ll, 2>> adj[maxn];

void solve(vector<ll> v) {
    ll a, b, d;
    vector<ll> l, r;

    if (v.size() <= 1) return;
    a = v[0];
    array<ll, 2> o = {INF, -1};
    for (auto u : v) {
        if (a == u) continue;
        o = min(o, {mt[a][u], u});
    }
    d = o[0]; b = o[1];
    if (d <= 0) {
        cout << "NO" << nl; exit(0);
    }

    adj[a].pb({b, d}); adj[b].pb({a, d});
    // cout << "new edge " << a _ b _ d << nl;

    for (auto u : v) {
        if (mt[a][u] - mt[b][u] == d) l.pb(u);
        else if (mt[a][u] - mt[b][u] == -d) r.pb(u);
        else flag[0] = 0;
    }

    solve(l); solve(r);
}

void dfs(ll s) {
    ll u, w;
    for (auto o : adj[s]) {
        u = o[0]; w = o[1];
        if (vis[u]) continue;
        vis[u] = true; dist[u] = dist[s] + w;
        dfs(u);
    }
}

void init(ll s) {
    ll i;
    for (i = 1; i <= n; i++) {
        vis[i] = false; dist[i] = 0;
    }
    vis[s] = true; dist[s] = 0; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; flag[0] = 1;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> mt[i][j];
        }
    }

    vector<ll> v;
    for (i = 1; i <= n; i++) v.pb(i);
    solve(v);

    // cout << flag[0] << nl;

    for (i = 1; i <= n; i++) {
        init(i);
        // cout << "init " << i << nl;
        for (j = 1; j <= n; j++) {
            // cout << "dist " << i _ j _ dist[j] << nl;
            if (dist[j] != mt[i][j] || dist[j] != mt[j][i]) flag[0] = 0;
        }
    }

    if (flag[0] == 1) cout << "YES" << nl;
    else cout << "NO" << nl;

    return 0;
}