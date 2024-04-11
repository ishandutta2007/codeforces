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

int n, i, j, mx;
int a[111][1111];

void go(int lev, int l, int r) {
  if (l == r) return;
  if (lev > mx) mx = lev;
  int y = (l+r) >> 1;
  for (int i=l;i<=y;i++) a[lev][i] = 1;
  go(lev+1, l, y);
  go(lev+1, y+1, r);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  memset(a,0,sizeof(a));
  mx = 0;
  go(1, 1, n);
  printf("%d\n", mx);
  for (i=1;i<=mx;i++) {
    int cnt = 0;
    for (j=1;j<=n;j++)
      if (a[i][j]) cnt++;
    printf("%d", cnt);
    for (j=1;j<=n;j++)
      if (a[i][j]) printf(" %d", j);
    printf("\n");
  }
  return 0;
}