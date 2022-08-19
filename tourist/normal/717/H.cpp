#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int x[N], y[N];
vector <int> g[N];
int team[N], color[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", x + i, y + i);
    x[i]--; y[i]--;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    g[i].resize(foo);
    for (int j = 0; j < foo; j++) {
      scanf("%d", &g[i][j]);
      cnt = max(cnt, g[i][j]);
      g[i][j]--;
    }
  }
  srand(8753);
  while (true) {
    for (int i = 0; i < n; i++) {
      int x = rand() % g[i].size();
      team[i] = g[i][x];
    }
    for (int i = 0; i < cnt; i++) {
      color[i] = rand() % 2;
    }
    int hatred = 0;
    for (int i = 0; i < m; i++) {
      hatred += (color[team[x[i]]] != color[team[y[i]]]);
    }
    if (2 * hatred >= m) {
      for (int i = 0; i < n; i++) {
        printf("%d ", team[i] + 1);
      }
      printf("\n");
      for (int i = 0; i < cnt; i++) {
        printf("%d ", color[i] + 1);
      }
      printf("\n");
      break;
    }
  }
  return 0;
}