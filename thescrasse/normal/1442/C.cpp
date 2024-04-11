#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010
#define gig 10000000

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, r, p2, ty, x, s, dist[maxn][2];
vector<ll> adj[maxn][2];
bool visited[maxn][2];
priority_queue<array<ll, 3>> pq;
array<ll, 3> o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a][0].pb(b); adj[b][1].pb(a);
    }

    res = INF; p2 = 1;
    for (i = 2; i <= n; i++) dist[i][0] = INF;

    for (r = 0; r <= 25; r++) {
        for (i = 1; i <= n; i++) {
            visited[i][0] = false; pq.push({-dist[i][0], 0, i});
        }

        while (!pq.empty()) {
            s = pq.top()[2]; pq.pop();
            visited[s][0] = true;
            for (auto u : adj[s][r % 2]) {
                // cout << "u = " << u << nl;
                if (visited[u][0]) continue;
                if (dist[s][0] + 1 < dist[u][0]) {
                    dist[u][0] = dist[s][0] + 1;
                    pq.push({-dist[u][0], 0, u});
                }
            }
        }

        res = min(res, dist[n][0] + p2 - 1); p2 *= 2;

        /* for (i = 1; i <= n; i++) {
            cout << dist[i][0] << ' ';
        }
        cout << nf; */
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j < 2; j++) {
            if (i + j == 1) dist[i][j] = 0;
            else dist[i][j] = INF;
            visited[i][j] = false;
        }
    }

    pq.push({0, 0, 1});
    while (!pq.empty()) {
        o = pq.top(); pq.pop();
        ty = o[1]; s = o[2];
        visited[s][ty] = true;
        for (auto u : adj[s][ty]) {
            if (visited[u][ty]) continue;
            if (dist[s][ty] + 1 < dist[u][ty]) {
                dist[u][ty] = dist[s][ty] + 1;
                pq.push({-dist[u][ty], ty, u});
            }
        }

        if (visited[s][ty ^ 1]) continue;
        if (dist[s][ty] + gig < dist[s][ty ^ 1]) {
            dist[s][ty ^ 1] = dist[s][ty] + gig;
            pq.push({-dist[s][ty ^ 1], ty ^ 1, s});
        }
    }

    if (dist[n][0] < dist[n][1]) ty = 0;
    else ty = 1;

    // cout << dist[n][ty] << nl;

    x = dist[n][ty] % gig;
    k = dist[n][ty] / gig;
    p2 = 1;
    for (i = 0; i < k; i++) p2 = (2 * p2) % mod;
    if (res == INF) {
        res = (x + p2 + mod - 1) % mod;
    }

    cout << res;

    return 0;
}