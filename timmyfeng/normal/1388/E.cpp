#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define x real()
#define y imag()

long long cross(point p, point q) {
  return (conj(p) * q).y;
}

double projection(point p, point v) { 
  return p.x - p.y * (1.0 * v.x / v.y);
}

struct event {
  point angle;
  int type, i, j;
  bool operator<(event oth) {
    return cross(angle, oth.angle) > 0;
  }
};

struct segment {
  point left, right;
  int i;
};

int main() {
  cout << fixed << setprecision(12);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<segment> segments;
  for (int i = 0; i < n; ++i) {
    int xl, xr, yy;
    cin >> xl >> xr >> yy;
    segments.push_back({point(xl, yy), point(xr, yy), i});
  }

  vector<event> events;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (segments[i].left.y > segments[j].left.y) {
        events.push_back({segments[j].left - segments[i].right, 0, i, j});
        events.push_back({segments[j].left - segments[i].left, 1, i, j});
        events.push_back({segments[j].right - segments[i].left, 2, i, j});
      }
    }
  }

  sort(events.begin(), events.end());

  int cnt = 0;
  int cur = 0;
  point angle = events.empty() ? point(0, -1) : events[cur].angle;

  sort(segments.begin(), segments.end(), [&](segment i, segment j) {
    return projection(i.left, angle) < projection(j.left, angle);
  });

  vector<int> where(n);
  for (int i = 0; i < n; ++i) {
    where[segments[i].i] = i;
  }

  double ans = projection(segments[n - 1].right, angle) - projection(segments[0].left, angle);

  while (cur < int(events.size())) {
    int cnt_new = 0;
    angle = events[cur].angle;

    while (cur < int(events.size()) && cross(angle, events[cur].angle) == 0) {
      event e = events[cur];
      if (e.type == 0) {
        cnt_new++;
      } else if (e.type == 1) {
        swap(segments[where[e.i]], segments[where[e.j]]);
        swap(where[e.i], where[e.j]);
      } else {
        --cnt;
      }
      ++cur;
    }

    if (cnt == 0) {
      ans = min(ans, projection(segments[n - 1].right, angle) - projection(segments[0].left, angle));
    }
    cnt += cnt_new;
  }

  cout << ans << "\n";
}