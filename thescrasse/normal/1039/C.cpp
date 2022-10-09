#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 500010
#define nv 500000004

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll c[maxn], st, x;
vector<array<ll, 2>> el;
map<ll, ll> wy;
map<ll, bool> vis[maxn];
map<ll, vector<ll>> adj[maxn];

void dfs(ll s, ll x, ll f) {
    if (vis[s][x]) return;
    vis[s][x] = true;
    if (!wy.count(x)) wy[x] = st;
    else if (f == 1) wy[x] = (nv * wy[x]) % mod;
    for (auto u : adj[s][x]) dfs(u, x, 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k;
    for (i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a][c[a] ^ c[b]].pb(b);
        adj[b][c[a] ^ c[b]].pb(a);
        el.pb({a, b});
    }

    st = 1;
    for (i = 1; i <= n; i++) st = (2 * st) % mod;

    for (auto [a, b] : el) {
        x = c[a] ^ c[b];
        if (x >= ((ll)1 << k)) continue;
        if (!vis[a][x]) dfs(a, x, 0);
        if (!vis[b][x]) dfs(b, x, 0);
    }

    res = (((ll)1 << k) - (ll)wy.size()) % mod;
    res = (res * st) % mod;
    for (auto u : wy) res = (res + u.second) % mod;

    // for (auto [a, b] : wy) cout << a _ b << nl;

    cout << res << nl;

    return 0;
}