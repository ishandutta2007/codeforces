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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sb[maxn], dist[maxn];
ll cy[2], parent[maxn];
vector<ll> adj[maxn];
bool visited[maxn];

void dfs(ll s) {
    sb[s] = 1;
    for (auto u : adj[s]) {
        if (visited[u]) {
            if (dist[s] <= dist[u]) continue;
            if (dist[s] - dist[u] == 1) continue;
            cy[0] = s; cy[1] = u; continue;
        }
        visited[u] = true; dist[u] = dist[s] + 1;
        parent[u] = s;
        dfs(u);
        sb[s] += sb[u];
    }
}

void init(ll s) {
    for (i = 1; i <= n; i++) visited[i] = false;
    visited[s] = true; dfs(s);
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
        cin >> n;
        for (i = 1; i <= n; i++) adj[i].clear();
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
        }

        init(1);

        res = n * (n - 1);
        a = cy[0]; b = cy[1];
        /* res += (sb[a] - 1) * (n - sb[a] + 1);
        res += sb[b] * (n - sb[b]);
        res -= (sb[a] - 1) * (n - sb[b]);
        res += ((sb[b] - sb[a] + 1) * (sb[b] - sb[a])) / 2; */

        res -= (sb[a] * (sb[a] - 1)) / 2;
        while (true) {
            if (parent[a] == b) {
                res -= ((n - sb[a]) * (n - sb[a] - 1)) / 2; break;
            }
            k = sb[parent[a]] - sb[a];
            res -= (k * (k - 1)) / 2;
            a = parent[a];
        }

        // cout << a << ' ' << b << ' ' << sb[a] << ' ' << sb[b] << nl;

        cout << res << nl;
    }

    return 0;
}