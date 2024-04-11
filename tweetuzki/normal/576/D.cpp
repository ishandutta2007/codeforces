#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>

const int MaxN = 150, MaxM = 150;
const int INF = 0x7F7F7F7F;

struct edge_t {
  int u, v, d;
  edge_t(int _u = 0, int _v = 0, int _d = 0) { u = _u, v = _v, d = _d; }
  inline friend bool operator < (const edge_t &a, const edge_t &b) { return a.d < b.d; }
};

int N, M;
edge_t E[MaxM + 5];

struct Matrix {
  std::bitset<MaxN + 5> mat[MaxN + 5];

  Matrix() {
    for (int i = 0; i <= MaxN; ++i) mat[i].reset();
  }

  inline friend std::bitset<MaxN + 5> operator * (const std::bitset<MaxN + 5> &a, const Matrix &b) {
    std::bitset<MaxN + 5> c;
    c.reset();
    for (int i = 1; i <= N; ++i)
      if (a[i] == true) c |= b.mat[i];
    return c;
  }

  inline friend Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 1; i <= N; ++i)
      for (int k = 1; k <= N; ++k)
        if (a.mat[i][k] == true) c.mat[i] |= b.mat[k];
    return c;
  }

  inline friend Matrix operator ^ (Matrix low, int high) {
    Matrix res;
    for (int i = 1; i <= N; ++i) res.mat[i].set(i);
    while (high) {
      if (high & 1) res = res * low;
      high >>= 1;
      low = low * low;
    }
    return res;
  }

  inline friend void print(const Matrix &a) {
    puts("matrix:");
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) putchar("01"[a.mat[i][j]]);
      putchar('\n');
    }
    puts("-------");
  }
};
std::bitset<MaxN + 5> F;
Matrix G;

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= M; ++i) scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].d);
  std::sort(E + 1, E + 1 + M);
}

void solve() {
  F.set(1);
  // print(F);
  int ans = INF;
  for (int l = 1, r = 0; l <= M; l = r + 1) {
    while (r < M && E[r + 1].d == E[l].d) r++;
    int d = E[l].d;
    if (d > ans) break;
    F = F * (G ^ (d - E[l - 1].d));
    // print(F);
    for (int i = l; i <= r; ++i) {
      int u = E[i].u, v = E[i].v;
      G.mat[u].set(v);
    }
    // print(G);
    std::bitset<MaxN + 5> f = F;
    for (int i = d + 1; i <= d + M; ++i) {
      // printf("i = %d\n", i);
      if (r != M && i > E[r + 1].d) break;
      f = f * G;
      // print(f);
      if (f[N] == true) {
        ans = std::min(ans, i);
        break;
      }
    }
  }
  if (ans == INF) puts("Impossible");
  else printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}