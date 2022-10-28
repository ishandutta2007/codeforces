#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int B = 64;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

long long bound(point v) {
  return abs(__gcd(v.X, v.Y));
}

double power[N], prob[B];
point p[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(11);

  power[0] = 1;
  for (int i = 1; i < N; ++i) {
    power[i] = power[i - 1] / 2;
  }

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = point(x, y);
  }

  for (int i = 1; i < min(n, B); ++i) {
    prob[i] = (power[i + 1] - power[n]) / (1 - power[n] * (1 + n + n * (n - 1) / 2));
  }

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    long long area = 0, edge = 0;
    for (int j = 1; j < min(n, B); ++j) {
      int u = (i + j - 1) % n, v = (i + j) % n;
      area += cross(p[u], p[v]);
      edge += bound(p[u] - p[v]);
      ans -= prob[j] * (abs(area + cross(p[v], p[i])) + edge + bound(p[v] - p[i])) / 2;
    }
  }

  long long area = 0, edge = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    area += cross(p[i], p[j]);
    edge += bound(p[i] - p[j]);
  }
  ans += (abs(area) + edge) / 2 + 1;

  cout << ans << "\n";
}