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

const int N = 11111;

int n, k, i, z;
int a[N], q[N], v[N], b[N], s[N];

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d %d", &n, &k);
  for (i=1;i<=n;i++) scanf("%d", q+i);
  for (i=1;i<=n;i++) v[q[i]] = i;
  for (i=1;i<=n;i++) scanf("%d", s+i);
  int left = -k-1, right = k+1;
  for (i=1;i<=n;i++) a[i] = i;
  for (z=0;z<=k;z++) {
    int ok = 1;
    for (i=1;i<=n;i++)
      if (a[i] != s[i]) ok = 0;
    if (ok) {
      right = z;
      break;
    }
    for (i=1;i<=n;i++) b[i] = a[q[i]];
    for (i=1;i<=n;i++) a[i] = b[i];
  }
  for (i=1;i<=n;i++) a[i] = i;
  for (z=0;z>=-k;z--) {
    int ok = 1;
    for (i=1;i<=n;i++)
      if (a[i] != s[i]) ok = 0;
    if (ok) {
      left = z;
      break;
    }
    for (i=1;i<=n;i++) b[i] = a[v[i]];
    for (i=1;i<=n;i++) a[i] = b[i];
  }
  if (left == 0 && right == 0) puts("NO"); else
  if (k == 1 && (left == -1 || right == 1)) puts("YES"); else
  if (left == -1 && right == 1) puts("NO"); else
  if ((k+left) % 2 == 0 || (k-right) % 2 == 0) puts("YES");
  else puts("NO");
  return 0;
}