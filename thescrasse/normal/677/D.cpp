// 677D
// Vanya and Treasure

#pragma GCC optimize("O3")
#pragma GCC option("arch=native")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF 1e9
#define mod 998244353
#define maxn 310

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], f[90010], dist[maxn][maxn], p;
vector<array<int, 2>> adj[90010];
priority_queue<array<int, 3>> q;
bool visited[maxn][maxn];

int d1[4] = {1, 0, -1, 0};
int d2[4] = {0, 1, 0, -1};

bool oob(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return true;
    return false;
}

void dij(int st) {
    int i, j, x, y, m1, m2;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (mt[i][j] != st) {
                visited[i][j] = false; dist[i][j] = INF;
            } else {
                q.push({-dist[i][j], i, j});
            }
        }
    }

    while (!q.empty()) {
        x = q.top()[1]; y = q.top()[2]; q.pop();
        // cout << x << ' ' << y << nl;
        for (i = 0; i < 4; i++) {
            m1 = x + d1[i]; m2 = y + d2[i];
            if (oob(m1, m2)) continue;
            if (visited[m1][m2]) continue;
            visited[m1][m2] = true;
            dist[m1][m2] = min(dist[m1][m2], dist[x][y] + 1);
            q.push({-dist[m1][m2], m1, m2});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> p;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mt[i][j]; f[mt[i][j]]++;
            adj[mt[i][j]].pb({i, j}); dist[i][j] = INF;
        }
    }
    adj[0].pb({0, 0}); dist[0][0] = 0;

    for (i = 1; i <= p; i++) {
        k = INF;
        if (f[i] * f[i - 1] <= 9 * n * m) {
            for (auto v : adj[i]) {
                if (v[0] + v[1] != 0 || i != 1) dist[v[0]][v[1]] = INF;
                for (auto u : adj[i - 1]) {
                    dist[v[0]][v[1]] = min(dist[v[0]][v[1]], dist[u[0]][u[1]] + abs(v[0] - u[0]) + abs(v[1] - u[1]));
                }
            }
        } else {
            dij(i - 1);
        }

        /* for (i1 = 0; i1 < n; i1++) {
            for (j = 0; j < m; j++) {
                cout << dist[i1][j] << ' ';
            }
            cout << nl;
        } */
    }

    cout << dist[adj[p][0][0]][adj[p][0][1]];

    return 0;
}