#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int r[N], any[N];
vector < pair <int, int> > g[N];
int x[N];
int color[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", r + i);
    any[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int foo;
    scanf("%d", &foo);
    for (int j = 0; j < foo; j++) {
      int bar;
      scanf("%d", &bar);
      bar--;
      if (any[bar] == -1) {
        any[bar] = i;
      } else {
        g[any[bar]].emplace_back(i, r[bar] ^ 1);
        g[i].emplace_back(any[bar], r[bar] ^ 1);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    color[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    if (color[i] != -1) {
      continue;
    }
    int b = 0, e = 1;
    x[0] = i;
    color[i] = 0;
    while (b < e) {
      int sz = g[x[b]].size();
      for (int j = 0; j < sz; j++) {
        int u = g[x[b]][j].first;
        int c = g[x[b]][j].second;
        if (color[u] == -1) {
          x[e] = u;
          color[u] = color[x[b]] ^ c;
          e++;
        } else {
          if (color[u] != (color[x[b]] ^ c)) {
            puts("NO");
            return 0;
          }
        }
      }
      b++;
    }
  }
  puts("YES");
  return 0;
}