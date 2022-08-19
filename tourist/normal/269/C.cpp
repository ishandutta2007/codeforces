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

const int N = 888888;

int n, m, i, j, e;
int ss[N], ff[N], dd[N], x[N], last[N], pred[N], good[N], deg[N], used[N];

int main() {
  scanf("%d %d", &n, &m);
  for (i=1;i<=m;i++) {
    scanf("%d %d %d", ss+i, ff+i, dd+i);
    ss[i+m] = ff[i];
    ff[i+m] = ss[i];
    dd[i+m] = dd[i];
  }
  for (i=1;i<=n;i++) last[i] = 0;
  for (i=1;i<=m+m;i++) {
    good[i] = 0;
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (i=1;i<=n;i++) deg[i] = 0;
  for (i=1;i<=m+m;i++) deg[ss[i]] += dd[i];
  for (i=1;i<=n;i++) deg[i] /= 2;
  for (i=1;i<=n;i++) used[i] = 0;
  deg[1] = deg[n] = 0;
  i = 1; e = 1;
  x[1] = 1;
  while (i <= e) {
    j = last[x[i]];
    while (j > 0) {
      if (ff[j] == n) good[j] = 1;
      if (used[ff[j]] < deg[ff[j]]) {
        good[j] = 1;
        used[ff[j]] += dd[j];
        if (used[ff[j]] == deg[ff[j]]) {
          e++;
          x[e] = ff[j];
        }
      }
      j = pred[j];
    }
    i++;
  }
  for (i=1;i<=m;i++) printf("%d\n", 1-good[i]);
  return 0;
}