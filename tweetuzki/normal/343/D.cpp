#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 500000;
const int MaxV = (1 << 20);

struct Graph {
  int cnte;
  int Head[MaxN + 5], To[MaxN * 2 + 5], Next[MaxN * 2 + 5];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, Q;
int Fa[MaxN + 5], Id[MaxN + 5], Siz[MaxN + 5], Dfc;
int Mx[MaxV + 5], Tag[MaxV + 5];
Graph Gr;

void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr.addEdge(u, v);
    Gr.addEdge(v, u);
  }
  scanf("%d", &Q);
}

void dfs(int u) {
  Id[u] = ++Dfc;
  Siz[u] = 1;
  for (int i = Gr.Head[u]; i; i = Gr.Next[i]) {
    int v = Gr.To[i];
    if (v == Fa[u]) continue;
    Fa[v] = u;
    dfs(v);
    Siz[u] += Siz[v];
  }
}

void updatePos(int pos, int val, int i = 1, int l = 1, int r = N) {
  Mx[i] = val;
  if (l == r) return;
  int m = (l + r) >> 1;
  if (pos <= m) updatePos(pos, val, i << 1, l, m);
  else updatePos(pos, val, i << 1 | 1, m + 1, r);
}

void updateRange(int left, int right, int val, int i = 1, int l = 1, int r = N) {
  if (left == l && right == r) {
    Tag[i] = val;
    return;
  }
  int m = (l + r) >> 1;
  if (right <= m) updateRange(left, right, val, i << 1, l, m);
  else if (left > m) updateRange(left, right, val, i << 1 | 1, m + 1, r);
  else updateRange(left, m, val, i << 1, l, m), updateRange(m + 1, right, val, i << 1 | 1, m + 1, r);
}

int queryPos(int pos, int i = 1, int l = 1, int r = N) {
  int res = Tag[i];
  if (l == r) return res;
  int m = (l + r) >> 1;
  if (pos <= m) res = std::max(res, queryPos(pos, i << 1, l, m));
  else res = std::max(res, queryPos(pos, i << 1 | 1, m + 1, r));
  return res;
}

int queryRange(int left, int right, int i = 1, int l = 1, int r = N) {
  if (left == l && right == r) return Mx[i];
  int m = (l + r) >> 1;
  if (right <= m) return queryRange(left, right, i << 1, l, m);
  else if (left > m) return queryRange(left, right, i << 1 | 1, m + 1, r);
  else return std::max(queryRange(left, m, i << 1, l, m), queryRange(m + 1, right, i << 1 | 1, m + 1, r));
}

void solve() {
  dfs(1);
  for (int q = 1; q <= Q; ++q) {
    int opt, x;
    scanf("%d %d", &opt, &x);
    if (opt == 1) updateRange(Id[x], Id[x] + Siz[x] - 1, q);
    else if (opt == 2) updatePos(Id[x], q);
    else {
      int emptyTime = queryRange(Id[x], Id[x] + Siz[x] - 1), fillTime = queryPos(Id[x]);
      if (emptyTime < fillTime) puts("1");
      else puts("0");
    }
  }
}

int main() {
  init();
  solve();
  return 0;
}