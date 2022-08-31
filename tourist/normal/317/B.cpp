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

int a[666][666], na[666][666];

int main() {
  int n;
  scanf("%d", &n);
  memset(a, 0, sizeof(a));
  a[0][0] = n;
  int mx = 0, it = 0;
  while (1) {
    bool ok = true;
    for (int i=0;i<=mx+1;i++)
      for (int j=0;j<=mx+1;j++) na[i][j] = a[i][j];
    int nmx = mx;
    for (int i=0;i<=mx;i++)
      for (int j=0;j<=mx;j++)
        if (a[i][j] >= 4) {
          ok = false;
          na[i][j] -= 4;
          if (i > 0) na[i-1][j]++;
          if (j > 0) na[i][j-1]++;
          na[i+1][j]++;
          na[i][j+1]++;
          if (i == 1) na[i-1][j]++;
          if (j == 1) na[i][j-1]++;
          if (i == mx || j == mx) nmx = mx+1;
        }
    if (ok) break;
    mx = nmx;
    for (int i=0;i<=mx;i++)
      for (int j=0;j<=mx;j++) a[i][j] = na[i][j];
  }
  int tt;                         
  scanf("%d", &tt);
  while (tt--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    int ans;
    if (x > mx || y > mx) ans = 0;
    else ans = a[x][y];
    printf("%d\n", ans);
  }
  return 0;
}