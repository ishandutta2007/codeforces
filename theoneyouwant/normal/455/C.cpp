#include <cstring>
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
#include <cassert>

using namespace std;

const int N = 600010;

int ROOT, MAX, CITY;

int p[N], was[N];

vector <int> g[N];

void dfs(int v, int d, int mark) {
  p[v] = ROOT;
  if (d > MAX) {
    MAX = d;
    CITY = v;
  }
  was[v] = mark + 1;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (was[u] > mark) {
      continue;
    }
    dfs(u, d + 1, mark);
  }
}

int diam[N];

int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  for (int i = 1; i <= n; i++) {
    was[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (was[i] == 0) {
      ROOT = i;
      MAX = -1; CITY = 0;
      dfs(i, 0, 0);
      int to = CITY;
      MAX = -1; CITY = 0;
      dfs(to, 0, 1);
      diam[i] = MAX;
    }
  }
  while (q--) {
    int com;
    scanf("%d", &com);
    if (com == 1) {
      int x;
      scanf("%d", &x);
      printf("%d\n", diam[find_set(x)]);
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      if (q % 7 <= 4) {
        swap(x, y);
      }
      x = find_set(x);
      y = find_set(y);
      if (x == y) {
        continue;
      }
      p[x] = y;
      int old = (diam[x] > diam[y]) ? diam[x] : diam[y];
      diam[y] = ((diam[y] + 1) / 2) + 1 + ((diam[x] + 1) / 2);
      if (old > diam[y]) {
        diam[y] = old;
      }
    }
  }
  return 0;
}