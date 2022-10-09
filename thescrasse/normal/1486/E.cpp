#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll w, s, fw, u, dist[maxn][55];
bool visited[maxn][55];
vector<array<ll, 2>> adj[maxn];
priority_queue<array<ll, 3>> pq;

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
        for (j = 0; j <= 50; j++) {
            dist[i][j] = INF;
        }
    }

    dist[1][0] = 0; pq.push({0, 1, 0});
    while (!pq.empty()) {
        array<ll, 3> o = pq.top(); pq.pop();
        s = o[1]; fw = o[2];
        // cout << s _ fw << nl;
        if (visited[s][fw]) continue;
        visited[s][fw] = true;
        for (auto e : adj[s]) {
            u = e[0]; w = e[1];
            if (fw != 0) {
                k = (fw + w) * (fw + w); m = 0;
            } else {
                k = 0; m = w;
            }
            if (dist[u][m] > dist[s][fw] + k) {
                dist[u][m] = dist[s][fw] + k;
                pq.push({-dist[u][m], u, m});
            }
        }
    }

    for (i = 1; i <= n; i++) {
        if (dist[i][0] == INF) cout << -1 << ' ';
        else cout << dist[i][0] << ' ';
    }
    cout << nl;

    return 0;
}