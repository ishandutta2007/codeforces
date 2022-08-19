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

int hl, hr, n, i, k;
int sc[111], xa[111], xb[111], used[111];
char c[111];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d %d %d", &hl, &hr, &n);
  for (i=0;i<n;i++) {
    scanf("%d", sc+i);
    c[i] = getchar();
    while (c[i] != 'T' && c[i] != 'F') c[i] = getchar();
    scanf("%d %d", xa+i, xb+i);
  }
  int ans = 0;
  for (k=-n;k<=n;k++) {
    int xs = 0, xf = 100000;
    int ys = hl, yf = hr;
    if (k & 1) yf = 100-yf;
    yf += k*100;
    long long a = yf-ys, b = xs-xf;
    long long cc = -a*xs-b*ys;
    for (i=0;i<n;i++) used[i] = 0;
    int ok = 1, y;
    if (k > 0) {
      for (y=1;y<=k;y++) {
        int found = 0;
        long long xn = -b*(y*100)-cc, xd = a;
        for (i=0;i<n;i++)
          if (c[i] == 'T' && y % 2 == 1 || c[i] == 'F' && y % 2 == 0) {
            if (xa[i]*xd <= xn && xb[i]*xd >= xn) {
              if (used[i]) ok = 0;
              used[i] = 1;
              found = 1;
              break;
            }
          }
        if (!found) ok = 0;
      }
    } else {
      for (y=0;y>k;y--) {
        int found = 0;
        long long xn = b*(y*100)+cc, xd = -a;
        for (i=0;i<n;i++)
          if (c[i] == 'T' && y % 2 != 0 || c[i] == 'F' && y % 2 == 0) {
            if (xa[i]*xd <= xn && xb[i]*xd >= xn) {
              if (used[i]) ok = 0;
              used[i] = 1;
              found = 1;
              break;
            }
          }
        if (!found) ok = 0;
      }
    }
    if (ok) {
      int cost = 0;
      for (i=0;i<n;i++) cost += used[i]*sc[i];
      if (cost > ans) ans = cost;
    }
  }
  printf("%d\n", ans);
  return 0;
}