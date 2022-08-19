#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int color[N];
vector <int> g[N];
int from[N], to[N];

void dfs(int v) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (color[u] == -1) {
      color[u] = (color[v] ^ 1);
      dfs(u);
    }
  }
}

void print_it(vector <int> z) {
  int sz = z.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", 1 + z[i]);
  }
  printf("\n");
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    from[i] = foo;
    to[i] = bar;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  for (int i = 0; i < n; i++) {
    color[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      color[i] = 0;
      dfs(i);
    }
  }
  for (int i = 0; i < m; i++) {
    if (color[from[i]] == color[to[i]]) {
      printf("%d\n", -1);
      return 0;
    }
  }
  vector <int> x, y;
  for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
      x.push_back(i);
    } else {
      y.push_back(i);
    }
  }
  print_it(x);
  print_it(y);
  return 0;
}