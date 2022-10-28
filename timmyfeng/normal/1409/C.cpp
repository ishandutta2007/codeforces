#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ans = {int(1e9)};
    for (int i = 1; i <= y - x; ++i) {
      for (int j = 1; j <= x; ++j) {
        vector<int> cur(n);
        for (int k = 0; k < n; ++k) {
          cur[k] = j + k * i;
        }

        if (count(cur.begin(), cur.end(), x) > 0 && count(cur.begin(), cur.end(), y) > 0 && cur.back() < ans.back()) {
          ans = cur;
        }
      }
    }

    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}