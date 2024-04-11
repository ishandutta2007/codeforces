#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
const int N = 1'000;

point points[N];

long long cross(point a, point b) {
  return (conj(a) * b).imag();
}

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

  double ans = 4e9;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = min(ans, sqrt(norm(points[i] - points[j])));
    }
  }

  for (int i = 0; i < n; ++i) {
    int prv = (i == 0 ? n - 1 : i - 1);
    int nxt = (i == n - 1 ? 0 : i + 1);
    ans = min(ans, abs(cross(points[nxt] - points[i], points[prv] - points[i])) / sqrt(norm(points[prv] - points[nxt])) / 2);
  }

  cout << fixed << setprecision(12) << ans << "\n";
}