#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define X real()
#define Y imag()

double cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

const int N = 100000 + 2;

point points[N], hull[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n, p, q;
  cin >> n >> p >> q;
  point target(p, q);

  int max_x = 0, max_y = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    max_x = max(max_x, x);
    max_y = max(max_y, y);
    points[i] = point(x, y);
  }

  points[n] = point(0, max_y);
  sort(points, points + n + 1, [](point a, point b) {
    return a.X < b.X;
  });

  int m = 0;
  for (int i = 0; i < n + 1; ++i) {
    while (m >= 2) {
      point prv = hull[m - 2];
      point cur = hull[m - 1];
      if (cross(cur - prv, points[i] - cur) < 0) {
        break;
      }
      --m;
    }
    hull[m++] = points[i];
  }
  hull[m++] = point(max_x, 0);

  int v = 0;
  for ( ; cross(hull[v], target) < 0; ++v);
  point slope = hull[v] - hull[v - 1];
  point intersect = cross(slope, hull[v]) * target / cross(slope, target);

  cout << q / intersect.Y << "\n";
}