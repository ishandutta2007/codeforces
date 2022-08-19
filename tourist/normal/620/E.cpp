#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

vector <int> g[N];
int pos[N], to[N];
int kw = 0, w[N];

void dfs(int v, int pr) {
  pos[v] = kw;
  w[kw++] = v;
  for (int j = 0; j < (int) g[v].size(); j++) {
    int u = g[v][j];
    if (u != pr) {
      dfs(u, v);
    }
  }
  to[v] = kw - 1;
}

long long a[4 * N];
bool put[4 * N];
int color[N];

void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    a[x] = a[x + x] | a[x + x + 1];
    put[x] = false;
  } else {
    a[x] = 1LL << color[w[l]];
    put[x] = true;
  }
}

inline void push(int x) {
  if (put[x]) {
    a[x + x] = a[x + x + 1] = a[x];
    put[x + x] = put[x + x + 1] = true;
    put[x] = false;
  }
}

inline void gather(int x) {
  a[x] = a[x + x] | a[x + x + 1];
}

void modify(int x, int l, int r, int ll, int rr, long long v) {
  if (r < ll || rr < l) {
    return;
  }
  if (ll <= l && r <= rr) {
    a[x] = v;
    put[x] = true;
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  modify(x + x, l, y, ll, rr, v);
  modify(x + x + 1, y + 1, r, ll, rr, v);
  gather(x);
}

long long get(int x, int l, int r, int ll, int rr) {
  if (r < ll || rr < l) {
    return 0;
  }
  if (ll <= l && r <= rr) {
    return a[x];
  }
  push(x);
  int y = (l + r) >> 1;
  long long res = get(x + x, l, y, ll, rr);
  res |= get(x + x + 1, y + 1, r, ll, rr);
  gather(x);
  return res;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", color + i);
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
  dfs(0, -1);
  build(1, 0, n - 1);
  while (m--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int foo, bar;
      scanf("%d %d", &foo, &bar);
      foo--;
      modify(1, 0, n - 1, pos[foo], to[foo], 1LL << bar);
    } else {
      int foo;
      scanf("%d", &foo);
      foo--;
      long long value = get(1, 0, n - 1, pos[foo], to[foo]);
      printf("%d\n", __builtin_popcountll(value));
    }
  }
  return 0;
}