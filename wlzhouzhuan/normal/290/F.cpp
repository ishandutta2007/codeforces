#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int vis[N], Map[N][N], deg[N];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (Map[u][v] || u == v) continue;
    Map[u][v] = Map[v][u] = 1;
    deg[u]++, deg[v]++;
  }
  for (int st = 1; st <= n; st++) {
    memset(vis, 0, sizeof(vis));
    int turn, cur = st;
    vis[st] = 1;
    for (turn = 1; turn < n; turn++) {
      int p = 0;
      for (int i = 1; i <= n; i++) {
        if (Map[cur][i] && !vis[i] && (p == 0 || deg[p] > deg[i])) {
          p = i;
        }
      }
      if (p == 0) break;
      cur = p, vis[cur] = 1;
    }
    if (turn == n) {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
  return 0;
}