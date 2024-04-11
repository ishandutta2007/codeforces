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

const int md = 1000000000;

long long a[222222], f[222222];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=1;i<=n;i++) scanf("%d", a+i);
  f[0] = f[1] = 1;
  for (int i=2;i<=n;i++) f[i] = (f[i-1] + f[i-2]) % md;
  for (int i=1;i<=m;i++) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      int q, w;
      scanf("%d %d", &q, &w);
      a[q] = w;
    } else
    if (com == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      int ans = 0;
      for (int j=0;j<=r-l;j++) ans = (ans + (long long)f[j] * a[l+j]) % md;
      printf("%d\n", ans);
    } else {
      int l, r, v;
      scanf("%d %d %d", &l, &r, &v);
      for (int j=l;j<=r;j++) a[j] += v;
    }
  }
  return 0;
}