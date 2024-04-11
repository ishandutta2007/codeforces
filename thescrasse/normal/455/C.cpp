// 455C
// query con aggiunta di archi che minimizzano il diametro

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, q, res, check1, a, b, parent[300010], size[300010], dist[300010], diam[300010], mx, nd;
bool visited[300010];
vector<ll> adj[300010], curr;

ll find(ll s) {
    // cout << "find " << s << endl << flush;
    while (parent[s] != s) {
        s = parent[s];
    }
    return s;
}

void dfs(ll s) {
    // cout << "dfs " << s << endl << flush;
    curr.push_back(s);
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            dist[u] = dist[s] + 1;
            if (dist[u] > mx) {
                mx = dist[u];
                nd = u;
            }
            dfs(u);
        }
    }
}

void diamupd(ll s) {
    // cout << "diamupd " << s << endl << flush;
    curr.clear();
    visited[s] = true; dist[s] = 0;
    mx = 0; nd = s;
    dfs(s);
    for (auto u : curr) {
        visited[u] = false;
    }

    curr.clear();
    visited[nd] = true; dist[nd] = 0;
    dfs(nd);
    for (auto u : curr) {
        diam[u] = mx;
    }
}

void unite(ll a, ll b) {
    // cout << "unite " << a << ' ' << b << endl << flush;
    a = find(a); b = find(b);
    if (a == b) {
        return;
    }
    if (size[a] < size[b]) {
        swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
    diam[a] = max({diam[a], diam[b], (diam[a] + 1) / 2 + (diam[b] + 1) / 2 + 1});
    // cout << diam[a] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m >> q;
    for (i = 1; i <= n; i++) {
        size[i] = 1;
        parent[i] = i;
        dist[i] = 0;
        diam[i] = 0;
    }
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        unite(a, b);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            diamupd(i);
        }
    }

    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a;
            cout << diam[find(a)] << endl;
        } else {
            cin >> a >> b;
            unite(a, b);
        }
    }

    return 0;
}