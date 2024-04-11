#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  vector<vector<pair<int, int>>> pos(26);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++) {
      pos[s[i][j] - 'a'].emplace_back(i, j);
    }
  }
  vector<vector<int>> mn(n, vector<int>(m, 1e9));
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<pair<int, int>> que;
  for (int c = 0; c < 26; c++) {
    for (auto p : pos[c]) {
      dist[p.first][p.second] = 0;
      que.push_back(p);
    }
    for (int v = 0; v < que.size(); v++) {
      int x = que[v].first;
      int y = que[v].second;
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == 1e9 && mn[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          mn[nx][ny] = min(mn[nx][ny], dist[nx][ny]);
          que.emplace_back(nx, ny);
        }
      }
    }
    que.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dist[i][j] = 1e9;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += min({mn[i][j], i + 1, n - i, j + 1, m - j});
    }
  }
  cout << ans << '\n';
  return 0;
}