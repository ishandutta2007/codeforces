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

int a[N], b[N], c[N], d[N], e[N], ax[N], bx[N];
int n, m, i;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (i=0;i<m;i++) scanf("%d", &b[i]);
  int ka = 1, kb = 1;
  ax[0] = 1;
  for (i=1;i<n;i++) {
    if (a[i] != a[i-1]) ka++;
    ax[i] = ka;
  }
  if (a[n-1] == 0) ka--;
  bx[0] = 1;
  for (i=1;i<m;i++) {
    if (b[i] != b[i-1]) kb++;
    bx[i] = kb;
  }
  if (b[m-1] == 0) kb--;
  if (ka > kb && (ka % 2) != (kb % 2))
    for (i=0;i<m;i++) bx[i]++;
  if (ka < kb && (ka % 2) != (kb % 2))
    for (i=0;i<n;i++) ax[i]++;
  int i = 0, j = 0, u = 0;
  for (int k=1;k<=ka || k <= kb;k++) {
    while (i < n && ax[i] == k) {
      c[u++] = i;
      i++;
    }
    while (j < m && bx[j] == k) {
      c[u++] = n+j;
      j++;
    }
  }
  while (i < n) {
    c[u++] = i;
    i++;
  }
  while (j < m) {
    c[u++] = n+j;
    j++;
  }
  for (i=0;i<u-1;i++) printf("%d ", c[i]+1);
  printf("%d\n", c[u-1]+1);
  for (i=0;i<u;i++)
    if (c[i] < n) d[i] = a[c[i]];
    else d[i] = b[c[i]-n];
  int ke = 0;
  for (i=0;i<u-1;i++)
    if (d[i] != d[i+1]) e[ke++] = i;
  if (d[u-1] == 1) e[ke++] = u-1;
  printf("%d\n", ke);
  for (i=0;i<ke-1;i++) printf("%d ", e[i]+1);
  if (ke > 0) printf("%d", e[ke-1]+1);
  printf("\n");
  return 0;
}