#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
  T, __gnu_pbds::null_type, Comp,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;

using point = complex<long double>;
#define X real()
#define Y imag()

long double dot(point a, point b) {
  return a.X * b.X + a.Y * b.Y;
}

long double cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

point perp(point a) {
  return point(-a.Y, a.X);
}

const int N = 50000;

long double c[N];
int where[N], n;
point v[N], o;

pair<long long, long double> calc(long double r, bool get) {
  vector<pair<point, int>> circle;
  for (int i = 0; i < n; ++i) {
    long double d = cross(v[i], o) - c[i];
    if (d * d / dot(v[i], v[i]) <= r * r) {
      point p = o - perp(v[i]) * d / dot(v[i], v[i]);
      long double q = sqrt(r * r - d * d / dot(v[i], v[i]));
      circle.emplace_back(p + v[i] / abs(v[i]) * q, i);
      circle.emplace_back(p - v[i] / abs(v[i]) * q, i);
    }
  }

  sort(circle.begin(), circle.end(), [&](auto a, auto b) {
    point u = a.first, v = b.first;
    if ((u.Y < o.Y) == (v.Y < o.Y)) {
      if (u.Y < o.Y) {
        return u.X < v.X;
      } else {
        return u.X > v.X;
      }
    } else {
      return (u.Y < o.Y) < (v.Y < o.Y);
    }
  });

  ordered_set<array<int, 2>> points;
  fill(where, where + n, -1);

  long double sum = 0.0;
  long long count = 0;

  for (int i = 0; i < (int) circle.size(); ++i) {
    auto [p, a] = circle[i];
    if (where[a] == -1) {
      points.insert({i, a});
      where[a] = i;
    } else {
      points.erase({where[a], a});
      count += points.size() - points.order_of_key({where[a], a});
      if (get) {
        auto it = points.lower_bound({where[a], a});
        while (it != points.end()) {
          int b = (*it)[1];
          point x = (c[a] * v[b] - c[b] * v[a]) / cross(v[a], v[b]);
          sum += abs(x - o);
          ++it;
        }
      }
    }
  }

  return {count, sum};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int ox, oy, m;
  cin >> n >> ox >> oy >> m;

  o = point(ox / 1000.0, oy / 1000.0);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    c[i] = b / 1000.0;
    v[i] = point(1, a / 1000.0);
  }

  long double lo = 0.0, hi = 1e10;
  for (int i = 0; i < 64; ++i) {
    long double r = (lo + hi) / 2;
    (calc(r, false).first < m ? lo : hi) = r;
  }

  auto [count, sum] = calc(lo, true);
  cout << sum - (count - m) * lo << "\n";
}