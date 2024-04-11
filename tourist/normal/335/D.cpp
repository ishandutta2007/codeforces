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

const int n = 3000;
const int N = n+10;
const int M = 100010;

int a[N][N], shcut[N][N], svcut[N][N], s[N][N];
bool hcut[N][N], vcut[N][N];
int stx[N], sty[N];
bool mark[M];
int ans[M];

int main() {
  int m;
  scanf("%d", &m);
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) a[i][j] = 0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) hcut[i][j] = false;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) vcut[i][j] = false;
  for (int i=1;i<=m;i++) {
    int xa, ya, xb, yb;
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    for (int x=xa+1;x<=xb;x++)
      for (int y=ya+1;y<=yb;y++) a[x][y] = i;
    for (int x=xa+1;x<=xb-1;x++)
      for (int y=ya+1;y<=yb;y++) hcut[x][y] = true;
    for (int x=xa+1;x<=xb;x++)
      for (int y=ya+1;y<=yb-1;y++) vcut[x][y] = true;
  }
  for (int i=0;i<=n;i++) {
    shcut[i][n] = 0;
    for (int j=n-1;j>=0;j--)
      if (hcut[i][j + 1]) shcut[i][j] = 0;
      else shcut[i][j] = shcut[i][j+1] + 1;
  }
  for (int j=0;j<=n;j++) {
    svcut[n][j] = 0;
    for (int i=n-1;i>=0;i--)
      if (vcut[i + 1][j]) svcut[i][j] = 0;
      else svcut[i][j] = svcut[i+1][j] + 1;
  }
  for (int i=n+1;i>=1;i--)
    for (int j=n+1;j>=1;j--)
      if (i > n || j > n) s[i][j] = 0; else
      if (a[i][j] == 0) s[i][j] = 0; else {
        s[i][j] = s[i+1][j+1];
        if (s[i][j+1] < s[i][j]) s[i][j] = s[i][j+1];
        if (s[i+1][j] < s[i][j]) s[i][j] = s[i+1][j];
        s[i][j]++;
      }
  for (int ys=1;ys<=2*n-1;ys++) {
    int e = 0;
    int x = n, y = ys;
    while (y > n) {
      x--; y--;
    }
    while (x > 0 && y > 0) {
      e++;
      stx[e] = x;
      sty[e] = y;
      int mx = s[x][y];
      if (shcut[x-1][y-1] < mx) mx = shcut[x-1][y-1];
      if (svcut[x-1][y-1] < mx) mx = svcut[x-1][y-1];
      while (e > 0 && stx[e] - x + 1 <= mx) {
        int side = stx[e] - x + 1;
        if (shcut[stx[e]][y-1] >= side && svcut[x-1][sty[e]] >= side) {
          for (int i=1;i<=m;i++) mark[i] = false;
          for (int xx=x;xx<=stx[e];xx++)
            for (int yy=y;yy<=sty[e];yy++) mark[a[xx][yy]] = true;
          int ka = 0;
          for (int i=1;i<=m;i++)
            if (mark[i]) ans[ka++] = i;
          printf("YES %d\n", ka);
          for (int i=0;i<ka-1;i++) printf("%d ", ans[i]);
          printf("%d\n", ans[ka-1]);
          return 0;
        }
        else e--;
      }
      x--; y--;
    }
  }
  printf("NO\n");
  return 0;
}