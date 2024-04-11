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
    for (auto &i : grid) {
      cin >> i;
    }

    vector<int> left(10, n), right(10, -1), up(10, n), down(10, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int d = grid[i][j] - '0';
        up[d] = min(up[d], i);
        down[d] = max(down[d], i);
        left[d] = min(left[d], j);
        right[d] = max(right[d], j);
      }
    }

    vector<int> ans(10);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int d = grid[i][j] - '0';
        ans[d] = max({ans[d],
            (i - up[d]) * max(j, n - 1 - j),
            (down[d] - i) * max(j, n - 1 - j),
            (j - left[d]) * max(i, n - 1 - i),
            (right[d] - j) * max(i, n - 1 - i)
        });
      }
    }

    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}