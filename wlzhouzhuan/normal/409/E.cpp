#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const double eps = 3e-5;
double x;

int main() {
  scanf("%lf", &x);
  for (double h = 1.0; h <= (10.0 + eps); h += 1.0) {
    if (h + eps < x) continue;
    double l = h / sqrt(h * h / (x * x) - 1) * 2.0;
    for (double q = 1.0; q <= (10.0 + eps); q += 1.0) {
      if (l - q < eps && q - l < eps) {
        printf("%.0lf %.0lf\n", q, h);
        exit(0);
      }
    }
  }
  return 0;
}