#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>

using namespace std;

const int inf = 1001001001;
const int N = 44444;
const int NN = 4444;

int n, i, j, e;
int xa[N], ya[N], xb[N], yb[N], xl[N], xr[N], yl[N], yr[N], x[N], y[N];
char a[NN][NN];
int qx[NN*NN], qy[NN*NN];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d", &n);
  int xx = 0, yy = 0;
  for (i=0;i<n;i++) {
    char ch = getchar();
    while (ch < 'A' || ch > 'Z') ch = getchar();
    int len;
    scanf("%d", &len);
    xa[i] = xx; ya[i] = yy;
    if (ch == 'L') xx -= len; else
    if (ch == 'R') xx += len; else
    if (ch == 'U') yy += len;
    else yy -= len;
    xb[i] = xx; yb[i] = yy;
    if (xa[i] > xb[i]) { int tmp = xa[i]; xa[i] = xb[i]; xb[i] = tmp; }
    if (ya[i] > yb[i]) { int tmp = ya[i]; ya[i] = yb[i]; yb[i] = tmp; }
  }

  int kx = 0;
  for (i=0;i<n;i++) {
    x[kx++] = xa[i];
    x[kx++] = xb[i];
  }
  sort(x, x+kx);
  x[kx] = inf+1;
  int xn = 1;
  xl[0] = -inf;
  xr[0] = x[0]-1;
  for (i=0;i<kx;i++) {
    if (x[i] == x[i+1]) continue;
    xl[xn] = x[i];
    xr[xn++] = x[i];
    if (x[i]+1 < x[i+1]) {
      xl[xn] = x[i]+1;
      xr[xn++] = x[i+1]-1;
    }
  }
  
  int ky = 0;
  for (i=0;i<n;i++) {
    y[ky++] = ya[i];
    y[ky++] = yb[i];
  }
  sort(y, y+ky);
  y[ky] = inf+1;
  int yn = 1;
  yl[0] = -inf;
  yr[0] = y[0]-1;
  for (i=0;i<ky;i++) {
    if (y[i] == y[i+1]) continue;
    yl[yn] = y[i];
    yr[yn++] = y[i];
    if (y[i]+1 < y[i+1]) {
      yl[yn] = y[i]+1;
      yr[yn++] = y[i+1]-1;
    }
  }

//  cout << xn << " " << yn << endl;
//  for (i=0;i<xn;i++) cout << " " << xl[i] << " " << xr[i] << endl;
//  for (i=0;i<yn;i++) cout << "   " << yl[i] << " " << yr[i] << endl;

  memset(a, 0, sizeof(a));
  for (i=0;i<n;i++) {
    int xs = -1, xf = -1;
    for (j=0;j<xn;j++)
      if (xl[j] >= xa[i] && xr[j] <= xb[i]) {
        if (xs == -1) xs = j;
        xf = j;
      }

    int ys = -1, yf = -1;
    for (j=0;j<yn;j++)
      if (yl[j] >= ya[i] && yr[j] <= yb[i]) {
        if (ys == -1) ys = j;
        yf = j;
      }

    for (int qx=xs;qx<=xf;qx++)
      for (int qy=ys;qy<=yf;qy++) a[qx][qy] = 1;
  }

  i = 1; e = 1;
  qx[1] = 0;
  qy[1] = 0;
  a[0][0] = 2;
  while (i <= e) {
    for (int sx=-1;sx<=1;sx++)
      for (int sy=-1;sy<=1;sy++) {
        if (sx != 0 && sy != 0) continue;
        if (sx == 0 && sy == 0) continue;
        int xk = qx[i]+sx, yk = qy[i]+sy;
        if (xk >= 0 && yk >= 0 && xk < xn && yk < yn)
          if (a[xk][yk] == 0) {
            e++;
            qx[e] = xk;
            qy[e] = yk;
            a[xk][yk] = 2;
          }
      }
    i++;
  }

  long long ans = 0;
  for (i=0;i<xn;i++)
    for (j=0;j<yn;j++)
      if (a[i][j] < 2) ans += (long long)(xr[i]-xl[i]+1)*(yr[j]-yl[j]+1);
  cout << ans << endl;
  
  return 0;
}