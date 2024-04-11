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

int n, a, b, i, j, p;
int h[222], f[222][44444][2];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d %d", &n, &a, &b);
  for (i=1;i<=n;i++) scanf("%d", &h[i]);
  h[0] = 0;
  memset(f,50,sizeof(f));
  f[0][0][0] = 0;
  int sum = 0, cur;
  for (i=0;i<n;i++) {
    sum += h[i+1];
    if (h[i] < h[i+1]) cur = h[i];
    else cur = h[i+1];
    for (j=0;j<=a;j++)
      for (p=0;p<=1;p++) {
        if (j+h[i+1] <= a) {
          int ft = f[i][j][p];
          if (p == 1) ft += cur;
          if (ft < f[i+1][j+h[i+1]][0]) f[i+1][j+h[i+1]][0] = ft;
        }
        if (sum-j <= b) {
          int ft = f[i][j][p];
          if (p == 0) ft += cur;
          if (ft < f[i+1][j][1]) f[i+1][j][1] = ft;
        }
      }
  }
  int ans = (int)2e9;
  for (j=0;j<=a;j++)
    for (p=0;p<=1;p++)
      if (f[n][j][p] < ans) ans = f[n][j][p];
  if (ans > 1e7) ans = -1;
  printf("%d\n", ans);
  return 0;
}