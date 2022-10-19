#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int fa[N], n, m, k, x[N], u, v, S[N];

int getf(int x) {
  return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

struct Edge  {
  int x, y, w;
  friend bool operator < (Edge a, Edge b) {
    return a.w < b.w;
  }
  void input() {
    scanf("%d%d%d", &x, &y, &w);
  }
}E[N];

map < pair <int, int>, int> C;

int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++ i) fa[i] = i;
  for(int i = 1; i <= k; ++ i) scanf("%d", &x[i]), S[x[i]] = 1;
  for(int i = 1; i <= m; ++ i) {
    E[i].input();
  }
  sort(E + 1, E + m + 1);
  int ans = 0;
  for(int i = 1; i <= m; ++ i) {
    int x = getf(E[i].x), y = getf(E[i].y);
    if(x == y) continue; 
    if(S[x] && S[y]) {
      ans = max(ans, E[i].w);
    }
    fa[getf(x)] = getf(y);
    S[getf(y)] += S[x];
  }
  for(int i = 1; i <= k; ++ i) printf("%d ", ans);
}