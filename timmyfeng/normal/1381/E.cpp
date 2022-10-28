#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define X real()
#define Y imag()

double cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

point midpoint(point a, point b, point c) {
  point p = (b * (c.Y - a.Y) + c * (a.Y - b.Y)) / (c.Y - b.Y);
  return (a + p) / 2.0;
}

struct event {

  double x, d;
  int i;

  bool operator<(event oth) const {
    return x < oth.x;
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(6);

  int n, q;
  cin >> n >> q;

  vector<point> polygon(n);
  for (auto &i : polygon) {
    int x, y;
    cin >> x >> y;
    i = point(x, y);
  }

  int low = 0;
  for (int i = 1; i < n; ++i) {
    if (polygon[i].Y < polygon[low].Y) {
      low = i;
    }
  }
  rotate(polygon.begin(), polygon.begin() + low, polygon.end());

  vector<point> divide;
  int l = 0, r = 0;
  do {
    if (polygon[l].Y == polygon[r].Y) {
      divide.push_back((polygon[l] + polygon[r]) / 2.0);
      r = (r + n - 1) % n;
      l = (l + 1) % n;
    } else if (polygon[l].Y < polygon[r].Y) {
      divide.push_back(midpoint(polygon[l], polygon[(r + 1) % n], polygon[r]));
      l = (l + 1) % n;
    } else {
      divide.push_back(midpoint(polygon[r], polygon[(l + n - 1) % n], polygon[l]));
      r = (r + n - 1) % n;
    }
  } while (l != r);
  divide.push_back(polygon[l]);

  double area = 0.0;
  vector<event> events;
  for (int i = 0; i < n; ++i) {
    point a = polygon[i];
    point b = polygon[(i + 1) % n];
    point v = b - a;
    if (v.X == 0.0) {
      events.push_back({a.X, -abs(v.Y), -2});
    } else {
      events.push_back({min(a.X, b.X), -abs(v.Y / v.X), -1});
      events.push_back({max(a.X, b.X), abs(v.Y / v.X), -1});
    }
    area += cross(a, b);
  }
  area = abs(area / 2.0);

  for (int i = 1; i < (int) divide.size(); ++i) {
    point a = divide[i - 1];
    point b = divide[i];
    point v = b - a;
    if (v.X == 0.0) {
      events.push_back({a.X, 2.0 * abs(v.Y), -2});
    } else {
      events.push_back({min(a.X, b.X), 2.0 * abs(v.Y / v.X), -1});
      events.push_back({max(a.X, b.X), -2.0 * abs(v.Y / v.X), -1});
    }
  }

  for (int i = 0; i < q; ++i) {
    double f;
    cin >> f;
    events.push_back({f, 0.0, i});
  }
  sort(events.begin(), events.end());

  vector<double> ans(q);
  double delta = 0.0, length = 0.0, x = events[0].x;
  for (auto e : events) {
    area += (delta * (e.x - x) / 2.0 + length) * (e.x - x);
    length += delta * (e.x - x);
    x = e.x;

    if (e.i == -2) {
      length += e.d;
    } else if (e.i == -1) {
      delta += e.d;
    } else {
      ans[e.i] = area;
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}