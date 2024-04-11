/**
 *    author:  tourist
 *    created: 19.01.2020 16:38:38       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  vector<long long> x(1, x0);
  vector<long long> y(1, y0);
  while (true) {
    long long bound = 0;
    if (x.back() > xs) {
      bound += x.back() - xs;
    }
    if (y.back() > ys) {
      bound += y.back() - ys;
    }
    if (bound > t) {
      x.pop_back();
      y.pop_back();
      break;
    }
    x.push_back(x.back() * ax + bx);
    y.push_back(y.back() * ay + by);
  }
  int n = (int) x.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long dx = x[j] - x[i];
      long long dy = y[j] - y[i];
      long long to_i = abs(xs - x[i]) + abs(ys - y[i]);
      long long to_j = abs(xs - x[j]) + abs(ys - y[j]);
      long long cur = min(to_i, to_j) + dx + dy;
      if (cur <= t) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}