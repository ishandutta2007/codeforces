/**
 *  author: milos
 *  created: 26.12.2020 20:34:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, t;
  cin >> n >> m >> t;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  deque<pair<int, int>> q;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};       
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool ok = false;
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[i][j] == s[nx][ny]) {
          ok = true;
        }
      }
      if (ok) {
        q.push_back({i, j});
      }    
    }
  }
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  for (auto c : q) {
    dist[c.first][c.second] = 0;
  }
  while (!q.empty()) {
    auto c = q[0];
    for (int i = 0; i < 4; i++) {
      int nx = c.first + dx[i], ny = c.second + dy[i];
      if (nx >= 0 && nx < n && ny >= 0 && ny <= m && dist[nx][ny] == 1e9) {
        dist[nx][ny] = dist[c.first][c.second] + 1;
        q.push_back({nx, ny});
      }
    }
    q.pop_front();
  }
  while (t--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    long long k;
    cin >> k;
    if (dist[x][y] == 1e9) {
      cout << s[x][y] << '\n';
    } else {
      int c = (int) (s[x][y] - '0');
      int ans = c ^ (max((long long) 0, k - dist[x][y]) & 1);
      cout << ans << '\n';
    }
  }
  return 0;
}