#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t;
  cin >> n >> m >> t;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  constexpr int dx[4] = {1, 0, -1, 0};
  constexpr int dy[4] = {0, 1, 0, -1};

  vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));
  vector<tuple<int, int, int>> que;
  vector<vector<bool>> vis(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool ok = false;
      for (int k = 0; k < 4; ++k) {
        if (i + dx[k] < 0 || i + dx[k] >= n) continue;
        if (j + dy[k] < 0 || j + dy[k] >= m) continue;
        if (s[i + dx[k]][j + dy[k]] == s[i][j]) ok = true;
      }
      if (ok) {
        dist[i][j][s[i][j] - '0'] = 0;
        vis[i][j] = true;
        que.emplace_back(i, j, s[i][j] - '0');
      }
    }
  }
  for (int it = 0; it < que.size(); ++it) {
    auto [x, y, z] = que[it];
    if (dist[x][y][z ^ 1] == -1) {
      dist[x][y][z ^ 1] = dist[x][y][z] + 1; 
      que.emplace_back(x, y, z ^ 1);
    }
    for (int k = 0; k < 4; ++k) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny]) continue;
      if (z == s[nx][ny] - '0') {
        vis[nx][ny] = true;
        dist[nx][ny][z ^ 1] = dist[x][y][z] + 1;
        que.emplace_back(nx, ny, z ^ 1);
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
    // for (int j = 0; j < m; ++j) {
      // cout << "(" << dist[i][j][0] << " " << dist[i][j][1] << ") ";
    // }
    // cout << endl;
  // }
  while (t--) {
    int i, j;
    int64_t p;
    cin >> i >> j >> p;
    i--, j--;
    if (dist[i][j][0] == -1) {
      cout << s[i][j] - '0' << "\n";
    } else {
      assert(dist[i][j][0] != -1 && dist[i][j][1] != -1);
      if (dist[i][j][0] < dist[i][j][1]) {
        if (p < dist[i][j][0]) cout << s[i][j] - '0' << "\n";
        else cout << (p - dist[i][j][0]) % 2 << "\n";
      } else {
        if (p < dist[i][j][1]) cout << s[i][j] - '0' << "\n";
        else cout << ((p - dist[i][j][1]) % 2 + 1) % 2 << "\n";
      }
    }
  }
}