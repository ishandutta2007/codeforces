#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

const int N = 300;

int under[N][N];
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

  sort(points, points + n, [&](point a, point b) {
    if (a.X == b.X) {
      return a.Y < b.Y;
    }
    return a.X < b.X;
  });

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        under[i][k] += (cross(points[j] - points[i], points[k] - points[i]) > 0);
      }
    }
  }

  long long ans = 2;

  for (int i = 0; i < 5; ++i) {
    ans *= n - i;
    ans /= i + 1;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int inside = abs(under[i][k] - under[i][j] - under[j][k] - (cross(points[j] - points[i], points[k] - points[i]) > 0));
        ans -= inside * (n - inside - 3);
      }
    }
  }

  cout << ans / 2 << "\n";
}