#include <bits/stdc++.h>
using namespace std;

double a, b, c;

double get_x(double y) {
  return -(b * y + c) / a;
}

double get_y(double x) {
  return -(a * x + c) / b;
}

double e_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double m_dist(double x1, double y1, double x2, double y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(12);

  double x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

  double ans = m_dist(x1, y1, x2, y2);

  if (a != 0 && b != 0) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        double x3, y3;
        if (i) {
          x3 = get_x(y1);
          y3 = y1;
        } else {
          x3 = x1;
          y3 = get_y(x1);
        }
        double x4, y4;
        if (j) {
          x4 = get_x(y2);
          y4 = y2;
        } else {
          x4 = x2;
          y4 = get_y(x2);
        }
        ans = min(ans, m_dist(x1, y1, x3, y3) + e_dist(x3, y3, x4, y4) + m_dist(x4, y4, x2, y2));
      }
    }
  }

  cout << ans << "\n";
}