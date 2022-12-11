#include <bits/stdc++.h>

using namespace std;

const int N = 1007, K = 42;
int dist[K][N][N];
vector <pair <int, int>> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int cc[N][N];
bool vis0[K];
bool vis[N][N];
int lst[N][N];
vector <pair <int, int>> comp[K];
int ress;
int step;

void bfs(int n, int m, int c) {
    memset(vis0, 0, sizeof(vis0));
    memset(vis, 0, sizeof(vis));
    queue <pair <int, int>> q;
    vis0[c] = 1;
    for (auto [x, y] : comp[c]) {
        dist[c][x][y] = 0;
        vis[x][y] = 1;
        q.push({x, y});
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int d = dist[c][x][y];
        if (!vis0[cc[x][y]]) {
            vis0[cc[x][y]] = 1;
            for (auto [nx, ny] : comp[cc[x][y]]) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dist[c][nx][ny] = d + 1;
                    q.push({nx, ny});
                }
            }
        }
        for (auto [dx, dy] : dd) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    dist[c][nx][ny] = d + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

bool dfs(int n, int m, int x, int y, int fx, int fy, int pref = 0) {
    if (pref + dist[cc[x][y]][fx][fy] >= ress) return 0;
    lst[x][y] = step;
    if (x == fx && y == fy && pref < ress) return 1;
    if (pref + dist[cc[x][y]][fx][fy] + 1 < ress) return 1;
    for (auto [dx, dy] : dd) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && lst[nx][ny] != step && cc[nx][ny] != cc[x][y]) {
            if (dfs(n, m, nx, ny, fx, fy, pref + 1)) return 1;
        }
    }
    return 0;
}

signed main() {
    memset(lst, 0, sizeof(lst));
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cc[i][j];
            comp[cc[i][j]].push_back({i, j});
        }
    }
    for (int c = 1; c <= k; c++) bfs(n, m, c);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        step = i + 1;
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        a1--, b1--, a2--, b2--;
        ress = dist[cc[a1][b1]][a2][b2] + 1;
        if (dfs(n, m, a1, b1, a2, b2)) ress--;
        cout << ress << "\n";
    }
}