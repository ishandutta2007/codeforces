#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n, r, v;
  cin >> n >> r >> v;

  for (int i = 0; i < n; ++i) {
    int s, f;
    cin >> s >> f;
    int d = f - s;

    double t = HUGE_VAL;
    for (auto k : {-M_PI / 2, M_PI / 2}) {
      double lo = 0.0, hi = 1e9;
      for (int j = 0; j < 64; ++j) {
        double mid = (lo + hi) / 2;
        (v * mid + r * cos(v * mid / r + k) < d / 2.0 ? lo : hi) = mid;
      }
      t = min(t, lo);
    }

    cout << 2 * t << "\n";
  }
}