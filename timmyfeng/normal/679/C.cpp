#include <bits/stdc++.h>
using namespace std;

const int R[] = {0, 1, 0, -1};
const int C[] = {1, 0, -1, 0};
const int N = 500 + 2;

int res[N][N], grid[N][N], color[N][N], sub[N * N];
bool visited[N * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; ++j) {
      grid[i][j] = (s[j - 1] == 'X');
    }
  }

  int m = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (color[i][j] == 0 && grid[i][j] == 0) {
        int min_r = n, min_c = n, max_r = 1, max_c = 1;
        queue<array<int, 2>> que;
        color[i][j] = ++m;
        que.push({i, j});

        while (!que.empty()) {
          auto [r, c] = que.front();
          que.pop();

          min_r = min(min_r, r);
          max_r = max(max_r, r);
          min_c = min(min_c, c);
          max_c = max(max_c, c);
          ++sub[m];

          for (int d = 0; d < 4; ++d) {
            int rr = r + R[d];
            int cc = c + C[d];
            if (rr > 0 && rr <= n && cc > 0 && cc <= n) {
              if (grid[rr][cc] == 0 && color[rr][cc] == 0) {
                que.push({rr, cc});
                color[rr][cc] = m;
              }
            }
          }
        }

        if (max(max_r - min_r, max_c - min_c) + 1 <= k) {
          max_r = max(1, max_r - k + 1), max_c = max(1, max_c - k + 1);
          ++min_r, ++min_c;

          res[max_r][max_c] += sub[m];
          res[max_r][min_c] -= sub[m];
          res[min_r][max_c] -= sub[m];
          res[min_r][min_c] += sub[m];
        }
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      grid[i][j] += -grid[i - 1][j - 1] + grid[i - 1][j] + grid[i][j - 1];
      res[i][j] += -res[i - 1][j - 1] + res[i - 1][j] + res[i][j - 1];
    }
  }

  int ans = 0;
  for (int i = 1; i + k - 1 <= n; ++i) {
    for (int j = 1; j + k - 1 <= n; ++j) {
      res[i][j] += grid[i + k - 1][j + k - 1] -
          grid[i + k - 1][j - 1] -
          grid[i - 1][j + k - 1] +
          grid[i - 1][j - 1];

      vector<int> adj;
      for (int x = 0; x < k; ++x) {
        adj.push_back(color[i - 1][j + x]);
        adj.push_back(color[i + k][j + x]);
        adj.push_back(color[i + x][j - 1]);
        adj.push_back(color[i + x][j + k]);
      }

      for (auto x : adj) {
        if (!visited[x]) {
          res[i][j] += sub[x];
          visited[x] = true;
        }
      }

      for (auto x : adj) {
        visited[x] = false;
      }

      ans = max(ans, res[i][j]);
    }
  }

  cout << ans << "\n";
}