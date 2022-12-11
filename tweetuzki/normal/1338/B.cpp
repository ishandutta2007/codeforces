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

const int MaxN = 100000;

struct Graph {
  int cnte;
  int Head[MaxN + 5], To[MaxN * 2 + 5], Next[MaxN * 2 + 5];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N;
int Dep[MaxN + 5], Deg[MaxN + 5], HaveLeaf[MaxN + 5];
Graph G;

void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G.addEdge(u, v);
    G.addEdge(v, u);
    Deg[u]++, Deg[v]++;
  }
}

void dfs(int u, int f) {
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == f) continue;
    Dep[v] = Dep[u] + 1;
    dfs(v, u);
  }
}

void solve() {
  dfs(1, 0);
  bool haveOddLeaf = false, haveEvenLeaf = false;
  for (int i = 1; i <= N; ++i) {
    if (Deg[i] != 1) continue;
    if (Dep[i] & 1) haveOddLeaf = true;
    else haveEvenLeaf = true;
  }
  if (haveOddLeaf && haveEvenLeaf) printf("%d ", 3);
  else printf("%d ", 1);
  int locked = 0;
  for (int i = 1; i <= N; ++i) {
    if (Deg[i] != 1) continue;
    int v = G.To[G.Head[i]];
    HaveLeaf[v]++;
  }
  for (int i = 1; i <= N; ++i)
    if (HaveLeaf[i] != 0) locked += HaveLeaf[i] - 1;
  printf("%d\n", N - 1 - locked);
}

int main() {
  init();
  solve();
  return 0;
}