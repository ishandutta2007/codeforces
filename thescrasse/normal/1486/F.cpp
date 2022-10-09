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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d;
ll dist[maxn], parent[maxn][25], clca[maxn], cpth[maxn];
bool visited[maxn];
vector<ll> adj[maxn];
vector<array<ll, 2>> v;
map<array<ll, 2>, ll> mp;

// old code, don't read

void dfs(ll s) {
    // cout << s << endl;
    ll i, j, k, u;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1; parent[u][0] = s;
            k = 1;
            for (i = 2; i <= dist[u]; i *= 2) {
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
                // rm[u][k] = max(rm[u][k - 1], rm[parent[u][k - 1]][k - 1]);
                k++;
                // cout << u << ' ' << k << ' ' << parent[u][k] << ' ' << rm[u][k] << endl;
            }
            dfs(u);
        }
    }
}

void dfs_ps(ll s) {
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true; dfs_ps(u);
        cpth[s] += cpth[u];
    }
}

ll kth(ll a, ll k) {
    for (i = 0; i < 25; i++) {
        if (((k >> i) & 1) == 1) a = parent[a][i];
    }
    return a;
}

ll lca(ll a, ll b) {
    ll i, j, k, res;
    res = 0;
    if (dist[a] < dist[b]) swap(a, b);
    k = dist[a] - dist[b];
    a = kth(a, k);

    if (a == b) return a;

    for (i = 24; i >= 0; i--) {
        if (dist[a] < (1 << i)) continue;
        if (parent[a][i] == parent[b][i]) continue;
        // res = max({res, rm[a][i], rm[b][i]});
        a = parent[a][i]; b = parent[b][i];
    }

    // res = max({res, rm[a][0], rm[b][0]});

    return parent[a][0];
}

ll bnm(ll x) {
    return (x * (x - 1)) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b; v.pb({a, b});
    }

    visited[1] = true; dist[1] = 0; dfs(1);
    for (auto u : v) {
        a = u[0]; b = u[1]; k = lca(a, b);
        // cout << a _ b _ k << nl;
        clca[k]++; cpth[a]++; cpth[b]++; cpth[k] -= 2;
    }

    /* for (i = 1; i <= n; i++) {
        cout << i _ clca[i] _ cpth[i] << nl;
    } */

    for (i = 1; i <= n; i++) visited[i] = false;
    visited[1] = true; dfs_ps(1);

    /* for (i = 1; i <= n; i++) {
        cout << i _ clca[i] _ cpth[i] << nl;
    } */

    /* for (i = 1; i <= n; i++) {
        res += clca[i] * cpth[i] + bnm(clca[i]);
    }

    cout << res << nl; */

    for (auto u : v) {
        a = u[0]; b = u[1]; k = lca(a, b);
        if (a != k) {
            c = kth(a, dist[a] - dist[k] - 1); mp[{c, k}]++;
        }
        if (b != k) {
            d = kth(b, dist[b] - dist[k] - 1); mp[{d, k}]++;
        }
        if (c > d) swap(c, d);
        if (a != k && b != k) mp[{c, d}]++;
    }

    for (auto u : v) {
        a = u[0]; b = u[1]; k = lca(a, b); m = cpth[k];
        if (a != k) {
            c = kth(a, dist[a] - dist[k] - 1); m += mp[{c, k}] - cpth[c];
        }
        if (b != k) {
            d = kth(b, dist[b] - dist[k] - 1); m += mp[{d, k}] - cpth[d];
        }

        res += m;
    }

    // cout << res << nl;

    for (i = 1; i <= n; i++) res += bnm(clca[i]);

    for (auto u : mp) {
        // cout << u.first[0] _ u.first[1] _ u.second << nl;
        res += bnm(u.second) * (1 - 2 * (dist[u.first[0]] != dist[u.first[1]]));
    }

    cout << res << nl;

    return 0;
}