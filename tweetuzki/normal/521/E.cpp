#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 200000 + 5, MaxM = 200000 + 5;

struct Graph {
  int cnte;
  int Head[MaxN], To[MaxN * 2], Next[MaxN * 2];

  inline void addEdge(int from, int to) {
    cnte++; To[cnte] = to;
    Next[cnte] = Head[from]; Head[from] = cnte;
  }
};

int N, M;
int U[MaxM], V[MaxM];
bool InTree[MaxM];
int Par[MaxN];
int Fa[MaxN], Dep[MaxN];
int Col[MaxN];
Graph G;

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i)
    scanf("%d %d", &U[i], &V[i]);
}

int find(int x) { return x == Par[x] ? x : Par[x] = find(Par[x]); }

void dfs(int u) {
  for (int i = G.Head[u]; i; i = G.Next[i]) {
    int v = G.To[i];
    if (v == Fa[u]) continue;
    Fa[v] = u;
    Dep[v] = Dep[u] + 1;
    dfs(v);
  }
}

inline int getCol(int u, int v) {
  while (Dep[u] > Dep[v]) {
    if (Col[u] != 0) return Col[u];
    u = Fa[u];
  }
  while (Dep[v] > Dep[u]) {
    if (Col[v] != 0) return Col[v];
    v = Fa[v];
  }
  while (u != v) {
    if (Col[u] != 0) return Col[u];
    if (Col[v] != 0) return Col[v];
    u = Fa[u], v = Fa[v];
  }
  return 0;
}

inline void paintCol(int u, int v, int c) {
  while (Dep[u] > Dep[v]) {
    Col[u] = c;
    u = Fa[u];
  }
  while (Dep[v] > Dep[u]) {
    Col[v] = c;
    v = Fa[v];
  }
  while (u != v) {
    Col[u] = c, Col[v] = c;
    u = Fa[u], v = Fa[v];
  }
}

inline std::vector<int> getPath(int u, int v) {
  static int st[MaxN];
  int tp = 0;
  std::vector<int> vec;
  vec.clear();
  while (Dep[u] > Dep[v]) {
    vec.push_back(u);
    u = Fa[u];
  }
  while (Dep[v] > Dep[u]) {
    st[++tp] = v;
    v = Fa[v];
  }
  while (u != v) {
    vec.push_back(u);
    st[++tp] = v;
    u = Fa[u], v = Fa[v];
  }
  vec.push_back(v);
  while (tp > 0) vec.push_back(st[tp--]);
  return vec;
}

inline std::vector<int> getIntersection(std::vector<int> l1, std::vector<int> l2) {
  std::vector<int> l;
  static bool o[MaxN];
  memset(o, false, sizeof o);
  for (int v : l1) o[v] = true;
  for (int v : l2) if (o[v]) l.push_back(v);
  return l;
}

inline void print(std::vector<int> vec) {
  int s = (int) vec.size();
  printf("%d ", s);
  for (int i = 0; i < s; ++i)
    printf("%d%c", vec[i], " \n"[i == s - 1]);
}

inline bool isAncestor(int u, int f) {
  while (Dep[u] > Dep[f]) u = Fa[u];
  if (u == f) return true;
  else return false;
}

void solve() {
  for (int i = 1; i <= N; ++i) Par[i] = i;
  for (int i = 1; i <= M; ++i) {
    int p = find(U[i]), q = find(V[i]);
    if (p != q) {
      Par[p] = q;
      InTree[i] = true;
      G.addEdge(U[i], V[i]);
      G.addEdge(V[i], U[i]);
    }
  }
  for (int i = 1; i <= N; ++i)
    if (Fa[i] == 0) dfs(i);
  for (int i = 1; i <= M; ++i) {
    if (InTree[i] == true) continue;
    if (Dep[U[i]] < Dep[V[i]]) std::swap(U[i], V[i]);
    int u = U[i], v = V[i];
    int c = getCol(u, v);
    if (c != 0) {
      puts("YES");
      std::vector<int> l1 = getPath(U[i], V[i]), l2 = getPath(U[c], V[c]);
      std::vector<int> inter = getIntersection(l1, l2);
      u = *inter.begin(), v = *(inter.end() - 1);
      if (Dep[u] < Dep[v]) std::swap(u, v);
      if (u == U[i] && v == V[i]) {
        print(getPath(u, v));
        printf("%d %d %d\n", 2, u, v);
        std::vector<int> p3, p4;
        p3 = getPath(u, U[c]);
        p4 = getPath(V[c], v);
        for (int v : p4) p3.push_back(v);
        print(p3);
      } else if (u == U[c] && v == V[c]) {
        print(getPath(u, v));
        printf("%d %d %d\n", 2, u, v);
        std::vector<int> p3, p4;
        p3 = getPath(u, U[i]);
        p4 = getPath(V[i], v);
        for (int v : p4) p3.push_back(v);
        print(p3);
      } else {
        print(getPath(u, v));
        std::vector<int> p1, p2;
        if (isAncestor(U[i], u)) {
          std::vector<int> p3;
          p1 = getPath(u, U[i]);
          p3 = getPath(V[i], v);
          for (int x : p3) p1.push_back(x);
        } else {
          std::vector<int> p3;
          p1 = getPath(u, V[i]);
          p3 = getPath(U[i], v);
          for (int x : p3) p1.push_back(x);
        }
        if (isAncestor(U[c], u)) {
          std::vector<int> p4;
          p2 = getPath(u, U[c]);
          p4 = getPath(V[c], v);
          for (int x : p4) p2.push_back(x);
        } else {
          std::vector<int> p4;
          p2 = getPath(u, V[c]);
          p4 = getPath(U[c], v);
          for (int x : p4) p2.push_back(x);
        }
        print(p1);
        print(p2);
      }
      return;
    } else paintCol(u, v, i);
  }
  puts("NO");
}

int main() {
  init();
  solve();
  return 0;
}