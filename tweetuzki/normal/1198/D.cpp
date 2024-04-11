#include <algorithm>
#include <cstdio>
#include <cstring>

const int MaxN = 50 + 5;

int N;
int A[MaxN][MaxN], Pre[MaxN][MaxN];
int F[MaxN][MaxN][MaxN][MaxN];
bool Vis[MaxN][MaxN][MaxN][MaxN];

inline char geCh() {
  char c;
  do c = getchar(); while (c != '#' && c != '.');
  return c;
}

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j) {
      if (geCh() == '#') A[i][j] = 1;
      else A[i][j] = 0;
    }
}

inline int query(int x1, int y1, int x2, int y2) {
  return Pre[x2][y2] - Pre[x2][y1 - 1] - Pre[x1 - 1][y2] + Pre[x1 - 1][y1 - 1];
}

int dfs(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  if (Vis[x1][y1][x2][y2] == true) return F[x1][y1][x2][y2];
  Vis[x1][y1][x2][y2] = true;
  int f = std::max(x2 - x1 + 1, y2 - y1 + 1);
  for (int x = x1; x <= x2; ++x) {
    if (query(x, y1, x, y2) == 0) {
      f = std::min(f, dfs(x1, y1, x - 1, y2) + dfs(x + 1, y1, x2, y2));
    }
  }
  for (int y = y1; y <= y2; ++y) {
    if (query(x1, y, x2, y) == 0) {
      f = std::min(f, dfs(x1, y1, x2, y - 1) + dfs(x1, y + 1, x2, y2));
    }
  }
  return F[x1][y1][x2][y2] = f;
}

void solve() {
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      Pre[i][j] = Pre[i - 1][j] + Pre[i][j - 1] + A[i][j] - Pre[i - 1][j - 1];
  printf("%d\n", dfs(1, 1, N, N));
}

int main() {
  init();
  solve();
  return 0;
}