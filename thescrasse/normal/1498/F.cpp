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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c[maxn];
ll xr[maxn][50], dist[maxn], x, rs[maxn];
vector<ll> adj[maxn];
bool vis[maxn];

void dfs(ll s) {
    // cout << "dfs " << s << nl;
    ll i;
    xr[s][0] ^= c[s];
    for (auto u : adj[s]) {
        // cout << "u = " << u << nl;
        if (vis[u]) continue;
        vis[u] = true; dist[u] = dist[s] + 1;
        dfs(u);
        for (i = 0; i < 2 * k; i++) xr[s][(i + 1) % (2 * k)] ^= xr[u][i];
    }
}

void rrt(ll s) {
    ll i, x;
    for (auto u : adj[s]) {
        // cout << "u = " << u << nl;
        if (vis[u]) continue;
        vis[u] = true;
        for (i = 0; i < 2 * k; i++) xr[s][(i + 1) % (2 * k)] ^= xr[u][i];
        for (i = 0; i < 2 * k; i++) xr[u][(i + 1) % (2 * k)] ^= xr[s][i];
        rrt(u);
        for (i = 0; i < 2 * k; i++) xr[u][(i + 1) % (2 * k)] ^= xr[s][i];
        for (i = 0; i < 2 * k; i++) xr[s][(i + 1) % (2 * k)] ^= xr[u][i];
    }

    x = 0;
    for (i = k; i < 2 * k; i++) x ^= xr[s][i];
    if (x == 0) rs[s] = 0;
    else rs[s] = 1;
}

void init(ll s, ll ty) {
    for (i = 1; i <= n; i++) vis[i] = false;
    vis[s] = true;
    if (ty == 1) dfs(s);
    else rrt(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    for (i = 1; i <= n; i++) {
        cin >> c[i];
    }

    init(1, 1);
    init(1, 2);

    /* for (i = 1; i <= n; i++) {
        for (j = 0; j < 2 * k; j++) {
            cout << i _ j _ xr[i][j] << nl;
        }
        cout << nl;
    }
    cout << nl; */

    for (i = 1; i <= n; i++) cout << rs[i] << ' ';
    cout << nl;

    return 0;
}