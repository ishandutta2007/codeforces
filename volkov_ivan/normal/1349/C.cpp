#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1007;
bool f[N][N];
bool vis[N][N];
int sz[N][N];
int dst[N][N];
vector <pair <int, int>> mov = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
vector <pair <int, int>> cur;

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void dfs(int x, int y, bool c) {
    if (!check(x, y)) return;
    if (vis[x][y]) return;
    if (f[x][y] != c) return;
    cur.push_back({x, y});
    vis[x][y] = 1;
    for (auto elem : mov) dfs(x + elem.first, y + elem.second, c);
}

void bfs() {
    memset(vis, 0, sizeof(vis));
    queue <pair <int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sz[i][j] > 1) {
                dst[i][j] = 0;
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        pair <int, int> elem = q.front();
        q.pop();
        int x = elem.first, y = elem.second;
        for (auto elem : mov) {
            int nx = x + elem.first, ny = y + elem.second;
            if (check(nx, ny) && !vis[nx][ny]) {
                dst[nx][ny] = dst[x][y] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

signed main() {
    memset(vis, 0, sizeof(vis));
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == '1') f[i][j] = 1;
            else f[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                cur.clear();
                dfs(i, j, f[i][j]);
                for (auto elem : cur) sz[elem.first][elem.second] = cur.size();
            }
        }
    }
    bfs();
    for (int i = 0; i < q; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        if (!vis[x][y]) {
            cout << (f[x][y] ? 1 : 0) << "\n";
            continue;
        }
        //cout << dst[x][y] << ' ' << t << endl;
        t -= dst[x][y];
        if (t <= 0) {
            cout << (f[x][y] ? 1 : 0) << "\n";
            continue;
        }
        t %= 2;
        if (t == 0) {
            cout << (f[x][y] ? 1 : 0) << "\n";
        } else {
            cout << (f[x][y] ? 0 : 1) << "\n";
        }
    }
    return 0;
}