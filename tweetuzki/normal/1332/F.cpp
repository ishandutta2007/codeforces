#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
 
const int MaxN = 300000;
const int Mod = 998244353;
 
struct Graph {
  int cnte;
  int Head[MaxN + 5], To[MaxN * 2 + 5], Next[MaxN * 2 + 5];
 
  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};
 
int N;
int Fa[MaxN + 5], F[MaxN + 5][2][2];
Graph Gr;
 
inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline int pw(int x, int y) { int z = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) z = mul(z, x); return z; }
inline int inv(int x) { return pw(x, Mod - 2); }
inline int sep(int x, int y) { return mul(x, inv(y)); }
inline void inc(int &x, int y = 1) { x = add(x, y); }
inline void dec(int &x, int y = 1) { x = sub(x, y); }
 
void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr.addEdge(u, v);
    Gr.addEdge(v, u);
  }
}
 
void dfs(int u) {
  F[u][0][1] = F[u][1][1] = 1;
  for (int i = Gr.Head[u]; i; i = Gr.Next[i]) {
    int v = Gr.To[i];
    if (v == Fa[u]) continue;
    Fa[v] = u;
    dfs(v);
    int f[2][2];
    f[0][0] = F[u][0][0], f[0][1] = F[u][0][1], f[1][0] = F[u][1][0], f[1][1] = F[u][1][1];
    F[u][0][0] = add(mul(f[0][0], add(add(mul(F[v][0][0], 2), mul(F[v][0][1], 2)), add(mul(F[v][1][0], 2), F[v][1][1]))), mul(f[0][1], add(add(F[v][0][0], F[v][0][1]), add(F[v][1][0], F[v][1][1]))));
    F[u][0][1] = mul(f[0][1], add(add(F[v][0][0], F[v][1][0]), F[v][0][1]));
    F[u][1][0] = add(mul(f[1][0], add(add(mul(F[v][0][0], 2), mul(F[v][0][1], 2)), F[v][1][0])), mul(f[1][1], add(F[v][0][0], F[v][0][1])));
    F[u][1][1] = mul(f[1][1], add(add(F[v][0][0], F[v][1][0]), F[v][0][1]));
  }
}
 
void solve() {
  dfs(1);
  printf("%d\n", sub(add(add(F[1][0][0], F[1][1][0]), F[1][0][1]), 1));
}
 
int main() {
  init();
  solve();
  return 0;
}