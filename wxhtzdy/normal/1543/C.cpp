/**
 *    author:  milos
 *    created: 03.09.2021 19:16:06       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
double eps = 1e-13;

double f(double a, double b, double c, double d, double x, int i) {
  double ans = x * c * i;
  if (a >= eps) {
    double nb = (b >= eps ? b + min(a, d) / 2 : 0);
    double nc = (b >= eps ? c + min(a, d) / 2 : c + min(a, d));
    ans += f(a - min(a, d), nb, nc, d, x * a, i + 1);
  }
  swap(a, b);
  if (a >= eps) {
    double nb = (b >= eps ? b + min(a, d) / 2 : 0);
    double nc = (b >= eps ? c + min(a, d) / 2 : c + min(a, d));
    ans += f(a - min(a, d), nb, nc, d, x * a, i + 1);
  }
  return ans;  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(10) << f(a, b, c, d, 1, 1) << '\n';
  }
  return 0;
}