#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

const int N = 42424;

int ss[N], ff[N], pred[N], last[N], was[N], sz[N];
int n, m, ans, i, st;

void dfs0(int v) {
  was[v] = 1;
  sz[v] = 0;
  int j = last[v];
  while (j > 0) {
    if (!was[ff[j]]) {
      dfs0(ff[j]);
      sz[v] += sz[ff[j]];
      if (j > m) sz[v]++;
    }
    j = pred[j];
  }
}

void dfs(int v, int w, int s, int mn, int p) {
  was[v] = 1;
  int cur = w;
  int j = last[v];
  while (j > 0) {
    if (!was[ff[j]]) {
      cur += sz[ff[j]];
      if (j > m) cur++;
    }
    j = pred[j];
  }
  if (cur+s+mn < ans) ans = cur+s+mn;
  j = last[v];
  while (j > 0) {
    if (!was[ff[j]]) {
      int cc = cur-sz[ff[j]];
      if (j > m) cc--;
      int newp = p+1, news = s;
      if (j <= m) news++;
      int newmn = mn;
      if (newp-2*news < newmn) newmn = newp-2*news;
      dfs(ff[j], cc, news, newmn, newp);
    }
    j = pred[j];
  }
}

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  scanf("%d", &n);
  m = n-1;
  for (i=1;i<=m;i++) {
    scanf("%d %d", ss+i, ff+i);
    ss[i+m] = ff[i];
    ff[i+m] = ss[i];
  }
  for (i=1;i<=n;i++) last[i] = 0;
  for (i=1;i<=m+m;i++) {
    pred[i] = last[ss[i]];
    last[ss[i]] = i;
  }
  ans = 424242;
  for (st=1;st<=n;st++) {
    for (i=1;i<=n;i++) was[i] = 0;
    dfs0(st);
    for (i=1;i<=n;i++) was[i] = 0;
    dfs(st, 0, 0, 0, 0);
  }
  printf("%d\n", ans);
  return 0;
}