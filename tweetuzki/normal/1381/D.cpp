#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 100000, MaxLog = 17;

struct graph_t {
  int cnte;
  int head[MaxN + 5], to[MaxN * 2 + 5], next[MaxN * 2 + 5];

  inline void clear() {
    cnte = 0;
    memset(head, 0, sizeof head);
    memset(to, 0, sizeof to);
    memset(next, 0, sizeof next);
  }

  inline void addEdge(int u, int v) {
    cnte++; to[cnte] = v;
    next[cnte] = head[u]; head[u] = cnte;
  }
};

int Te, N, Pos_A, Pos_B, L;
int Mx[MaxN + 5], Mmx[MaxN + 5], Mmmx[MaxN + 5], Mupx[MaxN + 5];
int Fa[MaxLog + 1][MaxN + 5], Dep[MaxN + 5], Deepest[MaxN + 5];
graph_t Gr;

void init() {
  scanf("%d %d %d", &N, &Pos_A, &Pos_B);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr.addEdge(u, v);
    Gr.addEdge(v, u);
  }
}

void dfs_getL(int u, int f, int d) {
  if (u == Pos_B) {
    L = d;
    return;
  }
  for (int i = Gr.head[u]; i; i = Gr.next[i]) {
    int v = Gr.to[i];
    if (v == f) continue;
    dfs_getL(v, u, d + 1);
  }
}

void dfs1(int u, int f) {
  for (int i = Gr.head[u]; i; i = Gr.next[i]) {
    int v = Gr.to[i];
    if (v == f) continue;
    dfs1(v, u);
    if (Mx[v] + 1 > Mx[u]) {
      Mmmx[u] = Mmx[u];
      Mmx[u] = Mx[u];
      Mx[u] = Mx[v] + 1;
    } else if (Mx[v] + 1 > Mmx[u]) {
      Mmmx[u] = Mmx[u];
      Mmx[u] = Mx[v] + 1;
    } else if (Mx[v] + 1 > Mmmx[u]) {
      Mmmx[u] = Mx[v] + 1;
    }
  }
}

void dfs2(int u, int f) {
  for (int i = Gr.head[u]; i; i = Gr.next[i]) {
    int v = Gr.to[i];
    if (v == f) continue;
    if (Mx[v] + 1 == Mx[u]) Mupx[v] = std::max(Mupx[u], Mmx[u]) + 1;
    else Mupx[v] = std::max(Mupx[u], Mx[u]) + 1;
    dfs2(v, u);
  }
}

void dfs3(int u) {
  Deepest[u] = u;
  for (int i = Gr.head[u]; i; i = Gr.next[i]) {
    int v = Gr.to[i];
    if (v == Fa[0][u]) continue;
    Dep[v] = Dep[u] + 1;
    Fa[0][v] = u;
    for (int j = 1; (1 << j) <= Dep[v]; ++j)
      Fa[j][v] = Fa[j - 1][Fa[j - 1][v]];
    dfs3(v);
    if (Dep[Deepest[v]] > Dep[Deepest[u]])
      Deepest[u] = Deepest[v];
  }
}

inline int kthAncestor(int u, int k) {
  for (int i = MaxLog; i >= 0; --i)
    if (k & (1 << i)) u = Fa[i][u];
  return u;
}

inline bool isAncestor(int u, int v) {
  if (Dep[u] < Dep[v]) std::swap(u, v);
  return kthAncestor(u, Dep[u] - Dep[v]) == v;
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
  dfs_getL(Pos_A, 0, 0);
  // printf("L = %d\n", L);
  dfs1(1, 0);
  dfs2(1, 0);
  // for (int i = 1; i <= N; ++i)
  //   printf("i = %d, mx = %d, mmx = %d, mmmx = %d, mupx = %d\n", i, Mx[i], Mmx[i], Mmmx[i], Mupx[i]);
  int pivot = 0;
  for (int i = 1; i <= N; ++i) {
    int cnt = 0;
    if (Mx[i] >= L) cnt++;
    if (Mmx[i] >= L) cnt++;
    if (Mmmx[i] >= L) cnt++;
    if (Mupx[i] >= L) cnt++;
    if (cnt >= 3) {
      // printf("%d is a valid pivot\n", i);
      pivot = i;
    }
  }
  if (pivot == 0) {
    puts("NO");
    return;
  }
  dfs3(pivot);
  int a = Pos_A, b = Pos_B, lca = getLca(a, b);
  int maxdepa = Dep[a], maxdepb = Dep[b];
  for (;;) {
    if (isAncestor(a, b) == true) {
      puts("YES");
      return;
    }
    if (Dep[Deepest[a]] > maxdepa) {
      int pace = Dep[Deepest[a]] - Dep[a];
      a = Deepest[a];
      if (pace >= Dep[b] - Dep[lca]) {
        puts("YES");
        return;
      } else b = kthAncestor(b, pace);
      maxdepa = Dep[a];
    } else if (Dep[Deepest[b]] > maxdepb) {
      int pace = Dep[Deepest[b]] - Dep[b];
      b = Deepest[b];
      if (pace >= Dep[a] - Dep[lca]) {
        puts("YES");
        return;
      } else a = kthAncestor(a, pace);
      maxdepb = Dep[b];
    } else {
      puts("NO");
      return;
    }
  }
}

void clear() {
  N = Pos_A = Pos_B = L = 0;
  memset(Mx, 0, sizeof Mx);
  memset(Mmx, 0, sizeof Mmx);
  memset(Mmmx, 0, sizeof Mmmx);
  memset(Mupx, 0, sizeof Mupx);
  memset(Fa, 0, sizeof Fa);
  memset(Dep, 0, sizeof Dep);
  memset(Deepest, 0, sizeof Deepest);
  Gr.clear();
}

int main() {
  scanf("%d", &Te);
  for (int t = 1; t <= Te; ++t) {
    init();
    solve();
    clear();
  }
  return 0;
}