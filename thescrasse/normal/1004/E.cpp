// 1004E
// Sonya and Ice Cream

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, u, w, x, y, ps;
ll parent[maxn], dist[maxn];
vector<array<ll, 2>> adj[maxn];
bool visited[maxn], dm[maxn];
vector<ll> v;

void dfs(ll s) {
    for (auto [u, w] : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        parent[u] = s; dist[u] = min(dist[u], dist[s] + w);
        dfs(u);
    }
}

void init(ll s) {
    for (ll i = 1; i <= n; i++) {
        visited[i] = false;
        if (dm[i]) dist[i] = 0;
        else dist[i] = INF;
    }
    visited[s] = true; dist[s] = 0; dfs(s);
}

ll fts() {
    ll m, x;
    m = -1;
    for (ll i = 1; i <= n; i++) {
        if (dist[i] > m) {
            m = dist[i]; x = i;
        }
    }
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w}); adj[b].pb({a, w});
    }

    init(1); x = fts();
    init(x); y = fts();

    while (true) {
        v.pb(dist[y]); dm[y] = true; if (x == y) break;
        y = parent[y];
    }

    reverse(v.begin(), v.end());
    m = v.size(); k = min(k - 1, m - 1); res = INF;
    for (i = 0; i < m - k; i++) res = min(res, max(v[i], v[m - 1] - v[i + k]));

    init(x); y = fts(); res = max(res, dist[y]);

    /* for (i = 1; i <= n; i++) {
        cout << i << ' ' << dist[i] << nl;
    } */

    cout << res;

    return 0;
}