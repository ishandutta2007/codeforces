#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 300000, MaxM = 300000;

int N, M, K, V, Rt;
bool Special[MaxN + 5];
int C[MaxN + 5];
struct edge_t { int u, v, w; } E[MaxM + 5];
std::vector<int> Gr[MaxN + 5];

template <typename Int>
inline void tense(Int &x, Int y) { if (y > x) x = y; }
template <typename Int>
inline void relax(Int &x, Int y) { if (y < x) x = y; }

void init() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 1; i <= K; ++i) {
    int u;
    scanf("%d", &u);
    Special[u] = true;
  }
  for (int i = 1; i <= N; ++i) scanf("%d", &C[i]);
  for (int i = 1; i <= M; ++i) scanf("%d", &E[i].w);
  for (int i = 1; i <= M; ++i) {
    scanf("%d %d", &E[i].u, &E[i].v);
    Gr[E[i].u].push_back(E[i].v);
    Gr[E[i].v].push_back(E[i].u);
  }
}

int low[MaxN + 5], dfn[MaxN + 5], dfc;
int stk[MaxN + 5], tp;
int bel[MaxN + 5];

long long A[MaxN + 5], B[MaxN + 5];
bool O[MaxN + 5];
int SumO[MaxN + 5];
std::vector< std::pair<int, int> > Tr[MaxN + 5];

void tarjan(int u, int f) {
  low[u] = dfn[u] = ++dfc;
  stk[++tp] = u;
  for (int v : Gr[u]) {
    if (v == f) continue;
    if (dfn[v] == 0) {
      tarjan(v, u);
      relax(low[u], low[v]);
    } else relax(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    V++;
    for (;;) {
      int v = stk[tp--];
      bel[v] = V;
      A[V] += C[v];
      O[V] |= Special[v];
      if (v == u) break;
    }
  }
}

int Par[MaxN + 5];
int find(int x) { return x == Par[x] ? x : Par[x] = find(Par[x]); }

void dfs1(int u, int f) {
  SumO[u] = O[u];
  B[u] = A[u];
  for (auto e : Tr[u]) {
    int v = e.first;
    if (v == f) continue;
    dfs1(v, u);
    SumO[u] += SumO[v];
    if (SumO[v] == 0) {
      Par[v] = u;
      B[u] += B[v];
    }
  }
}

void getBcc() {
  tarjan(1, 0);
  for (int i = 1; i <= M; ++i) {
    int u = E[i].u, v = E[i].v, w = E[i].w;
    u = bel[u], v = bel[v];
    if (u != v) {
      Tr[u].emplace_back(v, w);
      Tr[v].emplace_back(u, w);
    }
  }
  Rt = 0;
  for (int i = 1; i <= V; ++i)
    if (O[i] == true) Rt = i;
  for (int i = 1; i <= V; ++i) Par[i] = i;
  dfs1(Rt, 0);
}

long long F[MaxN + 5];
long long Ans[MaxN + 5];

void dfs2(int u, int f) {
  // printf("dfs2(%d, %d)\n", u, f);
  F[u] = B[u];
  for (auto e : Tr[u]) {
    int v = e.first, w = e.second;
    if (v == f || SumO[v] == 0) continue;
    dfs2(v, u);
    if (F[v] - w > 0) F[u] += F[v] - w;
  }
}

void dfs3(int u, int f) {
  Ans[u] = F[u];
  for (auto e : Tr[u]) {
    int v = e.first, w = e.second;
    if (v == f || SumO[v] == 0) continue;
    F[u] -= std::max(0LL, F[v] - w);
    F[v] += std::max(0LL, F[u] - w);
    dfs3(v, u);
    F[v] -= std::max(0LL, F[u] - w);
    F[u] += std::max(0LL, F[v] - w);
  }
}

void solve() {
  getBcc();
  dfs2(Rt, 0);
  dfs3(Rt, 0);
  // for (int i = 1; i <= N; ++i)
  //   printf("i = %d, bel = %d, o = %d, a = %lld\n", i, bel[i], O[bel[i]], A[bel[i]]);
  for (int i = 1; i <= N; ++i) {
    int id = find(bel[i]);
    // printf("id = %d\n", id);
    printf("%lld%c", Ans[id], " \n"[i == N]);
  }
}

int main() {
  init();
  solve();
  return 0;
}
/*
3 2 2
1 2
11 1 5
10 10
1 2
2 3
*/