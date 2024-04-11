#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<array<int, 2>, int> point;
  map<int, int> row, col;
  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ++row[x], ++col[y], ++point[{x, y}];
  }

  for (auto &[r, x] : row) {
    ans += (long long) x * (x - 1) / 2;
  }

  for (auto &[c, x] : col) {
    ans += (long long) x * (x - 1) / 2;
  }

  for (auto &[p, x] : point) {
    ans -= (long long) x * (x - 1) / 2;
  }

  cout << ans << "\n";
}