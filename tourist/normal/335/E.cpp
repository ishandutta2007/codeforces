#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <memory.h>

using namespace std;

double f[33333][33], s[33333][33];
double prob[33], sp[33];

int main() {
  char foo[42];
  scanf("%s", foo);
  int n, h;
  scanf("%d %d", &n, &h);
  if (foo[0] == 'A') {
    prob[0] = 0.5;
    for (int j=1;j<=h;j++) prob[j] = prob[j-1] * 0.5;
    prob[h] *= 2;
    f[0][0] = 1.0;
    s[0][0] = 0.0;
    for (int i=0;i<n;i++)
      for (int j=0;j<=h;j++) {
        for (int q=0;q<=h;q++) {
          double ft = f[i][j] * prob[q];
          double st = s[i][j] * prob[q];
          if (ft < 1e-100) ft = 0.0;
          if (q < j) {
            f[i + 1][j] += ft;
            s[i + 1][j] += st;
          } else
          if (q == j) {
            f[i + 1][j] += ft;
            s[i + 1][j] += st + (1 << j) * ft;
          } else {
            f[i + 1][q] += ft;
            s[i + 1][q] += st + (1 << j) * ft;
          }
        }
      }
    sp[h] = prob[h];
    for (int i=h-1;i>=0;i--) sp[i] = prob[i] + sp[i+1];
    double ans = 0.0, tp = 0.0;
    for (int i=1;i<=n;i++) {
      for (int q=0;q<h;q++) {
        for (int oq=0;oq<=h;oq++) {
          int j = oq;
          if (q+1 > j) j = q+1;
          double p = f[n - i][oq] * f[i - 1][q] * sp[j];
          if (p > 1e-50) {
            double s1 = s[n - i][oq] / f[n - i][oq];
            double s2 = s[i - 1][q] / f[i - 1][q];
            ans += (s1 + s2 + (1 << q) + (1 << oq) - 1) * p;
            tp += p;
          }
        }
      }
    }
    double lastp = 1.0;
    for (int i=0;i<n;i++) {
      lastp *= prob[0];
      if (lastp < 1e-50) lastp = 0.0;
    }
    ans += lastp * n;
    tp += lastp;
    printf("%.17lf\n", ans);
  } else {
    printf("%d\n", n);
  }
  return 0;
}