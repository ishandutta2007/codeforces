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

const int N = 200010;

vector <int> g[N];
int T, tin[N], tout[N];
bool was[N];
int pv[N], pr[N][20];
int de[N], md[N];

void dfs(int v) {
  was[v] = true;
  tin[v] = ++T;
  md[v] = 0;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (!was[u]) {
      pv[u] = v;
      de[u] = de[v] + 1;
      dfs(u);
      if (md[u] + 1 > md[v]) {
        md[v] = md[u] + 1;
      }
    }
  }
  tout[v] = ++T;
} 

bool anc(int x, int y) {
  return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int x, int y) {
  if (anc(x, y)) return x;
  for (int j = 19; j >= 0; j--)
    if (!anc(pr[x][j], y)) x = pr[x][j];
  return pv[x];
}

int mx1[N], mx2[N], mx3[N];
int km1[N], km2[N], km3[N];

int diff[N], sum[N];
int pdiff[N][20], psum[N][20];

int ans;

inline void update(int &a, int b) {
  if (a < b) a = b;
}

int get_up(int v, int h, int add2 = 0) {
  int add = de[v] + add2;
  int mx = -123456789;
  for (int j = 19; j >= 0; j--)
    if (h & (1 << j)) {
      if (pdiff[v][j] > mx) {
        mx = pdiff[v][j];
      }
      v = pr[v][j];
    }
  update(ans, mx + add);
  return v;
}

int get_up_weird(int v, int h, int add) {
  int mx = -123456789;
  for (int j = 19; j >= 0; j--)
    if (h & (1 << j)) {
      if (psum[v][j] > mx) {
        mx = psum[v][j];
      }
      v = pr[v][j];
    }
  update(ans, mx + add);
  return v;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  for (int i = 1; i <= n; i++) was[i] = false;
  pv[1] = 1;
  de[1] = 1;
  T = 0;
  dfs(1);
  for (int v = 1; v <= n; v++) {
    int sz = g[v].size();
    mx1[v] = 0; km1[v] = 0;
    mx2[v] = 0; km2[v] = 0;
    mx3[v] = 0; km3[v] = 0;
    for (int j = 0; j < sz; j++) {
      int u = g[v][j];
      if (pv[u] == v) {
        int cur = md[u] + 1;
        if (cur > mx1[v]) {
          mx3[v] = mx2[v]; km3[v] = km2[v];
          mx2[v] = mx1[v]; km2[v] = km1[v];
          mx1[v] = cur; km1[v] = u;
          continue;
        }
        if (cur > mx2[v]) {
          mx3[v] = mx2[v]; km3[v] = km2[v];
          mx2[v] = cur; km2[v] = u;
          continue;
        }
        if (cur > mx3[v]) {
          mx3[v] = cur; km3[v] = u;
          continue;
        }
      }
    }
  }
  diff[1] = sum[1] = -123456789;
  for (int i = 2; i <= n; i++) {
    if (km1[pv[i]] == i) {
      diff[i] = mx2[pv[i]] - de[pv[i]];
    } else {
      diff[i] = mx1[pv[i]] - de[pv[i]];
    }
    sum[i] = diff[i] + 2 * de[pv[i]];
  }
  for (int i = 1; i <= n; i++) {
    pr[i][0] = pv[i];
    pdiff[i][0] = diff[i];
    psum[i][0] = sum[i];
  }
  for (int j = 1; j < 20; j++)
    for (int i = 1; i <= n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
      pdiff[i][j] = pdiff[pr[i][j - 1]][j - 1];
      if (pdiff[i][j - 1] > pdiff[i][j]) pdiff[i][j] = pdiff[i][j - 1];
      psum[i][j] = psum[pr[i][j - 1]][j - 1];
      if (psum[i][j - 1] > psum[i][j]) psum[i][j] = psum[i][j - 1];
    }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (de[x] > de[y]) swap(x, y);
    int z = lca(x, y);
    int dx = de[x] - de[z];
    int dy = de[y] - de[z];
    ans = md[y];
    if (x != z) {
      if (md[x] > ans) ans = md[x];
    }
    int yy = get_up(y, (dy + dx - 1) / 2);
    if (de[yy] - de[z] >= 2) {
      get_up_weird(yy, de[yy] - de[z] - 1, de[x] - 2 * de[z]);
    }
    if (de[x] - de[z] >= 2) {
      get_up(x, de[x] - de[z] - 1);
    }
    if (km1[z] != -1 && !anc(km1[z], x) && !anc(km1[z], y)) {
      update(ans, mx1[z] + de[x] - de[z]);
    }
    if (km2[z] != -1 && !anc(km2[z], x) && !anc(km2[z], y)) {
      update(ans, mx2[z] + de[x] - de[z]);
    }
    if (km3[z] != -1 && !anc(km3[z], x) && !anc(km3[z], y)) {
      update(ans, mx3[z] + de[x] - de[z]);
    }
    get_up(z, de[z] - 1, de[x] - de[z]);
    printf("%d\n", ans);
  }
  return 0;
}