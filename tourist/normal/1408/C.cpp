/**
 *    author:  tourist
 *    created: 30.09.2020 17:41:56       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    double low = 0;
    double high = l;
    for (int it = 0; it < 100; it++) {
      double mid = 0.5 * (low + high);
      double total = 0;
      {
        double t = mid;
        double x = 0;
        double v = 1;
        for (int i = 0; i < n; i++) {
          double until = (a[i] - x) / v;
          if (until <= t) {
            t -= until;
            x = a[i];
            v += 1;
            continue;
          }
          break;
        }
        x += v * t;
        total += x;
      }
      {
        double t = mid;
        double x = l;
        double v = 1;
        for (int i = n - 1; i >= 0; i--) {
          double until = (x - a[i]) / v;
          if (until <= t) {
            t -= until;
            x = a[i];
            v += 1;
            continue;
          }
          break;
        }
        x -= v * t;
        total += l - x;
      }
      if (total >= l) {
        high = mid;
      } else {
        low = mid;
      }
    }
    cout << fixed << setprecision(17) << 0.5 * (low + high) << '\n';
  }
  return 0;
}