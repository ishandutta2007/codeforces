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

int n, m, i, j, e, kw, kc, ii;
int ss[N], ff[N], dd[N], cs[N], cf[N], cd[N], pred[N], last[N], x[N], was[N], c[N], w[N], deg[N], r[N];
                                                                                   
void rec(int v) {
  was[v] = 1;
  int j = last[v];
  while (j > 0) {
    if (!was[cf[j]]) rec(cf[j]);
    j = pred[j];
  }
  w[kw++] = v;
}

void go(int v) {
  c[v] = kc;
  int j = last[v];
  while (j > 0) {
    if (!c[cs[j]]) go(cs[j]);
    j = pred[j];
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  for (i=1;i<=m;i++) scanf("%d %d %d", &ss[i], &ff[i], &dd[i]);
  kc = n;
  for (i=1;i<=n;i++) c[i] = i;
  for (i=1;i<=m;i++) { cs[i] = ss[i]; cf[i] = ff[i]; cd[i] = dd[i]; }
  int root = 1, cnt = 0;
  while (1) {
    memset(last, 0, sizeof(last));
    for (i=1;i<=m;i++)
      if (!cd[i]) {
        pred[i] = last[cs[i]];
        last[cs[i]] = i;
      }
    memset(was, 0, sizeof(was));
    kw = 0;
    for (i=1;i<=kc;i++)
      if (!was[i]) rec(i);
    memset(last, 0, sizeof(last));
    for (i=1;i<=m;i++)
      if (!cd[i]) {
        pred[i] = last[cf[i]];
        last[cf[i]] = i;
      }
    memset(c, 0, sizeof(c));
    int old = kc;
    kc = 0;
    for (ii=kw-1;ii>=0;ii--)
      if (!c[w[ii]]) {
        kc++;
        go(w[ii]);
      }
    if (kc == old) cnt++;
    if (cnt > 2) {
      printf("%d\n", -1);
      return 0;
    }
    memset(last, 0, sizeof(last));
    for (i=1;i<=m;i++) {
      cs[i] = c[cs[i]];
      cf[i] = c[cf[i]];
      if (cs[i] != cf[i]) {
        pred[i] = last[cs[i]];
        last[cs[i]] = i;
      }
    }
    memset(deg, 0, sizeof(deg));
    for (i=1;i<=m;i++)
      if (cs[i] != cf[i] && !cd[i] && cf[i] != c[root]) deg[cf[i]] = 1;
    int ok = 1;
    for (i=1;i<=kc;i++)
      if (deg[i] == 0 && i != c[root]) {
        ok = 0;
        break;
      }
    if (ok) break;
    for (i=1;i<=m;i++)
      if (cs[i] != cf[i])
        if (deg[cf[i]] == 0) cd[i] = 0;
    root = c[root];
  }
  memset(last, 0, sizeof(last));
  for (i=1;i<=m;i++) {
    if (cd[i]) continue;
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  memset(was, 0, sizeof(was));
  int kr = 0;
  i = 1; e = 1;
  x[1] = 1;
  was[1] = 1;
  while (i <= e) {
    j = last[x[i]];
    while (j > 0) {
      if (!was[ff[j]]) {
        e++;
        x[e] = ff[j];
        if (dd[j]) r[kr++] = j;
        was[x[e]] = 1;
      }
      j = pred[j];
    }
    i++;
  }
  if (kr > 0) sort(r, r+kr);
  if (e < n) {
    printf("%d\n", -1);
    return 0;
  }
  printf("%d\n", kr);
  for (i=0;i<kr-1;i++) printf("%d ", r[i]);
  if (kr > 0) printf("%d", r[kr-1]);
  printf("\n");
  return 0;
}