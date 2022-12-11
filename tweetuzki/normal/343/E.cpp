#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 200, MaxM = 1000;
const int INF = 0x7F7F7F7F;

struct edge_t {
  int u, v, w;
  edge_t(int _u = 0, int _v = 0, int _w = 0) { u = _u, v = _v, w = _w; }
  inline friend bool operator<(const edge_t &a, const edge_t &b) { return a.w > b.w; }
};

int N, M, E;
int U[MaxM + 5], V[MaxM + 5], W[MaxM + 5];
int Lnk[MaxN + 5];
int Par[MaxN * 2 + 5], Lson[MaxN * 2 + 5], Rson[MaxN * 2 + 5], Stk[MaxN + 5], Tp;
edge_t T[MaxN + 5];

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i) scanf("%d %d %d", &U[i], &V[i], &W[i]);
}

namespace Dinic {

struct Graph {
  int cnte;
  int Head[MaxN + 5], To[MaxM * 4 + 5], Next[MaxM * 4 + 5], Cap[MaxM * 4 + 5];

  inline void init() {
    cnte = 1;
    memset(Head, 0, sizeof Head);
    memset(To, 0, sizeof To);
    memset(Next, 0, sizeof Next);
    memset(Cap, 0, sizeof Cap);
  }

  inline void add_edge(int from, int to, int cap) {
    cnte++; To[cnte] = to; Cap[cnte] = cap;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }

  inline void addEdge(int from, int to, int cap) {
    add_edge(from, to, cap);
    add_edge(to, from, 0);
  }
};

int Level[MaxN + 5], Iter[MaxN + 5];
Graph Gr;

void build() {
  Gr.init();
  for (int i = 1; i <= M; ++i) {
    Gr.addEdge(U[i], V[i], W[i]);
    Gr.addEdge(V[i], U[i], W[i]);
  }
}

void bfs(int s) {
  static int que[MaxN + 5];
  int head = 1, tail = 0;
  Level[s] = 0;
  que[++tail] = s;
  while (head <= tail) {
    int u = que[head++];
    for (int i = Gr.Head[u]; i; i = Gr.Next[i]) {
      if (Gr.Cap[i] == 0) continue;
      int v = Gr.To[i];
      if (Level[v] < 0) {
        Level[v] = Level[u] + 1;
        que[++tail] = v;
      }
    }
  }
}

int dfs(int u, int t, int f) {
  if (u == t) return f;
  for (int &i = Iter[u]; i; i = Gr.Next[i]) {
    int v = Gr.To[i], w = Gr.Cap[i];
    if (w == 0) continue;
    if (Level[u] < Level[v]) {
      int d = dfs(v, t, std::min(f, w));
      if (d > 0) {
        Gr.Cap[i] -= d;
        Gr.Cap[i ^ 1] += d;
        return d;
      }
    }
  }
  return 0;
}

int maxFlow(int s, int t) {
  int flow = 0;
  for (;;) {
    memset(Level, -1, sizeof Level);
    bfs(s);
    if (Level[t] < 0) break;
    memcpy(Iter, Gr.Head, sizeof Gr.Head);
    for (;;) {
      int f = dfs(s, t, INF);
      if (f == 0) break;
      flow += f;
    }
  }
  return flow;
}

}

void fun(int l, int r) {
  if (l == r) return;
  int s = Lnk[l], t = Lnk[l + 1];
  Dinic::build();
  int w = Dinic::maxFlow(s, t);
  T[++E] = edge_t(s, t, w);
  static int tmp1[MaxN + 5], tmp2[MaxN + 5];
  int cnt1 = 0, cnt2 = 0;
  for (int i = l; i <= r; ++i)
    if (Dinic::Level[Lnk[i]] >= 0) tmp1[++cnt1] = Lnk[i];
    else tmp2[++cnt2] = Lnk[i];
  for (int i = l; i <= l + cnt1 - 1; ++i) Lnk[i] = tmp1[i - l + 1];
  for (int i = l + cnt1; i <= r; ++i) Lnk[i] = tmp2[i - l - cnt1 + 1];
  fun(l, l + cnt1 - 1);
  fun(l + cnt1, r);
}

int find(int x) { return x == Par[x] ? x : Par[x] = find(Par[x]); }

void dfs(int u) {
  if (u <= N) {
    Stk[++Tp] = u;
    return;
  }
  dfs(Lson[u]);
  dfs(Rson[u]);
}

void solve() {
  for (int i = 1; i <= N; ++i) Lnk[i] = i;
  fun(1, N);
  std::sort(T + 1, T + 1 + E);
  int sum = 0;
  for (int i = 1; i <= N; ++i) Par[i] = i;
  int cnt = N;
  for (int i = 1; i <= E; ++i) {
    int u = find(T[i].u), v = find(T[i].v);
    sum += T[i].w;
    cnt++;
    Par[u] = Par[v] = Par[cnt] = cnt;
    Lson[cnt] = u, Rson[cnt] = v;
  }
  dfs(cnt);
  printf("%d\n", sum);
  for (int i = 1; i <= Tp; ++i) printf("%d%c", Stk[i], " \n"[i == Tp]);
}

int main() {
  init();
  solve();
  return 0;
}