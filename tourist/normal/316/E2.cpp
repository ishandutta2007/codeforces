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
const int N = 222222;

long long a[N], f[N];
long long s1[4*N], s2[4*N];
int added, ans;

int get(int first, int second, int id) {
  int res = (f[id-1] * first + f[id] * second) % md;
  return res;
}

void build(int x, int l, int r) {
  if (l == r) {
    s1[x] = a[l];
    s2[x] = a[l];
    return;
  }
  int y = (l+r) >> 1;
  build(x+x, l, y);
  build(x+x+1, y+1, r);
  s1[x] = s1[x+x] + get(s1[x+x+1], s2[x+x+1], y-l+2);
  if (s1[x] >= md) s1[x] -= md;
  s2[x] = s2[x+x] + get(s1[x+x+1], s2[x+x+1], y-l+3);
  if (s2[x] >= md) s2[x] -= md;
}

void modify(int x, int l, int r, int p, int v) {
  if (l == r) {
    s1[x] = v;
    s2[x] = v;
    return;
  }
  int y = (l+r) >> 1;
  if (p <= y) modify(x+x, l, y, p, v);
  else modify(x+x+1, y+1, r, p, v);
  s1[x] = s1[x+x] + get(s1[x+x+1], s2[x+x+1], y-l+2);
  if (s1[x] >= md) s1[x] -= md;
  s2[x] = s2[x+x] + get(s1[x+x+1], s2[x+x+1], y-l+3);
  if (s2[x] >= md) s2[x] -= md;
}

void sum(int x, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) {
    ans += get(s1[x], s2[x], added+1);
    if (ans >= md) ans -= md;
    added += r-l+1;
    return;
  }
  int y = (l+r) >> 1;
  if (ll <= y) sum(x+x, l, y, ll, rr);
  if (rr > y) sum(x+x+1, y+1, r, ll, rr);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i=1;i<=n;i++) scanf("%d", a+i);
  f[0] = 1; f[1] = 0;
  for (int i=2;i<=n+3;i++) f[i] = (f[i-1] + f[i-2]) % md;
  build(1, 1, n);
  for (int i=1;i<=m;i++) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      int q, w;
      scanf("%d %d", &q, &w);
      modify(1, 1, n, q, w);
    } else
    if (com == 2) {
      int l, r;
      scanf("%d %d", &l, &r);
      added = 0;
      ans = 0;
      sum(1, 1, n, l, r);
      printf("%d\n", ans);
    } else {
      int l, r, v;
      scanf("%d %d %d", &l, &r, &v);
//      for (int j=l;j<=r;j++) a[j] += v;
    }
  }
  return 0;
}