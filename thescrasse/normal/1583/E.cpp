#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll pr[maxn], dist[maxn], q, f[maxn], x[maxn], y[maxn];
bool vis[maxn];
vector<ll> adj[maxn], v;

void dfs(ll s) {
    vis[s] = true;
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        pr[u] = s; dist[u] = dist[s] + 1; dfs(u);
    }
}

ll lca(ll a, ll b) {
    if (dist[a] < dist[b]) swap(a, b);
    while (dist[a] != dist[b]) a = pr[a];
    while (a != b) a = pr[a], b = pr[b];
    return a;
}

void solve(ll ty, ll a, ll b) {
    vector<ll> w;
    while (a != b) {
        w.pb(a); a = pr[a];
    }
    if (ty == 0) w.pb(a);
    else reverse(w.begin(), w.end());
    for (auto u : w) v.pb(u);
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
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    dfs(1);

    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];
        f[x[i]] ^= 1; f[y[i]] ^= 1;
    }

    flag[0] = 1;
    for (i = 1; i <= n; i++) {
        if (f[i] == 1) flag[0] = 0;
    }

    if (flag[0] == 1) {
        cout << "YES" << nl;
        for (i = 1; i <= q; i++) {
            a = lca(x[i], y[i]);
            v.clear();
            solve(0, x[i], a); solve(1, y[i], a);
            cout << v.size() << nl;
            for (auto u : v) cout << u << ' ';
            cout << nl;
        }
    } else {
        cout << "NO" << nl; res = 0;
        for (i = 1; i <= n; i++) res += (f[i] == 1);
        res /= 2; cout << res << nl;
    }

    return 0;
}