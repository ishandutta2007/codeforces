#include <bits/stdc++.h>

using namespace std;

const int N = 40010;

bool was[N];
vector <int> g[N], gr[N];
int kw, w[N];
int comp[N];

void dfs1(int v) {
  was[v] = true;
  int sz = gr[v].size();
  for (int j = 0; j < sz; j++) {
    int u = gr[v][j];
    if (!was[u]) {
      dfs1(u);
    }
  }
  w[kw++] = v;
}

void dfs2(int v) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (comp[u] == -1) {
      comp[u] = comp[v];
      dfs2(u);
    }
  }
}

int d[N], x[N];
vector <int> who[N];
int value[N], best[N];
int from[N], to[N];

const int inf = (int) 1e9;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", from + i, to + i);
    from[i]--; to[i]--;
    g[from[i]].push_back(to[i]);
    gr[to[i]].push_back(from[i]);
  }
  for (int i = 0; i < n; i++) {
    was[i] = false;
  }
  kw = 0;
  for (int i = 0; i < n; i++) {
    if (!was[i]) {
      dfs1(i);
    }
  }
  for (int i = 0; i < n; i++) {
    comp[i] = -1;
  }
  int nc = 0;
  for (int it = kw - 1; it >= 0; it--) {
    int i = w[it];
    if (comp[i] == -1) {
      comp[i] = nc++;
      dfs2(i);
    }
  }
  for (int start = 0; start < n; start++) {
    for (int i = 0; i < n; i++) {
      d[i] = -1;
    }
    d[start] = 0;
    int b = 0, e = 1;
    x[0] = start;
    while (b < e) {
      int sz = g[x[b]].size();
      for (int j = 0; j < sz; j++) {
        int u = g[x[b]][j];
        if (d[u] == -1) {
          d[u] = d[x[b]] + 1;
          x[e++] = u;
        }
      }
      b++;
    }
    int sz = gr[start].size();
    int shortest = inf;
    for (int j = 0; j < sz; j++) {
      int u = gr[start][j];
      if (d[u] != -1) {
        shortest = min(shortest, d[u] + 1);
      }
    }
    value[start] = shortest;
  }
  for (int i = 0; i < nc; i++) {
    best[i] = inf;
    who[i].clear();
  }
  for (int i = 0; i < n; i++) {
    best[comp[i]] = min(best[comp[i]], value[i]);
    who[comp[i]].push_back(i);
  }
  int ans = n;
  for (int i = 0; i < nc; i++) {
    bool is_sink = true;
    int sz = who[i].size();
    for (int j = 0; j < sz; j++) {
      int v = who[i][j];
      int z = g[v].size();
      for (int q = 0; q < z; q++) {
        int u = g[v][q];
        if (comp[u] != comp[v]) {
          is_sink = false;
          break;
        }
      }
      if (!is_sink) {
        break;
      }
    }
    if (is_sink) {
      if (best[i] != inf) {
        ans += 998 * best[i] + 1;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}