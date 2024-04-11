#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll c[maxn], w, dist[maxn];
bool vis[maxn];
vector<array<ll, 2>> adj[maxn], gr[maxn];

void dfs(ll s) {
    vis[s] = true;
    for (auto [u, w] : adj[s]) {
        if (vis[u]) continue;
        if (w != -1) {
            w = __builtin_popcountll(w) % 2;
            gr[s].pb({u, w}); gr[u].pb({s, w});
        }
        dist[u] = dist[s] + 1;
        dfs(u);
    }
}

void bip(ll s) {
    vis[s] = true;
    for (auto [u, w] : gr[s]) {
        if (vis[u] == true && c[u] != (c[s] ^ w)) {
            flag[0] = 0; break;
        }
        if (vis[u]) continue;
        c[u] = c[s] ^ w; bip(u);
    }
}

void fns(ll s) {
    vis[s] = true;
    for (auto &u : adj[s]) {
        if (vis[u[0]]) continue;
        if (u[1] == -1) u[1] = c[u[0]] ^ c[s];
        fns(u[0]);
    }
}

void rst() {
    ll i;
    flag[0] = 1;
    for (i = 1; i <= n; i++) {
        adj[i].clear(); gr[i].clear();
        vis[i] = false;
    }
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
        cin >> n >> m; rst();
        for (i = 1; i <= n - 1; i++) {
            cin >> a >> b >> w;
            adj[a].pb({b, w}); adj[b].pb({a, w});
        }

        for (i = 1; i <= m; i++) {
            cin >> a >> b >> w;
            gr[a].pb({b, w}); gr[b].pb({a, w});
        }

        dfs(1);

        for (i = 1; i <= n; i++) vis[i] = false;
        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            bip(i);
        }

        if (flag[0] == 0) {
            cout << "NO" << nl; continue;
        }

        for (i = 1; i <= n; i++) vis[i] = false;
        fns(1);

        cout << "YES" << nl;
        for (i = 1; i <= n; i++) {
            for (auto [u, w] : adj[i]) {
                if (dist[u] < dist[i]) continue;
                cout << i _ u _ w << nl;
            }
        }
    }

    return 0;
}