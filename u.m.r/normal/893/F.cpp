#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 100000 + 10, S = N * 80;
const int inf = 1e9;

namespace SegmentTree {
  int ls[S], rs[S], mx[S], sz;
  int build(int l, int r, int x, int v) {
    int p = ++ sz;
    ls[p] = rs[p] = 0;
    mx[p] = inf;
    if (l + 1 == r) {
      mx[p] = v;
      return p;
    }
    int mid = (l + r) >> 1;
    if (x < mid) ls[p] = build(l, mid, x, v);
    else rs[p] = build(mid, r, x, v);
    if (ls[p]) {
      mx[p] = std::min(mx[p], mx[ls[p]]);
    }
    if (rs[p]) {
      mx[p] = std::min(mx[p], mx[rs[p]]);
    }
    return p;
  }
  int merge(int x, int y, int l, int r) {
    if (!x) return y; if (!y) return x;
    int p = ++ sz;
    ls[p] = rs[p] = 0;
    mx[p] = inf;
    if (l + 1 == r) {
      mx[p] = std::min(mx[x], mx[y]);
      return p;
    }
    int mid = (l + r) >> 1;
    ls[p] = merge(ls[x], ls[y], l, mid);
    rs[p] = merge(rs[x], rs[y], mid, r);
    if (ls[p]) {
      mx[p] = std::min(mx[p], mx[ls[p]]);
    }
    if (rs[p]) {
      mx[p] = std::min(mx[p], mx[rs[p]]);
    }
    return p;
  }
  int ask(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r) return mx[o];
    int mid = (l + r) >> 1;
    int ret = inf;
    if (L < mid && ls[o]) ret = std::min(ret, ask(ls[o], l, mid, L, R));
    if (R > mid && rs[o]) ret = std::min(ret, ask(rs[o], mid, r, L, R));
    return ret;
  }
}

std::vector<int> edges[N];
int rt[N], w[N];
int root, n;

void dfs(int u, int p = -1, int d = 0) {
  rt[u] = SegmentTree::build(0, n, d, w[u]);
  w[u] = d;
  for (auto &&v: edges[u]) if (v != p) {
    dfs(v, u, d + 1);
    rt[u] = SegmentTree::merge(rt[u], rt[v], 0, n);
  }
}

int main() {
  scanf("%d%d", &n, &root);
  for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  SegmentTree::sz = 0;
  dfs(root - 1);
  int m = 0, last = 0;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int p, q;
    scanf("%d%d", &p, &q);
    int x = (p + last) % n;
    int k = (q + last) % n;
    int l = w[x], r = w[x] + k + 1;
    last = SegmentTree::ask(rt[x], 0, n, l, r);
    printf("%d\n", last);
  }
  return 0;
}