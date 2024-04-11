/**
 *  author: milos
 *  created: 26.12.2020 18:20:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> b[i][j];
    }
  }
  vector<int> row_a(n, 0), col_a(m, 0);
  vector<int> row_b(n, 0), col_b(m, 0);
  int sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row_a[i] += a[i][j];
      row_b[i] += b[i][j];
      col_a[j] += a[i][j];
      col_b[j] += b[i][j];
      sum_a += a[i][j];
      sum_b += b[i][j];
    }
  }
  bool ok = true;
  if (sum_a % 2 != sum_b % 2) {
   ok = false;   
  }
  for (int i = 0; i < n; i++) {
    if (row_a[i] % 2 != row_b[i] % 2) {
      ok = false;
    }
  }
  for (int i = 0; i < m; i++) {
    if (col_a[i] % 2 != col_b[i] % 2) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}