#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  vector<pair<int, int>> a;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y >= 0) {
      a.push_back({x, y});
    } else {
      x = max(x, abs(y));
      b.push_back({x, y});
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), [&](pair<int, int> x, pair<int, int> y) {
    return x.first + x.second > y.first + y.second;
  });
  for (int i = 0; i < (int) a.size(); i++) {
    if (r < a[i].first) {
      cout << "NO" << '\n';
      return 0;
    } else {
      r += a[i].second;
    }
  }
  for (int i = 0; i < (int) b.size(); i++) {
    if (r < b[i].first) {
      cout << "NO" << '\n';
      return 0;
    } else {
      r += b[i].second;
    }
  }
  cout << "YES" << '\n';
  return 0;
}