#include <cstdio>
#include <cstring>

const int MaxN = 400000, MaxM = 600000;

struct Graph {
  int cnte;
  int Head[MaxN + 5], Next[MaxM * 2 + 5], To[MaxM * 2 + 5];
  Graph() { cnte = 1; }

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int M;
int Col[MaxM + 5], Ind[MaxN + 5];
int Iter[MaxN + 5];
Graph Gr;

void init() {
  scanf("%d", &M);
  for (int i = 1; i <= M; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    Gr.addEdge(u, v + 200000);
    Gr.addEdge(v + 200000, u);
    Ind[u]++, Ind[v + 200000]++;
  }
  for (int i = 1; i <= 400000; ++i)
    if (Ind[i] & 1) {
      Gr.addEdge(0, i);
      Gr.addEdge(i, 0);
    }
}

void dfs(int u, int c) {
  for (int &i = Iter[u]; i; i = Gr.Next[i]) {
    if (Col[i >> 1] != -1) continue;
    int v = Gr.To[i];
    Col[i >> 1] = c;
    dfs(v, c ^ 1);
  }
}

void solve() {
  memcpy(Iter, Gr.Head, sizeof Gr.Head);
  memset(Col, -1, sizeof Col);
  for (int i = 0; i <= 400000; ++i)
    if (Gr.Head[i] == Iter[i]) dfs(i, 0);
  for (int i = 1; i <= M; ++i) putchar("br"[Col[i]]);
  putchar('\n');
}

int main() {
  init();
  solve();
  return 0;
}