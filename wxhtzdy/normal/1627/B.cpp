#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a.emplace_back(i, j);
      }
    }
    auto Dist = [&](pair<int, int> x, pair<int, int> y) {
      return abs(x.first - y.first) + abs(x.second - y.second);
    };
    auto Close = [&](pair<int, int> x) {
      return max({Dist(x, {0, 0}), Dist(x, {0, m - 1}), Dist(x, {n - 1, 0}), Dist(x, {n - 1, m - 1})});
    };
    sort(a.begin(), a.end(), [&](pair<int, int> x, pair<int, int> y) {
      return Close(x) < Close(y);
    });
    for (int i = 0; i < n * m; i++) {
      cout << Close(a[i]) << " ";
    }
    cout << '\n';
  }
  return 0;
}