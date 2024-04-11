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

const int N = 300010;

int n;
int s[N];

void modify(int x, int v) {
  while (x <= n) {
    s[x] += v;
    x = (x | (x - 1)) + 1;
  }
}

int find_sum(int x) {
  int v = 0;
  while (x > 0) {
    v += s[x];
    x &= x - 1;
  }
  return v;
}

int tin[N], tout[N], kw;
vector <int> g[N];
int de[N];

void dfs(int v) {
  tin[v] = ++kw;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    de[g[v][j]] = de[v] + 1;
    dfs(g[v][j]);
  }
  tout[v] = kw;
}

int pv[N];
vector <int> qs[N];
int result[N];
int op[N], x[N], y[N];

int main() {
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    pv[i] = i;
    g[i].clear();
  }
  vector <int> docs;
  for (int i = 0; i < m; i++) {
    scanf("%d", op + i);
    if (op[i] == 2) {
      scanf("%d", x + i);
      docs.push_back(i);
    } else {
      scanf("%d %d", x + i, y + i);
      if (op[i] == 1) {
        pv[x[i]] = y[i];
        g[y[i]].push_back(x[i]);
      } else {
        qs[docs[y[i] - 1]].push_back(i);
        result[i] = -1;
      }
    }
  }
  kw = 0;
  for (int i = 1; i <= n; i++) {
    if (pv[i] == i) {
      de[i] = 0;
      dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    s[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    if (op[i] == 1) {
      modify(tin[x[i]], 1);
      modify(tout[x[i]] + 1, -1);
      continue;
    }
    if (op[i] == 2) {
      int from = x[i];
      int sz = qs[i].size();
      for (int j = 0; j < sz; j++) {
        result[qs[i][j]] = 0;
        int to = x[qs[i][j]];
        if (tin[to] <= tin[from] && tout[from] <= tout[to]) {
          if (find_sum(tin[from]) - find_sum(tin[to]) == de[from] - de[to]) {
            result[qs[i][j]] = 1;
          }
        }
      }
      continue;
    }
    puts(result[i] ? "YES" : "NO");
  }
  return 0;
}