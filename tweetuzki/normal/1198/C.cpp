#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 300000 + 5, MaxM = 1000000 + 5;

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxM], Next[MaxM];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int T, N, M;
bool Vis[MaxN], F[MaxN];
int Match[MaxM], Cnt;
Graph G;

void init() {
  scanf("%d %d", &N, &M);
  N *= 3; G.cnte = 1;
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    G.addEdge(u, v);
    G.addEdge(v, u);
  }
}

void dfs(int u, int d) {
  Vis[u] = true;
  if (d == 0) {
    for (int i = G.Head[u]; i; i = G.Next[i]) {
      int v = G.To[i];
      if (Vis[v] == true && F[v] == true) continue;
      if (F[u] == false) {
        Match[++Cnt] = (i >> 1);
        F[u] = F[v] = true;
        if (Vis[v] == false) dfs(v, 1);
      } else {
        if (Vis[v] == false) dfs(v, 0);
      }
    }
  } else {
    for (int i = G.Head[u]; i; i = G.Next[i]) {
      int v = G.To[i];
      if (Vis[v] == true) continue;
      dfs(v, 0);
    }
  }
}

void solve() {
  for (int i = 1; i <= N; ++i)
    if (Vis[i] == false) dfs(i, 0);
  if (Cnt >= N / 3) {
    puts("Matching");
    for (int i = 1; i <= N / 3; ++i)
      printf("%d%c", Match[i], i == N / 3 ? '\n' : ' ');
  } else {
    puts("IndSet");
    int c = 0;
    for (int i = 1; i <= N; ++i) {
      if (F[i] == false) {
        printf("%d ", i);
        c++;
        if (c == N / 3) {
          puts("");
          return;
        }
      }
    }
  }
}

void clearArray() {
  for (int i = 1; i <= N; ++i) Vis[i] = F[i] = false;
  for (int i = 1; i <= N; ++i) G.Head[i] = 0;
  for (int i = 1; i <= G.cnte; ++i)
    G.Next[i] = G.To[i] = 0;
  G.cnte = 0;
  Cnt = 0;
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    init();
    solve();
    clearArray();
  }
  return 0;
}