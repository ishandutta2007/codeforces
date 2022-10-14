#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  auto Check = [&](long double t) {
    vector<pair<long double, int>> ev;
    for (int i = 0; i < n; i++) {
      ev.push_back({x[i] - t * v[i], -1});
      ev.push_back({x[i] + t * v[i], 1});
    }
    sort(ev.begin(), ev.end());
    int cnt = 0;
    for (auto e : ev) {
      cnt -= e.second;
      if (cnt == n) {
        return true;
      }
    }
    return false;
  };
  const double eps = 1e-7;
  long double bot = 0, top = 1e9, ans = 0;
  while (top - bot >= eps) {
    long double mid = (bot + top) / 2;
    if (Check(mid)) {
      ans = mid;
      top = mid;
    } else {
      bot = mid;
    }
  }
  cout << fixed << setprecision(6) << ans << '\n';
  return 0;
}