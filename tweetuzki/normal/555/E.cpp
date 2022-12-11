#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 200000, MaxM = 200000, MaxQ = 200000;
const int MaxV = 200000, MaxLog = 18;

struct Graph {
  int cnte;
  int Head[MaxN + 5], To[MaxM * 2 + 5], Next[MaxM * 2 + 5];
  Graph() { cnte = 1; }

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

struct DSU {
  int par[MaxV + 5];
  void init() { for (int i = 1; i <= MaxV; ++i) par[i] = i; }
  int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
};

int N, M, Q, V;
int St[MaxQ + 5], Ed[MaxQ + 5];
int Low[MaxN + 5], Dfn[MaxN + 5], Dfc;
int Bel[MaxN + 5], Stk[MaxN + 5], Tp;
int Fa[MaxLog + 1][MaxV + 5], Tof[MaxV + 5], Dep[MaxV + 5];
DSU D1, D2;
Graph Gr, Tr;

void init() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr.addEdge(u, v);
    Gr.addEdge(v, u);
  }
  for (int i = 1; i <= Q; ++i) scanf("%d %d", &St[i], &Ed[i]);
}

void tarjan(int u, int fe) {
  Low[u] = Dfn[u] = ++Dfc;
  Stk[++Tp] = u;
  for (int i = Gr.Head[u]; i; i = Gr.Next[i]) {
    if ((i ^ fe) == 1) continue;
    int v = Gr.To[i];
    if (Dfn[v] == 0) {
      tarjan(v, i);
      Low[u] = std::min(Low[u], Low[v]);
      if (Low[v] > Dfn[u]) {
        V++;
        do {
          int x = Stk[Tp--];
          Bel[x] = V;
        } while (Stk[Tp + 1] != v);
      }
    } else Low[u] = std::min(Low[u], Dfn[v]);
  }
}

void dfs(int u) {
  for (int i = Tr.Head[u]; i; i = Tr.Next[i]) {
    int v = Tr.To[i];
    if (v == Fa[0][u]) continue;
    Fa[0][v] = u;
    Tof[v] = i;
    Dep[v] = Dep[u] + 1;
    for (int j = 1; (1 << j) <= Dep[v]; ++j)
      Fa[j][v] = Fa[j - 1][Fa[j - 1][v]];
    dfs(v);
  }
}

inline int getLca(int u, int v) {
  if (Dep[u] < Dep[v]) std::swap(u, v);
  int d = Dep[u] - Dep[v];
  for (int i = MaxLog; i >= 0; --i)
    if (d & (1 << i)) u = Fa[i][u];
  if (u == v) return u;
  for (int i = MaxLog; i >= 0; --i)
    if (Fa[i][u] != Fa[i][v]) {
      u = Fa[i][u];
      v = Fa[i][v];
    }
  return Fa[0][u];
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    if (Dfn[i] != 0) continue;
    tarjan(i, 0);
    V++;
    while (Tp > 0) {
      int x = Stk[Tp--];
      Bel[x] = V;
    }
  }
  // for (int i = 1; i <= N; ++i)
  //   printf("Bel[%d] = %d\n", i, Bel[i]);
  for (int u = 1; u <= N; ++u)
    for (int i = Gr.Head[u]; i; i = Gr.Next[i]) {
      int v = Gr.To[i];
      if (Bel[u] == Bel[v]) continue;
      Tr.addEdge(Bel[u], Bel[v]);
    }
  for (int i = 1; i <= V; ++i)
    if (Fa[0][i] == 0) dfs(i);
  D1.init(), D2.init();
  for (int i = 1; i <= Q; ++i) {
    int u = Bel[St[i]], v = Bel[Ed[i]], lca = getLca(u, v);
    if (lca == 0) {
      puts("No");
      return;
    }
    for (int x = D1.find(u); Dep[x] > Dep[lca]; x = D1.find(x)) D1.par[x] = Fa[0][x];
    for (int x = D2.find(v); Dep[x] > Dep[lca]; x = D2.find(x)) D2.par[x] = Fa[0][x];
  }
  for (int i = 1; i <= V; ++i)
    if (D1.find(i) != i && D2.find(i) != i) {
      puts("No");
      return;
    }
  puts("Yes");
}

int main() {
  init();
  solve();
  return 0;
}