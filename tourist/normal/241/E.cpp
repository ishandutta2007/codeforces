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

const int N = 44444;

int n, m, i, e, j, it;
int ss[N], ff[N], x[N], was[N], d[N];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d %d", &n, &m);
  for (i=1;i<=m;i++) scanf("%d %d", ss+i, ff+i);

  for (i=1;i<=n;i++) was[i] = 0;
  
  i = 1; e = 1;
  x[1] = 1;
  was[1] |= 1;
  while (i <= e) {
    for (j=1;j<=m;j++)
      if (ss[j] == x[i])
        if (!(was[ff[j]] & 1)) {
          e++;
          x[e] = ff[j];
          was[ff[j]] |= 1;
        }
    i++;
  }
  
  i = 1; e = 1;
  x[1] = n;
  was[n] |= 2;
  while (i <= e) {
    for (j=1;j<=m;j++)
      if (ff[j] == x[i])
        if (!(was[ss[j]] & 2)) {
          e++;
          x[e] = ss[j];
          was[ss[j]] |= 2;
        }
    i++;
  }

  for (i=1;i<=n;i++) d[i] = (int)1e9;
  d[1] = 0;

  int last = 0;
  for (it=0;it<=3*n;it++) {
    for (i=1;i<=m;i++)
      if (was[ss[i]] == 3 && was[ff[i]] == 3) {
        if (d[ss[i]]+2 < d[ff[i]]) d[ff[i]] = d[ss[i]]+2, last = it;
        if (d[ff[i]]-1 < d[ss[i]]) d[ss[i]] = d[ff[i]]-1, last = it;
      }
  }

  if (last == 3*n) puts("No"); else {
    puts("Yes");
    for (i=1;i<=m;i++)
      if (was[ss[i]] == 3 && was[ff[i]] == 3) printf("%d\n", d[ff[i]]-d[ss[i]]);
      else printf("%d\n", 1);
  }

  return 0;
}