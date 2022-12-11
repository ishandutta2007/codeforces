#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;
const int MaxLog = 20;

struct Graph {
  int cnte;
  int Head[MaxN], Next[MaxN * 2], To[MaxN * 2];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N;
int Ind[MaxN];
int Fa[MaxLog + 1][MaxN], Dep[MaxN];
int F[MaxN], L[MaxN];
int dep[MaxN], fa[MaxN];
vector<int> vec[MaxN];
Graph G;

void init() {
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Ind[u]++; Ind[v]++;
    G.addEdge(u, v);
    G.addEdge(v, u);
  }
}

void buildTree(int u) {
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[0][u]) continue;
    Dep[v] = Dep[u] + 1;
    Fa[0][v] = u;
    for (int j = 1; (1 << j) <= Dep[v]; ++j)
      Fa[j][v] = Fa[j - 1][Fa[j - 1][v]];
    buildTree(v);
  }
}

inline int getLca(int u, int v) {
  if (Dep[u] < Dep[v]) std::swap(u, v);
  int d = Dep[u] - Dep[v];
  for (int i = MaxLog; i >= 0; --i)
    if (d & (1 << i)) u = Fa[i][u];
  if (u == v) return u;
  for (int i = MaxLog; i >= 0; --i) {
    if (Fa[i][u] != Fa[i][v]) {
      u = Fa[i][u];
      v = Fa[i][v];
    }
  }
  return Fa[0][u];
}

inline void findTreeDist(int &u, int &v) {
  int s = 1;
  static int dis[MaxN];
  memset(dis, 0x7F, sizeof dis);
  queue<int> que;
  que.push(s); dis[s] = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = G.Head[x]; i; i = G.Next[i]) {
      int y = G.To[i];
      if (dis[x] + 1 < dis[y]) {
        dis[y] = dis[x] + 1;
        que.push(y);
      }
    }
  }

  u = 1;
  for (int i = 2; i <= N; ++i)
    if (dis[i] > dis[u]) u = i;

  s = u; memset(dis, 0x7F, sizeof dis);
  que.push(s); dis[s] = 0;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = G.Head[x]; i; i = G.Next[i]) {
      int y = G.To[i];
      if (dis[x] + 1 < dis[y]) {
        dis[y] = dis[x] + 1;
        que.push(y);
      }
    }
  }

  v = 1;
  for (int i = 2; i <= N; ++i)
    if (dis[i] > dis[v]) v = i;
}

inline int getDis(int u, int v) {
  int Lca = getLca(u, v);
  return Dep[u] + Dep[v] - 2 * Dep[Lca];
}

void dfs(int u) {
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == fa[u]) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs(v);
  }
}

inline bool check(int rt) {
  memset(fa, 0, sizeof fa);
  memset(dep, 0, sizeof dep);
  for (int i = 0; i <= N; ++i) vec[i].clear();
  dfs(rt);
  for (int i = 1; i <= N; ++i)
    vec[dep[i]].push_back(i);
  for (int i = 1; i <= N; ++i) {
    int d = -1;
    for (int v : vec[i]) {
      int dd = Ind[v];
      if (d == -1) d = dd;
      else if (d != dd) return false;
    }
  }
  return true;
}

void findShortestChain(int u, int f) {
  if (Ind[u] == 1) {
    F[u] = 0;
    L[u] = u;
    return;
  }
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == f) continue;
    findShortestChain(v, u);
    if (F[v] != -1 && F[u] == 0) {
      F[u] = F[v] + 1;
      L[u] = L[v];
    } else {
      F[u] = -1;
    }
  }
}

void solve() {
  buildTree(1);
  int x, y;
  findTreeDist(x, y);

  if (check(x) == true) {
    printf("%d\n", x);
    return;
  } else if (check(y) == true) {
    printf("%d\n", y);
    return;
  }
  if (getDis(x, y) & 1) {
    puts("-1");
    return;
  }
  int d = getDis(x, y) / 2;
  if (Dep[x] < Dep[y]) swap(x, y);

  for (int i = 1; i <= d; ++i) x = Fa[0][x];
  findShortestChain(x, 0);
  int mid = x;
  for (int i = G.Head[x]; i; i = G.Next[i]) {
    int u = G.To[i];
    if (F[u] != -1) {
      if (mid == x) mid = u;
      else if (F[u] < F[mid]) mid = u;
    }
  }
  if (mid != x) mid = L[mid];
  if (check(mid) == true) printf("%d\n", mid);
  else puts("-1");
}

int main() {
  init();
  solve();
  return 0;
}