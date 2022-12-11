#include <cstdio>

const int MaxN = 1000000 + 5;

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxN * 2], Next[MaxN * 2];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N;
int Fa[MaxN], Dep[MaxN], Mxd[MaxN], Wson[MaxN];
int Id[MaxN], Dfc;
int Ans[MaxN], Dp[MaxN];
Graph G;

void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G.addEdge(u, v);
    G.addEdge(v, u);
  }
}

void dfs1(int u) {
  Mxd[u] = Dep[u];
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u]) continue;
    Fa[v] = u;
    Dep[v] = Dep[u] + 1;
    dfs1(v);
    if (Mxd[v] > Mxd[u]) {
      Mxd[u] = Mxd[v];
      Wson[u] = v;
    }
  }
}

void dfs2(int u) {
  Id[u] = ++Dfc;
  if (Wson[u] != 0) dfs2(Wson[u]);
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u] || v == Wson[u]) continue;
    dfs2(v);
  }
}

inline int f(int u, int k) {
  return Dp[Id[u] + k];
}

void dfs4(int u, int d, int top) {
  Dp[Id[top] + d]++;
  if (f(top, d) > f(top, Ans[top]) || (f(top, d) == f(top, Ans[top]) && d < Ans[top])) Ans[top] = d;
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u]) continue;
    dfs4(v, d + 1, top);
  }
}

void dfs3(int u) {
  Dp[Id[u]] = 1; Ans[u] = 0;
  if (Wson[u] == 0) return;
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u]) continue;
    dfs3(v);
  }
  if (f(Wson[u], Ans[Wson[u]]) > f(u, 0)) Ans[u] = Ans[Wson[u]] + 1;
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u] || v == Wson[u]) continue;
    dfs4(v, 1, u);
  }
}

void solve() {
  dfs1(1); dfs2(1); dfs3(1);
  for (int i = 1; i <= N; ++i) printf("%d\n", Ans[i]);
}

int main() {
  init();
  solve();
  return 0;
}