#include <bits/stdc++.h>
using namespace std;

const int I[] = {0, -1, 0, 1};
const int J[] = {1, 0, -1, 0};
const int N = 1000 + 1;
const int K = 3 + 1;

int dist[K][N][N], cost[K][K];
string grid[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  for (int k = 1; k <= 3; ++k) {
    queue<array<int, 2>> que;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == k + '0') {
          que.push({i, j});
        } else {
          dist[k][i][j] = -1;
        }
      }
    }

    while (!que.empty()) {
      auto [i, j] = que.front();
      que.pop();
      for (int d = 0; d < 4; ++d) {
        int r = i + I[d], c = j + J[d];
        if (r >= 0 && r < n && c >= 0 && c < m && dist[k][r][c] == -1 && grid[r][c] != '#') {
          dist[k][r][c] = dist[k][i][j] + (grid[r][c] == '.');
          que.push({r, c});
        }
      }
    }
  }

  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cost[i][j] = n * m;
    }
  }

  int ans = n * m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') {
        int sum = -2;
        bool ok = true;
        for (int k = 1; k <= 3; ++k) {
          ok &= (dist[k][i][j] != -1);
          sum += dist[k][i][j];
        }

        if (ok) {
          ans = min(ans, sum);
        }
      } else if (grid[i][j] >= '1' && grid[i][j] <= '3') {
        int k = grid[i][j] - '0';
        for (int l = 1; l <= 3; ++l) {
          if (dist[l][i][j] != -1) {
            cost[k][l] = min(cost[k][l], dist[l][i][j]);
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; ++i) {
    int sum = 0;
    bool ok = true;
    for (int j = 1; j <= 3; ++j) {
      ok &= (cost[i][j] < n * m);
      sum += cost[i][j];
    }

    if (ok) {
      ans = min(ans, sum);
    }
  }

  cout << (ans == n * m ? -1 : ans) << "\n";
}