#include <bits/stdc++.h>
using namespace std;

const int R = 500000;
const int N = 100;

double x[N], p[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] = 1.0 - p[i] / 100.0;
    x[i] = 1.0;
  }

  double ans = 0.0;
  for (int i = 0; i < R; ++i) {
    pair<double, int> best = {0.0, -1};
    for (int j = 0; j < n; ++j) {
      best = max(best, make_pair((1 - x[j] * p[j]) / (1 - x[j]), j));
    }
    x[best.second] *= p[best.second];
    
    double product = 1.0;
    for (int j = 0; j < n; ++j) {
      product *= 1.0 - x[j];
    }
    ans -= product;
  }
  ans += R + 1;

  cout << ans << "\n";
}