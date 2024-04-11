#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 3000;
const int Mod = 1000000007;

struct graph_t {
  int cnte;
  int head[MaxN + 5], to[MaxN + 5], next[MaxN + 5];

  inline void addEdge(int u, int v) {
    cnte++; to[cnte] = v;
    next[cnte] = head[u]; head[u] = cnte;
  }
};

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, int y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }
inline void inc(int &x, int y = 1) { (x += y) >= Mod ? x -= Mod : 0; }
inline void dec(int &x, int y = 1) { (x -= y) < 0 ? x += Mod : 0; }

int N, D;
int Inv[MaxN + 5];
int F[MaxN + 5][MaxN + 5];
graph_t Gr;

void init() {
  scanf("%d %d", &N, &D);
  for (int i = 2; i <= N; ++i) {
    int f;
    scanf("%d", &f);
    Gr.addEdge(f, i);
  }
  Inv[1] = 1;
  for (int i = 2; i <= N + 1; ++i)
    Inv[i] = mul(Mod - Mod / i, Inv[Mod % i]);
}

void dfs(int u) {
  for (int i = 1; i <= N + 1; ++i) F[u][i] = 1;
  for (int e = Gr.head[u]; e; e = Gr.next[e]) {
    int v = Gr.to[e];
    dfs(v);
    for (int i = 2; i <= N + 1; ++i) inc(F[v][i], F[v][i - 1]);
    for (int i = 1; i <= N + 1; ++i) F[u][i] = mul(F[u][i], F[v][i]);
  }
}

inline int eval(int *f, int n, int x) {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int prod = 1;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      int k;
      if (i > j) k = Inv[i - j];
      else k = sub(0, Inv[j - i]);
      prod = mul(prod, mul(sub(x, j), k));
    }
    inc(res, mul(f[i], prod));
  }
  return res;
}

void solve() {
  dfs(1);
  for (int i = 2; i <= N + 1; ++i) inc(F[1][i], F[1][i - 1]);
  printf("%d\n", eval(F[1], N + 1, D));
}

int main() {
  init();
  solve();
  return 0;
}