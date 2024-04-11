#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

vector <int> g[N];
int a[N];
int pos[N], fin[N];
int kw, w[N];

void dfs(int v, int pr) {
  pos[v] = kw;
  w[kw++] = v;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    dfs(u, v);
  }
  fin[v] = kw - 1;
}

const int M = 1000;

int m;
bitset<M> tree[4 * N];
int shift[4 * N];
bitset<M> all;

void build(int x, int l, int r) {
  shift[x] = 0;
  if (l == r) {
    tree[x] = bitset<M>();
    tree[x].set(a[w[l]]);
    return;
  }
  int y = (l + r) >> 1;
  build(x + x, l, y);
  build(x + x + 1, y + 1, r);
  tree[x] = tree[x + x] | tree[x + x + 1];
}

inline void apply(bitset<M> &b, int sh) {
  b = ((b << sh) & all) | (b >> (m - sh));
}

inline void push(int x) {
  if (shift[x] != 0) {
    shift[x + x] += shift[x];
    if (shift[x + x] >= m) {
      shift[x + x] -= m;
    }
    shift[x + x + 1] += shift[x];
    if (shift[x + x + 1] >= m) {
      shift[x + x + 1] -= m;
    }
    apply(tree[x + x], shift[x]);
    apply(tree[x + x + 1], shift[x]);
    shift[x] = 0;
  }
}

inline void gather(int x) {
  tree[x] = tree[x + x] | tree[x + x + 1];
}

void modify(int x, int l, int r, int ll, int rr, int sh) {
  if (ll <= l && r <= rr) {
    apply(tree[x], sh);
    shift[x] += sh;
    if (shift[x] >= m) {
      shift[x] -= m;
    }
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, sh);
  }
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, sh);
  }
  gather(x);
}

bitset<M> res;

void get(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    res |= tree[x];
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    get(x + x, l, y, ll, rr);
  }
  if (rr > y) {
    get(x + x + 1, y + 1, r, ll, rr);
  }
  gather(x);
}

int main() {
  int n;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] %= m;
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
  kw = 0;
  dfs(0, -1);
  build(1, 0, n - 1);
  bitset<M> primes;
  for (int i = 0; i < m; i++) {
    all.set(i);
  }
  for (int i = 2; i < m; i++) {
    bool prime = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.set(i);
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int type, v;
    scanf("%d %d", &type, &v);
    v--;
    if (type == 1) {
      int shift;
      scanf("%d", &shift);
      shift %= m;
      if (shift == 0) {
        continue;
      }
      modify(1, 0, n - 1, pos[v], fin[v], shift);
    } else {
      res.reset();
      get(1, 0, n - 1, pos[v], fin[v]);
      int ans = (res & primes).count();
      printf("%d\n", ans);
    }
  }
  return 0;
}