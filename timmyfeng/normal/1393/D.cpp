#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
const int R[] = {0, -1, 0, 1};
const int C[] = {1, 0, -1, 0};

string grid[N];
int dist[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dist[i][j] = -1;
      for (int k = 0; k < 4; ++k) {
        int ii = i + R[k];
        int jj = j + C[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] != grid[i][j]) {
          que.emplace(i, j);
          dist[i][j] = 1;
          break;
        }
      }
    }
  }


  long long ans = 0;
  while (!que.empty()) {
    auto [i, j] = que.front();
    que.pop();
    ans += dist[i][j];
    for (int k = 0; k < 4; ++k) {
      int ii = i + R[k];
      int jj = j + C[k];
      if (ii >= 0 && ii < n && jj >= 0 && jj <= m && grid[ii][jj] == grid[i][j] && dist[ii][jj] == -1) {
        dist[ii][jj] = dist[i][j] + 1;
        que.emplace(ii, jj);
      }
    }
  }

  cout << ans << "\n";
}