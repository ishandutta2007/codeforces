#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

const int N = 2'000;

long long dist[N];
point points[N];
bool dead[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  point center;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = point(x * n, y * n);
    center += point(x, y);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (!dead[i] && !dead[j]) {
        point u = 2LL * center - points[i] - points[j];
        if (u.X == 0 && u.Y == 0) {
          dead[i] = true;
          dead[j] = true;
        }
      }
    }
  }

  int m = count(dead, dead + n, false);
  if (m == 0) {
    cout << -1 << "\n";
    exit(0);
  }

  int pivot = 0;
  while (dead[pivot]) {
    ++pivot;
  }

  vector<point> angles;
  for (int i = 0; i < n; ++i) {
    if (!dead[i] && (i != pivot || m % 2 == 1)) {
      point vec = 2LL * center - points[i] - points[pivot];

      bool ok = true;
      for (auto j : angles) {
        ok &= (cross(vec, j) != 0);
      }

      for (int i = 0; i < n; ++i) {
        dist[i] = cross(vec, points[i]);
      }
      sort(dist, dist + n);

      for (int i = 0; i < n; ++i) {
        ok &= (dist[i] + dist[n - 1 - i] - 2 * cross(vec, center) == 0);
      }

      if (ok) {
        angles.push_back(vec);
      }
    }
  }

  cout << angles.size() << "\n";
}