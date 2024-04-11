#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

long long i, i1, j, k, k1, t, n, m, res, check1, check2, a, b, c, u, v, w, p[400050], dist[200010][3], ps[200010];
vector<long long> adj[200010];
queue<long long> q;
bool visited[200010];

void bfs(int s, int o) {
    for (i = 1; i <= n; i++) {
        visited[i] = false;
    }
    dist[s][o] = 0;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if (!visited[u]) {
                q.push(u);
                visited[u] = true;
                dist[u][o] = dist[v][o] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b >> c;
        p[0] = 0;
        for (i = 0; i < m; i++) {
            cin >> p[i + 1];
        }
        for (i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (i = 0; i < m; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        sort(p + 1, p + m + 1);
        for (i = m + 1; i < 2 * m + 10; i++) {
            p[i] = (long long)1e18;
        }
        ps[0] = p[0];
        for (i = 1; i <= m; i++) {
            ps[i] = ps[i - 1] + p[i];
        }

        /* for (i = 1; i <= m; i++) {
            cout << ps[i] << ' ';
        }
        cout << endl; */

        bfs(a, 0); bfs(b, 1); bfs(c, 2);

        res = (long long)1e18;
        for (i = 1; i <= n; i++) {
            if (dist[i][0] + dist[i][1] + dist[i][2] > m) {
                continue;
            }
            /* check1 = -2;
            check2 = -2;
            for (auto u : adj[i]) {
                if (dist[u][0] == dist[i][0] - 1) {
                    if (check1 == -2) {
                        check1 = u;
                    } else {
                        check1 = -1;
                    }
                }
                if (dist[u][2] == dist[i][2] - 1) {
                    if (check2 == -2) {
                        check2 = u;
                    } else {
                        check2 = -1;
                    }
                }
            }
            if (check1 >= 0 && check2 == check1) {
                continue;
            }  */

            // cout << i << ' ' << ps[dist[i][1]] + ps[dist[i][0] + dist[i][1] + dist[i][2]] << endl;
            // cout << dist[i][0] << ' ' << dist[i][1] << ' ' << dist[i][2] << endl;
            res = min(res, ps[dist[i][1]] + ps[dist[i][0] + dist[i][1] + dist[i][2]]);
        }

        cout << res << endl;
    }

    return 0;
}