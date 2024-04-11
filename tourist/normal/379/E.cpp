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
#include <memory.h>

using namespace std;

const int MAX = 5005;
const int N = 610;
const int NN = 123456;
const double eps = 1e-10;

int py[N][N];
double x[NN], y[NN], xx[NN], yy[NN], ans[NN];

int main() {
  int cnt, width;
  scanf("%d %d", &cnt, &width);
  for (int i = 0; i < cnt; i++)
    for (int j = 0; j <= width; j++) scanf("%d", py[i] + j);
  for (int i = 0; i < cnt; i++) ans[i] = 0.0;
  for (int w = 0; w < width; w++) {
    int n = 4;
    x[0] = 0; y[0] = MAX;
    x[1] = 0; y[1] = 0;
    x[2] = 1; y[2] = 0;
    x[3] = 1; y[3] = MAX;
    double old_area = 0.0;
    for (int id = 0; id < cnt; id++) {
      int xa = 0, ya = py[id][w];
      int xb = 1, yb = py[id][w + 1];
      int a = yb - ya;
      int b = xa - xb;
      int c = -a * xa - b * ya;
      int nn = 0;
      for (int i = 0; i < n; i++) {
        double z = a * x[i] + b * y[i] + c;
        if (z < eps) {
          xx[nn] = x[i];
          yy[nn] = y[i];
          nn++;
        }
        if (i < n - 1) {
          double zz = a * x[i + 1] + b * y[i + 1] + c;
          if ((z < -eps && zz > eps) || (zz < -eps && z > eps)) {
            double aa = y[i + 1] - y[i];
            double bb = x[i] - x[i + 1];
            double cc = -aa * x[i] - bb * y[i];
            double d = a * bb - b * aa;
            double dx = (b * cc - c * bb) / d;
            double dy = (c * aa - a * cc) / d;
            xx[nn] = dx;
            yy[nn] = dy;
            nn++;
          }
        }
      }
      n = nn;
      for (int i = 0; i < n; i++) {
        x[i] = xx[i];
        y[i] = yy[i];
      }
      double area = 0.0;
      for (int i = 0; i < n - 1; i++) area += (x[i + 1] - x[i]) * (y[i + 1] + y[i]);
      area *= 0.5;
      ans[id] += area - old_area;
      old_area = area;
    }
  }
  for (int i = 0; i < cnt; i++) printf("%.17lf\n", ans[i]);
  return 0;
}