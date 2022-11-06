#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, v1, v2, k;
  cin >> n >> l >> v1 >> v2 >> k;
  double left = 1.0 * l / v2, right = 1.0 * l / v1;
  for (int it = 0; it < 50; ++it) {
    double mid = 0.5 * (left + right);
    double x = (mid * v1 * v2 - 1.0 * v1 * l) / (v2 - v1);
    double y = l - x;
    double pos = 0.0;
    int cnt = n;
    bool ok = true;
    while (ok) {
      if (pos > x) {
        ok = false;
        break;
      }
      if (cnt <= k) break;
      cnt -= k;
      double t = y / v2;
      double cpos = pos + y;
      pos += v1 * t;
      t = (cpos - pos) / (v1 + v2);
      pos += v1 * t;
    }
    (ok ? right : left) = mid;
  }
  cout << fixed << setprecision(20) << left << "\n";
}