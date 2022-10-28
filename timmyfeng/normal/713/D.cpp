#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int L = __lg(N) + 1;

int sparse[L][N][L][N];
int a[N][N];

int query(int x1, int y1, int x2, int y2) {
  int log_x = __lg(x2 - x1);
  int log_y = __lg(y2 - y1);
  return max({
      sparse[log_x][x1][log_y][y1],
      sparse[log_x][x2 - (1 << log_x)][log_y][y1],
      sparse[log_x][x1][log_y][y2 - (1 << log_y)],
      sparse[log_x][x2 - (1 << log_x)][log_y][y2 - (1 << log_y)]
  });
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i][j] == 1 && i < n - 1 && j < m - 1) {
        a[i][j] = min({a[i + 1][j], a[i][j + 1], a[i + 1][j + 1]}) + 1;
      }
    }
  }

  for (int i1 = 0; i1 <= __lg(n); ++i1) {
    int len_i = 1 << i1;
    for (int i2 = 0; i2 + len_i <= n; ++i2) {
      for (int j1 = 0; j1 <= __lg(m); ++j1) {
        int len_j = 1 << j1;
        for (int j2 = 0; j2 + len_j <= m; ++j2) {
          if (i1 > 0) {
            sparse[i1][i2][j1][j2] = max(
                sparse[i1 - 1][i2][j1][j2],
                sparse[i1 - 1][i2 + len_i / 2][j1][j2]
            );
          } else if (j1 > 0) {
            sparse[i1][i2][j1][j2] = max(
                sparse[i1][i2][j1 - 1][j2],
                sparse[i1][i2][j1 - 1][j2 + len_j / 2]
            );
          } else {
            sparse[i1][i2][j1][j2] = a[i2][j2];
          }
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1;

    int lo = 0;
    int hi = min(x2 - x1, y2 - y1);
    while (lo < hi) {
      int size = (lo + hi + 1) / 2;
      if (query(x1, y1, x2 - size + 1, y2 - size + 1) >= size) {
        lo = size;
      } else {
        hi = size - 1;
      }
    }

    cout << lo << "\n";
  }
}