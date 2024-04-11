#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, da, db, u, v, dist[maxn], parent[maxn], s, x;
vector<ll> adj[maxn];
bool visited[maxn];

void dfs(ll s) {
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true; parent[u] = s;
        dist[u] = dist[s] + 1;
        dfs(u);
    }
}

void init(ll s) {
    for (i = 1; i <= n; i++) visited[i] = false;
    visited[s] = true; dist[s] = 0; parent[s] = -1;
    dfs(s);
}

ll fts() {
    ll m, k;
    m = -INF; k = -1;
    for (i = 1; i <= n; i++) {
        if (dist[i] > m) {
            m = dist[i]; k = i;
        }
    }

    return k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (i = 1; i <= n; i++) {
            adj[i].clear(); visited[i] = false;
        }
        for (i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }

        init(1);
        s = fts(); init(s);
        s = fts();
        // cout << dist[s] << nl;
        db = min(db, dist[s]);

        if (2 * da >= db) {
            cout << "Alice" << nl; continue;
        }

        if (dist[a] < dist[b]) swap(a, b);
        x = 0;
        while (dist[a] > dist[b]) {
            a = parent[a]; x++;
        }

        while (a != b) {
            a = parent[a]; b = parent[b]; x += 2;
        }

        if (da >= x) {
            cout << "Alice" << nl;
        } else {
            cout << "Bob" << nl;
        }
    }

    return 0;
}