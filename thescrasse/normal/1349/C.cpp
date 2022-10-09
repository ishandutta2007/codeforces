#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, check2, a, b, x, y, p, cc[1010][1010], dist[1010][1010];
char mt[1010][1010];
bool visited[1010][1010], visited2[1010][1010];
deque<pair<ll, ll>> q;

ll d1[4] = {1, 0, -1, 0};
ll d2[4] = {0, 1, 0, -1};

void dfs(ll x, ll y, ll c, ll check1) {
    // cout << x << ' ' << y << ' ' << c << ' ' << check1 << endl;
    ll i, j, k, m1, m2;
    /* if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    cc[x][y] = c; */
    for (i = 0; i < 4; i++) {
        m1 = x + d1[i]; m2 = y + d2[i];
        if (m1 >= 0 && m2 >= 0 && m1 < n && m2 < m) {
            if (mt[x][y] == mt[m1][m2]) {
                if (!visited[m1][m2]) {
                    // cout << m1 << ' ' << m2 << endl;
                    visited[m1][m2] = true;
                    cc[m1][m2] = c;
                    if (check1 == 0) {
                        dist[x][y] = 0;
                        visited2[x][y] = true;
                        q.push_front({x, y});
                    }
                    dist[m1][m2] = 0;
                    visited2[m1][m2] = true;
                    q.push_front({m1, m2});
                    dfs(m1, m2, c, 1);
                }
            }
        }
    }
}

void bfs() {
    ll i, j, k, x, y, m1, m2;
    while (!q.empty()) {
        x = q.front().first; y = q.front().second; q.pop_front();
        for (i = 0; i < 4; i++) {
            m1 = x + d1[i]; m2 = y + d2[i];
            if (m1 >= 0 && m2 >= 0 && m1 < n && m2 < m) {
                if (!visited2[m1][m2]) {
                    visited2[m1][m2] = true;
                    if (cc[x][y] == cc[m1][m2]) {
                        q.push_front({m1, m2});
                        dist[m1][m2] = dist[x][y];
                    } else {
                        q.push_back({m1, m2});
                        dist[m1][m2] = dist[x][y] + 1;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m >> t;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> mt[i][j];
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j]) {
                // cout << i << ' ' << j << endl;
                visited[i][j] = true; cc[i][j] = k;
                dfs(i, j, k, 0);
                k++;
            }
        }
    }

    bfs();

    /* for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << i << ' ' << j << ' ' << cc[i][j] << ' ' << dist[i][j] << endl;
        }
    } */

    while (t--) {
        cin >> x >> y >> p;
        x--; y--;
        if (p < dist[x][y]) {
            cout << mt[x][y] << endl;
        } else {
            p -= dist[x][y];
            if (cc[n - 1][m - 1] == n * m - 1) {
                cout << mt[x][y] << endl;
            } else {
                cout << (ll)(mt[x][y] + p) % 2 << endl;
            }
        }
    }

    return 0;
}