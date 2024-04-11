#include <bits/stdc++.h>
using namespace std;

const int N = 100;

array<int, 2> where[N][N];
int ans[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      where[i][j] = {i, j};
    }
  }

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int r;
      cin >> r;
      array<int, 2> temp = where[r - 1][0];
      for (int c = 0; c < m - 1; ++c) {
        where[r - 1][c] = where[r - 1][c + 1];
      }
      where[r - 1][m - 1] = temp;
    } else if (type == 2) {
      int c;
      cin >> c;
      array<int, 2> temp = where[0][c - 1];
      for (int r = 0; r < n - 1; ++r) {
        where[r][c - 1] = where[r + 1][c - 1];
      }
      where[n - 1][c - 1] = temp;
    } else {
      int r, c, x;
      cin >> r >> c >> x;
      ans[where[r - 1][c - 1][0]][where[r - 1][c - 1][1]] = x;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}