#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;

#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

long long dot(point a, point b) {
  return a.X * b.X + a.Y * b.Y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n, px, py;
  cin >> n >> px >> py;

  point p = point(px, py);

  double maxi = 0.0, mini = HUGE_VAL;
  vector<point> polygon(n);
  for (auto &v : polygon) {
    int x, y;
    cin >> x >> y;
    v = point(x, y);
    maxi = max(maxi, M_PI * norm(v - p));
  }

  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    point a = polygon[i], b = polygon[j];
    point v = a - b;
    if ((dot(v, a) < dot(v, p)) == (dot(v, p) < dot(v, b))) {
      mini = min(mini, M_PI * cross(v, p - b) * cross(v, p - b) / norm(v));
    } else {
      mini = min(mini, M_PI * min(norm(a - p), norm(b - p)));
    }
  }

  cout << maxi - mini << "\n";
}