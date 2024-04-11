#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> x(n);
  vector<long long> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  auto orient = [&](long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long p = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    return p == 0 ? 0 : (p > 0 ? 1 : 2);
  };
  auto Check = [&](long long xx, long long yy) {
    if (orient(x[0], y[0], xx, yy, x[n - 1], y[n - 1]) != 1) {
      return false;
    }
    long long low = 0, high = n - 1, idx = 0;
    while (low <= high) {
      long long mid = low + high >> 1;
      if (orient(x[0], x[0], x[mid], y[mid], xx, yy) == 1) {
        idx = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    long long ori = orient(x[idx], y[idx], xx, yy, x[(idx + 1) % n], y[(idx + 1) % n]);
    return ori == 2;
  };
  int m;
  cin >> m;
  bool ok = true;
  for (int i = 0; i < m; i++) {
    long long xx, yy;
    cin >> xx >> yy;
    ok &= Check(xx, yy);
  }
  cout << (ok ? "YES" : "NO");
  return 0;
}