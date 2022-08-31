#include <bits/stdc++.h>

using namespace std;

void solve(long double a, long double b, long double c, long double d, long double &from, long double &to) {
  vector <long double> z;
  z.push_back(a * c);
  z.push_back(a * d);
  z.push_back(b * c);
  z.push_back(b * d);
  sort(z.begin(), z.end());
  from = z[0];
  to = z[3];
}

int main() {
  long long a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  long double low = 0, high = 1e10;
  for (int it = 0; it < 200; it++) {
    long double x = 0.5 * (low + high);
    long double h1, h2;
    solve(a - x, a + x, d - x, d + x, h1, h2);
    long double v1, v2;
    solve(b - x, b + x, c - x, c + x, v1, v2);
    if (v1 > h2 || h1 > v2) {
      low = x;
    } else {
      high = x;
    }
  }
  printf("%.17f\n", (double) (0.5 * (low + high)));
  return 0;
}