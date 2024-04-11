#include <cstring>
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
#include <cassert>

using namespace std;

const int N = 4010;

inline double get_dist(double xa, double ya, double xb, double yb) {
  return (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
}

const double eps = 1e-9;

double x[N], y[N];
double xx[N], yy[N];

void cut(int &cnt, double aa, double bb, double cc) {
  x[cnt] = x[0]; y[cnt] = y[0];
  int ncnt = 0;
  for (int i = 0; i < cnt; i++) {
    double z = aa * x[i] + bb * y[i] + cc;
    if (z < eps) {
      xx[ncnt] = x[i];
      yy[ncnt] = y[i];
      ncnt++;
    }
    double zn = aa * x[i + 1] + bb * y[i + 1] + cc;
    if ((z < -eps && zn > eps) || (z > eps && zn < -eps)) {
      double a = y[i + 1] - y[i];
      double b = x[i] - x[i + 1];
      double c = -a * x[i] - b * y[i];
      double d = a * bb - b * aa;
      xx[ncnt] = (b * cc - c * bb) / d;
      yy[ncnt] = (c * aa - a * cc) / d;
      ncnt++;
    }
  }
  cnt = ncnt;
  for (int i = 0; i < cnt; i++) {
    x[i] = xx[i];
    y[i] = yy[i];
  }
}

pair <int, int> p[N];
int weight[N];

double ox[N], oy[N];

int main() {
  int w, h, n;
  scanf("%d %d %d", &w, &h, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p[i].first, &p[i].second);
  }
  sort(p, p + n);
  int nn = 1;
  weight[0] = 1;
  for (int i = 1; i < n; i++) {
    if (p[i] == p[nn - 1]) {
      weight[nn - 1]++;
    } else {
      p[nn] = p[i];
      weight[nn] = 1;
      nn++;
    }
  }
  n = nn;
  double ans = 0.0;
  for (int st = 0; st < n; st++) {
    int cnt = 4;
    x[0] = 0; y[0] = 0;
    x[1] = w; y[1] = 0;
    x[2] = w; y[2] = h;
    x[3] = 0; y[3] = h;
    for (int i = 0; i < n; i++) {
      double aa = p[i].first - p[st].first;
      double bb = p[i].second - p[st].second;
      double cc = -aa * 0.5 * (p[i].first + p[st].first) - bb * 0.5 * (p[i].second + p[st].second);
      cut(cnt, aa, bb, cc);
    }
    if (weight[st] >= 2) {
      for (int i = 0; i < cnt; i++) {
        double dist = get_dist(x[i], y[i], p[st].first, p[st].second);
        if (dist > ans) {
          ans = dist;
        }
      }
      continue;
    }
    x[cnt] = x[0]; y[cnt] = y[0];
    vector <int> pts;
    for (int i = 0; i < cnt; i++) {
      double xm = 0.5 * (x[i] + x[i + 1]);
      double ym = 0.5 * (y[i] + y[i + 1]);
      double mn = 1e20;
      int km = -1;
      for (int j = 0; j < n; j++) {
        if (j == st) {
          continue;
        }
        double cur = get_dist(xm, ym, p[j].first, p[j].second);
        if (cur < mn) {
          mn = cur;
          km = j;
        }
      }
      pts.push_back(km);
    }
    int ocnt = cnt;
    for (int i = 0; i < cnt; i++) {
      ox[i] = x[i];
      oy[i] = y[i];
    }
    int sz = pts.size();
    for (int jj = 0; jj < sz; jj++) {
      int pt = pts[jj];
      cnt = ocnt;
      for (int i = 0; i < cnt; i++) {
        x[i] = ox[i];
        y[i] = oy[i];
      }
      for (int u = 0; u < sz; u++) {
        if (u == jj) {
          continue;
        }
        int i = pts[u];
        double aa = p[i].first - p[pt].first;
        double bb = p[i].second - p[pt].second;
        double cc = -aa * 0.5 * (p[i].first + p[pt].first) - bb * 0.5 * (p[i].second + p[pt].second);
        cut(cnt, aa, bb, cc);
      }
      for (int i = 0; i < cnt; i++) {
        double dist = get_dist(x[i], y[i], p[pt].first, p[pt].second);
        if (dist > ans) {
          ans = dist;
        }
      }
    }
  }
  printf("%.17lf\n", sqrt(ans));
  return 0;
}