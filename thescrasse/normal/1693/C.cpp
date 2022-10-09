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
ll dg[maxn], dist[maxn], w;
vector<ll> adj[maxn];
priority_queue<array<ll, 2>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b; adj[b].pb(a); dg[a]++;
    }

    for (i = 1; i <= n; i++) dist[i] = INF;
    dist[n] = 0; pq.push({0, n});

    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop(); d = -d;
        // cout << "s, d =" _ s _ d << nl;
        if (dist[s] != d) continue;
        for (auto u : adj[s]) {
            w = dist[s] + dg[u]; dg[u]--;
            // cout << "upd" _ u _ dg[u] _ w << nl;
            if (dist[u] > w) {
                dist[u] = w; pq.push({-w, u});
            }
        }
    }

    cout << dist[1] << nl;

    return 0;
}