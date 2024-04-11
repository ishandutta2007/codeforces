#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long double> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (fabs(p[i] - 1) < 1e-12) {
      cout << fixed << setprecision(20) << p[i] << "\n";
      return 0;
    }
  }
  long double res = 0.0;
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      long double pd = 1.0;
      for (int k = i; k <= j; ++k) pd *= 1 - p[k];
      long double pb = 0.0;
      for (int k = i; k <= j; ++k) pb += p[k] / (1.0 - p[k]);
      res = max(res, pb * pd);
    }
  }
  cout << fixed << setprecision(20) << res << "\n";
}