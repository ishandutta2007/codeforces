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

    map<int, int> cost;
    for (int i = 0, j = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (cost.count(a) == 0) {
        cost[a] = 1;
      }
      ++cost[a];
      if (i == 0) {
        --cost[a];
      }
      if (i == n - 1) {
        --cost[a];
      }
      if (a == j) {
        --cost[a];
      }
      j = a;
    }

    int ans = INT_MAX;
    for (auto [a, b] : cost) {
      ans = min(ans, b);
    }
    cout << ans << "\n";
  }
}