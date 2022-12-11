#include <cstdio>

const int MaxN = 100000 + 5;
const int S = 400, Nums = MaxN / S + 5;

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxN], Next[MaxN];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, M;
int A[MaxN]; bool Col[MaxN];
int Fa[MaxN], Dep[MaxN], Siz[MaxN], Wson[MaxN];
int Id[MaxN], Dfn[MaxN], Top[MaxN], Dfc;
int Bel[MaxN], L[Nums], R[Nums], Tag[Nums], Ans[Nums];
int Cnt[Nums][MaxN + MaxN];
Graph G;

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 2; i <= N; ++i) {
    scanf("%d", &Fa[i]);
    G.addEdge(Fa[i], i);
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    A[i] += N;
  }
}

void dfs1(int u) {
  Siz[u] = 1;
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    Fa[v] = u;
    Dep[v] = Dep[u] + 1;
    dfs1(v);
    Siz[u] += Siz[v];
    if (Siz[v] > Siz[Wson[u]]) Wson[u] = v;
  }
}

void dfs2(int u, int chain) {
  Id[u] = ++Dfc, Dfn[Dfc] = u;
  Top[u] = chain;
  if (Wson[u] != 0) dfs2(Wson[u], chain);
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Wson[u]) continue;
    dfs2(v, v);
  }
}

inline void clear(int x) {
  Ans[x] = 0;
  for (int i = L[x]; i <= R[x]; ++i) {
    Cnt[x][A[Dfn[i]]] = 0;
    A[Dfn[i]] += Tag[x];
  }
  Tag[x] = 0;
}

inline void rebuild(int x) {
  for (int i = L[x]; i <= R[x]; ++i) {
    if (Col[Dfn[i]] == true) continue;
    Cnt[x][A[Dfn[i]]]++;
    if (A[Dfn[i]] < N) Ans[x]++;
  }
}

inline void add(int l, int r) {
  int u = Bel[l], v = Bel[r];
  if (u == v) {
    clear(u);
    for (int i = l; i <= r; ++i) A[Dfn[i]]++;
    rebuild(u);
  } else {
    clear(u);
    for (int i = l; i <= R[u]; ++i) A[Dfn[i]]++;
    rebuild(u);
    clear(v);
    for (int i = L[v]; i <= r; ++i) A[Dfn[i]]++;
    rebuild(v);

    for (int i = u + 1; i < v; ++i) {
      Tag[i]++;
      Ans[i] -= Cnt[i][N - Tag[i]];
    }
  }
}

inline void del(int l, int r) {
  int u = Bel[l], v = Bel[r];
  if (u == v) {
    clear(u);
    for (int i = l; i <= r; ++i) A[Dfn[i]]--;
    rebuild(u);
  } else {
    clear(u);
    for (int i = l; i <= R[u]; ++i) A[Dfn[i]]--;
    rebuild(u);
    clear(v);
    for (int i = L[v]; i <= r; ++i) A[Dfn[i]]--;
    rebuild(v);

    for (int i = u + 1; i < v; ++i) {
      Ans[i] += Cnt[i][N - Tag[i]];
      Tag[i]--;
    }
  }
}

inline void access(int u, bool f) {
  Col[u] = f;
  while (u != 0) {
    if (f == false) add(Id[Top[u]], Id[u]);
    else del(Id[Top[u]], Id[u]);
    u = Fa[Top[u]];
  }
}

void solve() {
  dfs1(1); dfs2(1, 1);
  for (int i = 1; i <= N; ++i) {
    Bel[i] = (i - 1) / S + 1;
    if (L[Bel[i]] == 0) L[Bel[i]] = i;
    R[Bel[i]] = i;
  }
  for (int i = 1; i <= Bel[N]; ++i) rebuild(i);
  for (int q = 1; q <= M; ++q) {
    int u; scanf("%d", &u);
    if (u < 0) access(-u, false);
    else access(u, true);
    int ans = 0;
    for (int i = 1; i <= Bel[N]; ++i) ans += Ans[i];
    printf("%d%c", ans, q == M ? '\n' : ' ');
  }
}

int main() {
  init();
  solve();
  return 0;
}