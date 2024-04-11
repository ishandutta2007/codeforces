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

int n, m, i, j;
char foo[12345];
int t[5010];
int f[5010][5010];

int main() {
  scanf("%d %d", &n, &m);
  for (i=1;i<=n;i++) scanf("%d %s", t+i, foo);
  memset(f, 255, sizeof(f));
  f[1][1] = 0;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++) {
      if (f[i][j] < 0) continue;
      if (j < n && f[i][j] > f[i][j+1]) f[i][j+1] = f[i][j];
      int ft = f[i][j]+(t[i] == j);
      if (ft > f[i+1][j]) f[i+1][j] = ft;
    }
  int ans = 0;
  for (j=1;j<=m;j++)
    if (f[n+1][j] > ans) ans = f[n+1][j];
  printf("%d\n", n-ans);
  return 0;
}