#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define x real()
#define y imag()

const int N = 1e5;
const double P = 1.5e6;
const double E = 1e-9;

double dot(point u, point v) {
  return (conj(u) * v).x;
}

double cross(point u, point v) {
  return (conj(u) * v).y;
}

struct cmp {
  int half(point u) const {
    return u.y > 0 || (u.y == 0 && u.x > 0);
  }

  bool operator()(pair<point, int> u, pair<point, int> v) const {
    return make_tuple(half(u.first), 0, u.second) < make_tuple(half(v.first), cross(u.first, v.first), v.second);
  }
};

int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  set<pair<point, int>, cmp> points;
  for (int i = 0; i < n; ++i) {
    int xx, yy;
    cin >> xx >> yy;
    ans[i] = 1;
    if (xx != 0 || yy != 0) {
      points.emplace(point(xx, yy), i);
    }
  }

  point vec;
  for (auto [v, i] : points) {
    vec += v;
  }

  while (dot(vec, vec) + E > P * P) {
    auto it = points.lower_bound(make_pair(vec, 0));
    if (it == points.end()) {
      it = points.begin();
    }

    auto [v, i] = *it;
    points.erase(it);
    points.emplace(-v, i);
    ans[i] = -ans[i];
    vec -= 2.0 * v;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}