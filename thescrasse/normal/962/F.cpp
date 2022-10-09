// 962F
// Simple Cycles Edges

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, be[maxn], dp[maxn], dist[maxn], s;
bool visited[maxn];
array<ll, 2> parent[maxn];
vector<array<ll, 2>> adj[maxn];
vector<array<ll, 3>> bel;
vector<ll> r, vcc;

void dfs(ll ty, ll s) {
    if (ty == 1) {
        for (auto o : adj[s]) {
            ll u = o[0]; ll i = o[1];
            // cout << s << ' ' << u << ' ' << parent[s][0] << nl;
            if (parent[s][0] == u) continue;
            if (visited[u] && dist[s] > dist[u]) {
                be[s]++; be[u]--;
                bel.pb({s, u, i});
            }
            if (visited[u]) continue;
            visited[u] = true; parent[u] = {s, i};
            vcc.pb(u);
            dist[u] = dist[s] + 1; dfs(ty, u);
        }
    } else if (ty == 2) {
        for (auto o : adj[s]) {
            ll u = o[0];
            if (visited[u]) continue;
            visited[u] = true;
            dfs(ty, u);
            be[s] += be[u];
        }
    } else if (ty == 3) {
        for (auto o : adj[s]) {
            ll u = o[0];
            if (visited[u]) continue;
            visited[u] = true;
            if (be[u] == 1) dp[u] = dp[s];
            else dp[u] = dist[u];
            dfs(ty, u);
        }
    }
}

void init(ll ty, ll s) {
    ll i;
    for (auto u : vcc) visited[u] = false;
    visited[s] = true; dfs(ty, s);
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
        adj[a].pb({b, i}); adj[b].pb({a, i});
    }

    for (i = 1; i <= n; i++) {
        if (visited[i]) continue;
        vcc.clear();
        for (j = 1; j <= 3; j++) init(j, i);
    }

    for (auto u : bel) {
        if (dp[u[0]] <= dist[u[1]]) {
            r.pb(u[2]);
            s = u[0];
            while (s != u[1]) {
                // cout << s << nf;
                r.pb(parent[s][1]); s = parent[s][0];
            }
        }
    }

    sort(r.begin(), r.end());

    cout << r.size() << nl;
    for (auto u : r) cout << u << ' ';

    return 0;
}