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
ll w, dist[maxn][2][2], x, y, s, u;
vector<array<ll, 2>> adj[maxn];
bool visited[maxn][2][2];
priority_queue<array<ll, 4>> pq;
array<ll, 4> o;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w}); adj[b].pb({a, w});
    }

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 1; j++) {
            for (k = 0; k <= 1; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    dist[1][0][0] = 0; pq.push({0, 1, 0, 0});

    while (!pq.empty()) {
        o = pq.top(); pq.pop();
        s = o[1]; x = o[2]; y = o[3];
        // cout << s _ x _ y << nl
        if (visited[s][x][y]) continue;
        visited[s][x][y] = true;
        for (auto e : adj[s]) {
            u = e[0]; w = e[1];
            for (i = x; i <= 1; i++) {
                for (j = y; j <= 1; j++) {
                    k = w * (1 - (i - j - x + y));
                    if (dist[u][i][j] > dist[s][x][y] + k) {
                        dist[u][i][j] = dist[s][x][y] + k;
                        pq.push({-dist[u][i][j], u, i, j});
                    }
                }
            }
        }
    }

    for (i = 2; i <= n; i++) {
        cout << dist[i][1][1] << ' ';
    }
    cout << nl;

    return 0;
}