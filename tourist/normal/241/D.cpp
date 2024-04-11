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

int a[55555], id[55555], b[55555];

char f[33][33][50010];
unsigned short pr[33][33][50010];

int main() {
  int n, p, i;
  scanf("%d %d", &n, &p);
  for (i=1;i<=n;i++) scanf("%d", a+i);
  int co = 31, m = 0;
  for (i=1;i<=n;i++)
    if (a[i] <= co) {
      m++;
      b[m] = a[i];
      id[m] = i;
    }
  int j, k;
  memset(f, 0, sizeof(f));
  f[1][0][0] = 1;
  for (i=1;i<=m;i++)
    for (j=0;j<=co;j++)
      for (k=0;k<p;k++)
        if (f[i][j][k]) {
          if (f[i+1][j][k] == 0)
            f[i+1][j][k] = 1;
          int nk = k;
          if (b[i] >= 10) nk *= 100;
          else nk *= 10;
          nk += b[i];
          nk %= p;
          int nj = j ^ b[i];
          f[i+1][nj][nk] = 2;
          pr[i+1][nj][nk] = k;
        }
  vector <int> ret;
  i = m+1; j = 0; k = 0;
  while (i > 1) {
    if (f[i][j][k] == 1) i--; else {
      ret.push_back(id[i-1]);
      k = pr[i][j][k];
      i--;
      j ^= b[i];
    }
  }
  sort(ret.begin(), ret.end());
  if (ret.size() == 0) puts("No"); else {
    puts("Yes");
    printf("%d\n", ret.size());
    for (i=0;i<(int)ret.size()-1;i++) printf("%d ", ret[i]);
    printf("%d\n", ret[ret.size()-1]);
  }
  return 0;
}