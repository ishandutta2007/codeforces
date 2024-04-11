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

int n, i, j, md;
int f[444444], g[444444], a[444444], b[444444];

int main() {
  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%d", a+i);
  for (i=0;i<n;i++) scanf("%d", b+i);
  scanf("%d", &md);
  int div2 = 0;
  for (i=0;i<n;i++)
    if (a[i] == b[i]) div2++;
  sort(a, a+n);
  sort(b, b+n);
  f[0] = 1;
  g[0] = 0;
  for (i=1;i<=2*n;i++) {
    g[i] = g[i-1];
    int x = i;
    while (x % 2 == 0) {
      x /= 2;
      g[i]++;
    }
    f[i] = (long long)f[i-1]*x % md;
  }
  int ans = 1, mul2 = 0;
  i = 0, j = 0;
  while (i < n || j < n) {
    int u;
    if (i == n) u = b[j]; else
    if (j == n) u = a[i]; else
    if (a[i] < b[j]) u = a[i];
    else u = b[j];
    int cnt = 0;
    while (i < n && a[i] == u) i++, cnt++;
    while (j < n && b[j] == u) j++, cnt++;
    ans = (long long)ans*f[cnt] % md;
    mul2 += g[cnt];
  }
  for (i=0;i<mul2-div2;i++) ans = (long long)ans*2 % md;
  printf("%d\n", ans);
  return 0;
}