#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto& i : grid) {
      cin >> i;
    }

    vector<array<int, 2>> ans;

    if (grid[0][1] == grid[1][0]) {
      if (grid[n - 1][n - 2] == grid[0][1]) {
        ans.push_back({n - 1, n - 2});
      }
      if (grid[n - 2][n - 1] == grid[0][1]) {
        ans.push_back({n - 2, n - 1});
      }
    } else if (grid[n - 1][n - 2] == grid[n - 2][n - 1]) {
      if (grid[0][1] == grid[n - 1][n - 2]) {
        ans.push_back({0, 1});
      }
      if (grid[1][0] == grid[n - 1][n - 2]) {
        ans.push_back({1, 0});
      }
    } else {
      if (grid[0][1] == '1') {
        ans.push_back({0, 1});
      }
      if (grid[1][0] == '1') {
        ans.push_back({1, 0});
      }
      if (grid[n - 2][n - 1] == '0') {
        ans.push_back({n - 2, n - 1});
      }
      if (grid[n - 1][n - 2] == '0') {
        ans.push_back({n - 1, n - 2});
      }
    }

    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
      cout << a + 1 << " " << b + 1 << "\n";
    }
  }
}