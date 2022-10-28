#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int x1, y1, x2, y2, v, t, vx, vy, wx, wy;
  cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;

  double l = 0.0, r = 1e10;
  for (int i = 0; i < 64; ++i) {
    double m = (l + r) / 2;

    double x = x1, y = y1;
    if (m >= t) {
      x += vx * t, y += vy * t;
      x += wx * (m - t), y += wy * (m - t);
    } else {
      x += vx * m, y += vy * m;
    }

    x -= x2, y -= y2;

    (sqrt(x * x + y * y) <= v * m ? r : l) = m;
  }

  cout << l << "\n";
}