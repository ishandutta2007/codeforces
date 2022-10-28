#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define X real()
#define Y imag()

const double E = 1e-12;
const int N = 2000;

point v[N];
int c[N];

struct epsilon_compare {

  bool operator()(double a, double b) const {
    return a + E < b;
  }

};

double cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

double dot(point a, point b) {
  return a.X * b.X + a.Y * b.Y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b >> c[i];
    v[i] = point(-b, a);
  }

  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    map<double, int, epsilon_compare> positive, negative;

    for (int j = 0; j < n; ++j) {
      if (j == i) {
        continue;
      }

      if (cross(v[i], v[j]) < 0) {
        v[j] *= -1, c[j] *= -1;
      }

      point p = ((double) c[i] * v[j] - (double) c[j] * v[i]) / cross(v[i], v[j]);
      double theta = acos(dot(p, v[j]) / abs(p) / abs(v[j]));

      if (c[j] == 0) {
        if (abs(p) <= E && i < j) {
          ans += n - 2;
        }
      } else if (c[j] < 0) {
        ++negative[theta];
      } else {
        ++positive[theta];
      }
    }

    for (auto [theta, x] : positive) {
      ans += x * negative[M_PI - theta];
    }
  }

  cout << ans << "\n";
}