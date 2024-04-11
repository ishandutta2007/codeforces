#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

bool half(point a) {
  return a.Y > 0 || (a.Y == 0 && a.X < 0);
}

const int N = 2000;

point points[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    points[i] = point(x, y);
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    vector<point> vecs;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        vecs.push_back(points[j] - points[i]);
      }
    }

    sort(vecs.begin(), vecs.end(), [](point a, point b) {
      if (half(a) == half(b)) {
        return cross(a, b) > 0;
      } else {
        return half(a) < half(b);
      }
    });

    for (int j = 0, k = 1; j < n - 1 && !half(vecs[j]); ++j) {
      for ( ; k < n - 1 && cross(vecs[j], vecs[k]) > 0; ++k);
      int l = k - j - 1;
      int r = n - 2 - l;
      ans += (long long) l * (l - 1) * r * (r - 1) / 4;
    }
  }

  cout << ans << "\n";
}