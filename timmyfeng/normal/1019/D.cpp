#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define x real()
#define y imag()

long long cross(point u, point v) {
  return (conj(u) * v).y;
}

bool half(point u) {
  return (u.y > 0 || (u.y == 0 && u.x > 0));
}

struct event {
  point v;
  int i, j;
  bool operator<(event oth) {
    if (half(v) == half(oth.v)) {
      return cross(v, oth.v) > 0;
    }
    return half(v) < half(oth.v);
  }
};

const int N = 2001;

point points[N];
int where[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long s;
  cin >> n >> s;
  s *= 2;

  for (int i = 0; i < n; ++i) {
    int xx, yy;
    cin >> xx >> yy;
    points[i] = point(xx, yy);
  }

  sort(points, points + n, [](point a, point b) {
    return make_pair(a.y, a.x) > make_pair(b.y, b.x);
  });

  vector<event> events;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        events.push_back({points[j] - points[i], i, j});
      }
    }
    where[i] = i;
  }
  sort(events.begin(), events.end());

  for (event e : events) {
    swap(points[where[e.i]], points[where[e.j]]);
    swap(where[e.i], where[e.j]);
    point u = points[where[e.i]];
    point v = points[where[e.j]];

    int k = lower_bound(points, points + n, e.v, [&](point a, point b) {
      return cross(b, a - u) < s;
    }) - points;

    if (cross(e.v, points[k] - u) == s) {
      cout << "Yes\n";
      cout << u.x << " " << u.y << "\n";
      cout << v.x << " " << v.y << "\n";
      cout << points[k].x << " " << points[k].y << "\n";
      exit(0);
    }
  }
  cout << "No\n";
}