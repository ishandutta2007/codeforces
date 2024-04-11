#include <bits/stdc++.h>
using namespace std;

const int N = 251;

int ans[N][N];
int row[N];
int col[N];

bool mx[N * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      row[i] = max(row[i], a);
      col[j] = max(col[j], a);
    }
  }

  sort(row, row + n, greater<int>());
  sort(col, col + m, greater<int>());

  int r = 0;
  int c = 0;
  while (r < n || c < m) {
    if (r == n || (c < m && row[r] < col[c])) {
      ans[r - 1][c] = col[c];
      ++c;
    } else if (c == m || (r < n && col[c] < row[r])) {
      ans[r][c - 1] = row[r];
      ++r;
    } else {
      ans[r][c] = row[r];
      ++r;
      ++c;
    }
  }

  for (int i = 0; i < n; ++i) {
    mx[row[i]] = true;
  }
  for (int i = 0; i < m; ++i) {
    mx[col[i]] = true;
  }

  int cur = 0;
  auto nxt = [&]() {
    do {
      ++cur;
    } while (mx[cur]);
    return cur;
  };

  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (mx[ans[i][j]]) {
        if (i > 0 && ans[i - 1][j] == 0) {
          for (int k = 0; k < i; ++k) {
            ans[k][j] = nxt();
          }
        }
        if (j > 0 && ans[i][j - 1] == 0) {
          for (int k = 0; k < j; ++k) {
            ans[i][k] = nxt();
          }
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}