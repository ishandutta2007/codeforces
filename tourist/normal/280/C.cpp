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

const int N = 444444;

int ss[N], ff[N], pred[N], last[N], x[N], was[N];

int main() {
  int n;
  scanf("%d", &n);
  int m = n-1;
  for (int i=1;i<=m;i++) {
    scanf("%d %d", ss+i, ff+i);
    ss[i+m] = ff[i];
    ff[i+m] = ss[i];
  }
  for (int i=1;i<=n;i++) last[i] = 0;
  for (int i=1;i<=m+m;i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  for (int i=1;i<=n;i++) was[i] = 0;
  int i = 1, e = 1;
  x[1] = 1;
  was[1] = 1;
  while (i <= e) {
    int j = last[x[i]];
    while (j > 0) {
      if (!was[ff[j]]) {
        e++;
        x[e] = ff[j];
        was[x[e]] = was[x[i]]+1;
      }
      j = pred[j];
    }
    i++;
  }
  double ans = 0;
  for (int i=1;i<=n;i++) ans += 1.0/was[i];
  printf("%.17lf\n", ans);
  return 0;
}