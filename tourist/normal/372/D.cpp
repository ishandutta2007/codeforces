#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int N = 400010;

int from[N], to[N], pred[N], last[N], de[N], pv[N];
int T, tin[N], tout[N];
int kw, w[N], pos[N];
int s[N], pr[N], ne[N];
bool was[N];
int plca[22][N];

int n;

void dfs(int v) {
  tin[v] = ++T;
  was[v] = true;
  w[++kw] = v;
  int j = last[v];
  while (j > 0) {
    if (!was[to[j]]) {
      de[to[j]] = de[v] + 1;
      pv[to[j]] = v;
      dfs(to[j]);
    }
    j = pred[j];
  }
  tout[v] = ++T;
}

void modify(int x, int v) {
  while (x <= n) {
    s[x] += v;
    x = (x | (x - 1)) + 1;
  }
}

int findsum(int x) {
  int v = 0;
  while (x > 0) {
    v += s[x];
    x &= x - 1;
  }
  return v;
}

int find_left(int p) {
  if (findsum(n) == 0) return p;
  if (findsum(p) == 0) p = n;
  int u = findsum(p);
  int ll = 1, rr = p;
  while (ll < rr) {
    int mid = (ll + rr) >> 1;
    if (findsum(mid) == u) rr = mid;
    else ll = mid + 1;
  }
  return ll;
}

int find_right(int p) {
  if (findsum(n) == 0) return p;
  if (findsum(n) - findsum(p) == 0) p = 0;
  int u = findsum(p);
  int ll = p, rr = n;
  while (ll < rr) {
    int mid = (ll + rr) >> 1;
    if (findsum(mid) == u) ll = mid + 1;
    else rr = mid;
  }
  return ll;
}

bool anc(int x, int y) {
  return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y) {
  if (anc(x, y)) return x;
  for (int j = 20; j >= 0; j--)
    if (!anc(plca[j][x], y)) x = plca[j][x];
  return pv[x];
}

int sum;

int get(int x, int y) {
  x = w[x];
  y = w[y];
  int z = lca(x, y);
  return de[y] - de[z];
}

void add(int v) {
  v = pos[v];
  pr[v] = find_left(v);
  ne[v] = find_right(v);
  pr[ne[v]] = v;
  ne[pr[v]] = v;
  modify(v, 1);
  sum -= get(pr[v], ne[v]);
  sum += get(pr[v], v);
  sum += get(v, ne[v]);
}

void del(int v) {
  v = pos[v];
  sum -= get(pr[v], v);
  sum -= get(v, ne[v]);
  sum += get(pr[v], ne[v]);
  pr[ne[v]] = pr[v];
  ne[pr[v]] = ne[v];
  modify(v, -1);
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  int m = n - 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", from + i, to + i);
    from[i + m] = to[i];
    to[i + m] = from[i];
  }
  for (int i = 1; i <= n; i++) last[i] = 0;
  for (int i = 1; i <= m + m; i++) {
    pred[i] = last[from[i]];
    last[from[i]] = i;
  }
  for (int i = 1; i <= n; i++) was[i] = false;
  kw = 0;
  de[1] = 1;
  T = 0;
  dfs(1);
  pv[1] = 1;
  for (int i = 1; i <= n; i++) plca[0][i] = pv[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) {
      plca[j][i] = plca[j - 1][plca[j - 1][i]];
    }
  for (int i = 1; i <= n; i++) pos[w[i]] = i;
  for (int i = 1; i <= n; i++) s[i] = 0;
  int R = 0, ans = 1;
  sum = 1;
  for (int L = 1; L < n; L++) {
    while (R + 1 <= n) {
      add(R + 1);
      if (sum <= k) R++; else {
        del(R + 1);
        break;
      }
    }
    if (R - L + 1 > ans) ans = R - L + 1;
    del(L);
  }
  printf("%d\n", ans);
  return 0;
}