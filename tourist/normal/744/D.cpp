#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);

const int N = 1234;

int xr[N], yr[N], xb[N], yb[N];
int x[2 * N], y[2 * N];
double d[2 * N][2 * N];
double a[2 * N][2 * N];
pair <double, int> e[4 * N];

inline double norm(double x) {
  if (x < 0) x += 2 * pi;
  if (x >= 2 * pi) x -= 2 * pi;
  return x;
}

int main() {
  int nr, nb;
  scanf("%d %d", &nr, &nb);
  int n = nr + nb;
  for (int i = 0; i < nr; i++) {
    scanf("%d %d", xr + i, yr + i);
    x[i] = xr[i];
    y[i] = yr[i];
  }
  for (int i = 0; i < nb; i++) {
    scanf("%d %d", xb + i, yb + i);
    x[nr + i] = xb[i];
    y[nr + i] = yb[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      if (i != j) {
        a[i][j] = norm(atan2(y[j] - y[i], x[j] - x[i]));
      }
    }
  }
  double ans = 1.0;
  for (int i = 0; i < n; i++) {
    bool err = false;
    double low = ans, high = 1e13;
    for (int it = -1; it < 20; it++) {
      double dd = (it == -1 ? ans : sqrt(low * high));
      double qd = 1.0 / dd;
      bool found = false;
      int ne = 0;
      int good = 0;
      int bad = 0;
      if (i < nr) {
        good++;
      }
      for (int j = 0; j < n; j++) {
        if (i == j || d[i][j] >= dd) {
          continue;
        }
        double cs = d[i][j] * qd;
        if (cs >= 1.0) {
          continue;
        }
        double shift = acos(cs);
        double from = norm(a[i][j] - shift);
        double to = norm(a[i][j] + shift);
        e[ne++] = make_pair(from, j < nr ? 2 : 1);
        e[ne++] = make_pair(to, j < nr ? -2 : -1);
        if (from > to) {
          if (j < nr) {
            good++;
          } else {
            bad++;
          }
        }
      }
      sort(e, e + ne);
      for (int i = 0; i <= ne; i++) {
        if (good > 0 && bad == 0) {
          found = true;
          break;
        }
        if (i == ne) {
          break;
        }
        int type = e[i].second;
        switch (type) {
          case 1:  { bad++; break; }
          case -1: { bad--; break; }
          case 2:  { good++; break; }
          case -2: { good--; break; }
        }
      }
      if (it == -1 && !found) {
        err = true;
        break;
      }
      if (found) {
        low = dd;
      } else {
        high = dd;
      }
    }
    if (!err) {
      ans = max(ans, sqrt(low * high));
    }
    if (ans > 9e12) {
      break;
    }
  }
  if (ans > 9e12) {
    printf("%d\n", -1);
  } else {
    printf("%.15f\n", 0.5 * ans);
  }
  cerr << clock() << " ms" << endl;
  return 0;
}