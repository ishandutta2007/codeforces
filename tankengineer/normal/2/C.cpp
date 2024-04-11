//CF 2C
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

double x[5], y[5], r[5], a[5], b[5], c[5], cx, cy, cxs[3], cys[3], cr[3], ta, tb, tc, td, t1, t2, t3, t4;

inline double sq(double a) {return a * a;}

int main() {
  for (int i = 1; i <= 3; i++) {
    scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
  }
  
  if (r[1] == r[2] && r[2] == r[3]) {
    //Two lines
    for (int i = 1; i <= 2; i++) {
      a[i] = x[i] - x[i + 1];
      b[i] = y[i] - y[i + 1];
      c[i] = - (x[i] * x[i] + y[i] * y[i] - x[i + 1] * x[i + 1] - y[i + 1] * y[i + 1]) / 2;
    }
    cx = (c[1] * b[2] - c[2] * b[1]) / (a[2] * b[1] - a[1] * b[2]);
    cy = (c[2] * a[1] - c[1] * a[2]) / (a[2] * b[1] - a[1] * b[2]);
    printf("%.5lf %.5lf\n", cx, cy);
    
  } else {
    if (r[1] == r[2]) {
      swap(r[1], r[3]);
      swap(x[1], x[3]);
      swap(y[1], y[3]);
    } else if (r[1] == r[3]) {
      swap(x[1], x[2]);
      swap(y[1], y[2]);
      swap(r[1], r[2]);
    }
    //Two cycles
    for (int i = 2; i <= 3; i++) {
      ta = r[1] * r[1] - r[i] * r[i];
      tb = 2 * (r[1] * r[1] * x[i] - r[i] * r[i] * x[1]) / ta;
      tc = 2 * (r[1] * r[1] * y[i] - r[i] * r[i] * y[1]) / ta;
      td = (r[1] * r[1] * x[i] * x[i] + r[1] * r[1] * y[i] * y[i] - r[i] * r[i] * x[1] * x[1] - r[i] * r[i] * y[1] * y[1]) / ta;
      cxs[i - 1] = tb / 2;
      cys[i - 1] = tc / 2;
      if (-td + sq(tb) / 4 + sq(tc) / 4 < 0) return 0;
      cr[i - 1] = sqrt(-td + (tb * tb) / 4 + (tc * tc) / 4);
    }
    ta = sqrt(sq(cxs[2] - cxs[1]) + sq(cys[2] - cys[1]));
    if (ta > cr[1] + cr[2]) return 0;
    if (cr[1] + cr[2] - ta < 1e-7) {
      cx = (cxs[1] * cr[2] + cxs[2] * cr[1]) / (cr[1] + cr[2]);
      cy = (cys[1] * cr[2] + cys[2] * cr[1]) / (cr[1] + cr[2]);
      printf("%.5lf %.5lf\n", cx, cy);
    } else {
      a[1] = cys[1] - cys[2];
      b[1] = cxs[2] - cxs[1];
      c[1] = cxs[1] * cys[2] - cxs[2] * cys[1];
      a[2] = -2 * cxs[1] + 2 * cxs[2];
      b[2] = -2 * cys[1] + 2 * cys[2];
      c[2] = -(sq(cr[1]) - sq(cr[2]) - sq(cxs[1]) - sq(cys[1]) + sq(cxs[2]) + sq(cys[2]));
      cx = (c[1] * b[2] - c[2] * b[1]) / (a[2] * b[1] - b[2] * a[1]);
      cy = (c[2] * a[1] - c[1] * a[2]) / (a[2] * b[1] - b[2] * a[1]);
      if (sq(cr[1]) < sq(cx - cxs[1]) + sq(cy - cys[1])) return 0;
      ta = sqrt(sq(cr[1]) - sq(cx - cxs[1]) - sq(cy - cys[1]));
      tb = atan2(a[2], -b[2]);
      tc = cx + ta * cos(tb);
      td = cy + ta * sin(tb);
      t1 = asin(r[2] / sqrt(sq(x[2] - tc) + sq(y[2] - td)));
      t2 = cx - ta * cos(tb);
      t3 = cy - ta * sin(tb);
      t4 = asin(r[2] / sqrt(sq(x[2] - t2) + sq(y[2] - t3)));
      if (t4 > t1) {
        tc = t2;
        td = t3;
      }
      printf("%.5lf %.5lf\n", tc, td);
    }
  }
    
  return 0;
}