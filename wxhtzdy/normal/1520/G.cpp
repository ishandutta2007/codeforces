#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, w;
  cin >> n >> m >> w;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  const long long inf = 1e18;
  vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(2, inf)));
  function<void(int, int, int)> Bfs = [&](int x, int y, int z) {
    dist[x][y][z] = 0;
    vector<pair<int, int>> q;
    q.emplace_back(x, y);
    for (int b = 0; b < (int) q.size(); b++) {
      for (int j = 0; j < 4; j++) {
        int nx = q[b].first + dx[j], ny = q[b].second + dy[j];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != -1) {
          if (dist[nx][ny][z] == inf) {
            q.emplace_back(nx, ny);
          }
          dist[nx][ny][z] = min(dist[nx][ny][z], dist[q[b].first][q[b].second][z] + w);
        }
      }
    }
  };
  Bfs(0, 0, 0);
  Bfs(n - 1, m - 1, 1);
  long long ans = dist[n - 1][m - 1][0];
  long long mn = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j][1] != inf && a[i][j] > 0) {
        mn = min(mn, dist[i][j][1] + a[i][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] > 0 && dist[i][j][0] != inf) {
        ans = min(ans, mn + dist[i][j][0] + a[i][j]);
      }
    }
  }
  cout << (ans == inf ? -1 : ans) << '\n';
  return 0;
}