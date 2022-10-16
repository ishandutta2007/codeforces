#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int c[N];
vector <int> g[N];

void put(int x) {
  c[x] = -c[x];
  printf(" %d", x + 1);
}

void dfs(int v, int pr) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    put(u);
    dfs(u, v);
    put(v);
    if (c[u] == -1) {
      put(u);
      put(v);
    }
  }
  if (v == 0 && c[v] == -1) {
    int u = g[v][0];
    put(u);
    put(v);
    put(u);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  printf("1");
  dfs(0, -1);
  return 0;
}