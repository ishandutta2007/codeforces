#include <bits/stdc++.h>
using namespace std;

const int DR[] = {0, 1, 0, -1};
const int DC[] = {-1, 0, 1, 0};
const int N = 2000;

pair<int, int> dist[N][N];
string grid[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, r, c, x, y;
  cin >> n >> m >> r >> c >> x >> y;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i][j] = {-1, -1};
    }
  }
  dist[r - 1][c - 1] = {0, 0};

  deque<pair<int, int>> que;
  que.emplace_back(r - 1,c - 1);
  int ans = 0;

  while (!que.empty()) {
    auto [rr, cc] = que.front();
    que.pop_front();

    if (dist[rr][cc].first > x || dist[rr][cc].second > y) {
      continue;
    }

    ++ans;

    for (int i = 0; i < 4; ++i) {
      int r_new = rr + DR[i];
      int c_new = cc + DC[i];

      if (r_new >= 0 && r_new < n && c_new >= 0 && c_new < m &&
          dist[r_new][c_new].first == -1 && grid[r_new][c_new] == '.') {
        dist[r_new][c_new] = dist[rr][cc];
        dist[r_new][c_new].first += (i == 0);
        dist[r_new][c_new].second += (i == 2);
        if (i == 0 || i == 2) {
          que.emplace_back(r_new, c_new);
        } else {
          que.emplace_front(r_new, c_new);
        }
      }
    }
  }
  cout << ans << "\n";
}