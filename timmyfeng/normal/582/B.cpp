#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int m = b.size();

  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }

  vector<vector<int>> matrix(m, vector<int>(m, INT_MIN));
  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      multiset<int> lis;
      for (int k = 0; k < n; ++k) {
        if (a[k] >= i && a[k] <= j) {
          auto it = lis.upper_bound(a[k]);
          if (it != lis.end()) {
            lis.erase(it);
          }
          lis.insert(a[k]);
        }
      }
      matrix[i][j] = lis.size();
    }
  }

  vector<int> length(m);
  for (int i = 1; t > 0; i *= 2) {
    if ((t & i) > 0) {
      vector<int> new_length(m);
      for (int a = 0; a < m; ++a) {
        for (int b = 0; b < m; ++b) {
          new_length[b] = max(new_length[b], length[a] + matrix[a][b]);
        }
      }
      length = new_length;
      t -= i;
    }

    vector<vector<int>> new_matrix(m, vector<int>(m, INT_MIN));
    for (int a = 0; a < m; ++a) {
      for (int b = 0; b < m; ++b) {
        for (int c = 0; c < m; ++c) {
          if (min(matrix[a][b], matrix[b][c]) > INT_MIN) {
            new_matrix[a][c] = max(new_matrix[a][c], matrix[a][b] + matrix[b][c]);
          }
        }
      }
    }

    matrix = new_matrix;
  }

  cout << *max_element(length.begin(), length.end()) << "\n";
}