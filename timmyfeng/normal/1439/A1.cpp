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
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }

    vector<set<array<int, 2>>> ans;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '1') {
          int x = i == n - 1 ? i - 1 : i;
          int y = j == m - 1 ? j - 1 : j;

          set<array<int, 2>> block;
          for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
              block.insert({x + r, y + c});
            }
          }

          for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < 2; ++c) {
              if (x + r != i || y + c != j) {
                block.erase({x + r, y + c});
                ans.push_back(block);
                block.insert({x + r, y + c});
              }
            }
          }
        }
      }
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
      for (auto [x, y] : i) {
        cout << x + 1 << " " << y + 1 << " ";
      }
      cout << "\n";
    }
  }
}