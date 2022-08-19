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

const int N = 256;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int hx[N], hy[N];
char c[N][N];
int cost[N][N];
int dd[27][N][N], px[27][N][N], py[27][N][N];
int ppx[1111111], ppy[1111111];
int n, m, k, i, j, e, xs, ys, xf, yf;
int x[1111111], y[1111111];
char ch, s[11111];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d %d %d", &n, &m, &k);
  memset(hx, 0, sizeof(hx));
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {
      c[i][j] = getchar();
      while (c[i][j] != '#' && (c[i][j] < '0' || c[i][j] > '9') && (c[i][j] < 'a' || c[i][j] > 'z')) c[i][j] = getchar();
      if (c[i][j] >= 'a' && c[i][j] <= 'z') {
        hx[c[i][j]] = i;
        hy[c[i][j]] = j;
      }
      if (c[i][j] >= '1' && c[i][j] <= '9') cost[i][j] = c[i][j]-'0';
      else cost[i][j] = 1;
    }
  for (ch='a';ch<='z';ch++) {
    if (!hx[ch]) continue;
    x[1] = hx[ch];
    y[1] = hy[ch];
    int w = ch-'a';
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++) dd[w][i][j] = (int)1e9;
    dd[w][x[1]][y[1]] = 0;
    i = 1; e = 1;
    while (i <= e) {
      if (i > 1 && c[x[i]][y[i]] >= 'a' && c[x[i]][y[i]] <= 'z') ; else {
        for (j=0;j<4;j++) {
          int xk = x[i]+dx[j], yk = y[i]+dy[j];
          if (xk >= 1 && yk >= 1 && xk <= n && yk <= m)
            if (c[xk][yk] != '#') {
              int dt = dd[w][x[i]][y[i]] + cost[x[i]][y[i]];
              if (dt < dd[w][xk][yk]) {
                e++;
                x[e] = xk;
                y[e] = yk;
                px[w][xk][yk] = x[i];
                py[w][xk][yk] = y[i];
                dd[w][xk][yk] = dt;
              }
            }
        }
      }
      i++;
    }
  }
  scanf("%d %d", &xs, &ys);
  scanf("%s", s);
  scanf("%d %d", &xf, &yf);
  for (i=0; s[i]; i++) {
    int xg = hx[s[i]], yg = hy[s[i]], w = s[i]-'a';
    while (xs != xg || ys != yg) {
      if (k < cost[xs][ys]) {
        printf("%d %d\n", xs, ys);
        return 0;
      }
      k -= cost[xs][ys];
      int nx = px[w][xs][ys], ny = py[w][xs][ys];
      xs = nx, ys = ny;
    }
  }
  int kp = 0;
  int xg = hx[s[i-1]], yg = hy[s[i-1]], w = s[i-1]-'a';
  xs = xf; ys = yf;
  while (xs != xg || ys != yg) {
    int nx = px[w][xs][ys], ny = py[w][xs][ys];
    xs = nx, ys = ny;
    ppx[kp] = xs;
    ppy[kp] = ys;
    kp++;
  }
  for (i=kp-1;i>=0;i--) {
    if (k < cost[ppx[i]][ppy[i]]) {
      printf("%d %d\n", ppx[i], ppy[i]);
      return 0;
    }
    k -= cost[ppx[i]][ppy[i]];
  }
  printf("%d %d\n", xf, yf);
  return 0;
}