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

    int x = n;
    vector<array<int, 2>> ans;
    for (int i = n - 1; i > 1; --i) {
      while ((x + i - 1) / i >= i) {
        x = (x + i - 1) / i;
        ans.push_back({n, i});
      }
      ans.push_back({i, n});
    }

    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
      cout << x << " " << y << "\n";
    }
  }
}