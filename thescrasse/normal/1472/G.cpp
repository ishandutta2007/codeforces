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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dist[maxn], mk[maxn], vl[maxn];
vector<array<ll, 2>> el, v;
vector<ll> adj[maxn];
queue<ll> q;
bool visited[maxn];

void bfs(ll ty, ll k) {
    ll s;
    while (!q.empty()) {
        s = q.front(); q.pop();
        visited[s] = true;
        if (ty == 2) vl[s] = min(vl[s], k);
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            if (ty == 2 || dist[s] + 1 < dist[u]) {
                dist[u] = dist[s] + 1; q.push(u);
            }
        }
    }
}

void init(ll s) {
    for (i = 1; i <= n; i++) {
        visited[i] = false; dist[i] = INF;
    }
    visited[s] = true; dist[s] = 0; q.push(s); bfs(1, 0);
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
        cin >> n >> m; el.clear(); v.clear();
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].pb(b); el.pb({a, b});
        }

        init(1);

        // for (i = 1; i <= n; i++) cout << dist[i] << nl;

        for (i = 1; i <= n; i++) mk[i] = INF;

        for (auto u : el) {
            a = u[0]; b = u[1];
            if (dist[a] >= dist[b]) mk[a] = min(mk[a], dist[b]);
        }

        for (i = 1; i <= n; i++) {
            if (mk[i] == INF) continue;
            v.pb({mk[i], i});
        }

        // for (auto u : v) cout << u[0] _ u[1] << nl;

        for (i = 1; i <= n; i++) {
            adj[i].clear(); vl[i] = dist[i]; visited[i] = false;
        }
        for (auto u : el) {
            a = u[0]; b = u[1];
            if (dist[a] >= dist[b]) continue;
            adj[b].pb(a);
        }

        sort(v.begin(), v.end());
        for (auto u : v) {
            a = u[1];
            if (visited[a]) continue;
            q.push(a); bfs(2, u[0]);
        }

        for (i = 1; i <= n; i++) cout << vl[i] << ' ';
        cout << nl;
    }

    return 0;
}