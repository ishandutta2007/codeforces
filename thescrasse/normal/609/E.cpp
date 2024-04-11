// 609E
// Minimum spanning tree for each edge

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define size treapdidsu

ll i, i1, j, k, k1, t, n, m, mn, res[200010], flag, a, b, w, link[200010], size[200010], dist[200010], parent[200010][25], rm[200010][25];
vector<array<ll, 4>> el;
vector<pair<ll, ll>> adj[200010];
bool visited[200010];

ll find(ll x) {
    while (link[x] != x) x = link[x];
    return x;
}

bool same(ll a, ll b) {
    return find(a) == find(b);
}

void unite(ll a, ll b) {
    a = find(a); b = find(b);
    if (size[a] > size[b]) swap(a, b);
    link[a] = b; size[b] += size[a];
    // cout << a << ' ' << b << ' ' << link[a] << endl;
}

void dfs(ll s) {
    // cout << s << endl;
    ll i, j, k, u;
    for (auto o : adj[s]) {
        u = o.first;
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1;
            parent[u][0] = s; rm[u][0] = o.second;
            k = 1;
            for (i = 2; i <= dist[u]; i *= 2) {
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
                rm[u][k] = max(rm[u][k - 1], rm[parent[u][k - 1]][k - 1]);
                k++;
                // cout << u << ' ' << k << ' ' << parent[u][k] << ' ' << rm[u][k] << endl;
            }
            dfs(u);
        }
    }
}

ll lca(ll a, ll b) {
    ll i, j, k, res;
    res = 0;
    if (dist[a] < dist[b]) swap(a, b);
    k = dist[a] - dist[b];
    for (i = 0; i < 25; i++) {
        if (((k >> i) & 1) == 1) {
            res = max(res, rm[a][i]);
            a = parent[a][i];
        }
    }
    
    if (a == b) return res;

    for (i = 24; i >= 0; i--) {
        if (dist[a] < (1 << i)) continue;
        if (parent[a][i] == parent[b][i]) continue;
        res = max({res, rm[a][i], rm[b][i]});
        a = parent[a][i]; b = parent[b][i];
    }
    
    res = max({res, rm[a][0], rm[b][0]});

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> w;
        el.push_back({w, a, b, i});
    }

    for (i = 1; i <= n; i++) {
        size[i] = 1; link[i] = i;
    }

    sort(el.begin(), el.end());
    mn = 0;
    for (auto u : el) {
        w = u[0]; a = u[1]; b = u[2];
        if (!same(a, b)) {
            unite(a, b); mn += w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }

    /* cout << mn << endl;

    for (i = 0; i < n; i++) {
        cout << link[i] << ' ';
    }
    cout << endl; */

    visited[1] = true; dist[1] = 0; dfs(1);

    for (auto u : el) {
        w = u[0]; a = u[1]; b = u[2]; i = u[3];
        res[i] = mn + w - lca(a, b);
    }

    for (i = 0; i < m; i++) {
        cout << res[i] << endl;
    }

    return 0;
}