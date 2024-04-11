#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &i : grid) {
      cin >> i;
    }

    int ans = 0;
    vector<vector<int>> length(n, vector<int>(m));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '*') {
          length[i][j] = n;
          for (int k = j - 1; k <= j + 1; ++k) {
            if (i + 1 < n && k >= 0 && k < m) {
              length[i][j] = min(length[i][j], length[i + 1][k] + 1);
            } else {
              length[i][j] = 1;
            }
          }
          ans += length[i][j];
        }
      }
    }

    cout << ans << "\n";
  }
}