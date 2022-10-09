#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w, dist[maxn][maxn], c, d, s, u;
vector<array<ll, 2>> adj[maxn], el, cl;
bool visited[maxn];
priority_queue<array<ll, 2>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> k;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w}); adj[b].pb({a, w});
        el.pb({a, b});
    }

    for (i = 1; i <= n; i++) {
        // cout << nl;
        for (j = 1; j <= n; j++) {
            visited[j] = false; dist[i][j] = INF;
        }
        dist[i][i] = 0;
        pq.push({0, i});
        while (!pq.empty()) {
            s = pq.top()[1]; pq.pop();
            visited[s] = true;
            // cout << s << nl;
            for (auto o : adj[s]) {
                u = o[0]; w = o[1];
                if (visited[u]) continue;
                if (dist[i][s] + w < dist[i][u]) {
                    dist[i][u] = min(dist[i][u], dist[i][s] + w);
                    pq.push({-dist[i][u], u});
                }                
            }
        }
    }

    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << nl;
    } */

    for (i = 0; i < k; i++) {
        cin >> a >> b; cl.pb({a, b});
    }

    res = INF;
    for (auto u : el) {
        m = 0; c = u[0]; d = u[1];
        for (auto o : cl) {
            a = o[0]; b = o[1];
            m += min({dist[a][b], dist[a][c] + dist[d][b], dist[a][d] + dist[c][b]});
        }
        res = min(res, m);
    }

    cout << res << nl;

    return 0;
}