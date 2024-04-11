#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = N * 4;

int fir[N], ne[M], to[M], vis[N], n, m, x, y, cnt, k;

vector <int> ans;

void add(int x, int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

void link(int x, int y) {
  add(x, y);
  add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int up(int x, int y) {
  return (x - 1) / y + 1;
}

void dfs(int x) {
  ans.push_back(x);
  vis[x] = 1;
  Foreachson(i, x) {
    int V = to[i];
    if(vis[V]) continue;
    dfs(V);
    ans.push_back(x);
  }
}

main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d", &x, &y);
    link(x, y);
  }
  dfs(1);
  int MAX = up(2 * n, k);
  int now = 0;
  for(int i = 0; i < (int) ans.size(); i += MAX) {
    printf("%d ", min(MAX, (int)ans.size() - i));
    for(int j = i; j < min(i + MAX, (int)ans.size()); ++ j) printf("%d ", ans[j]);
    puts("");
    ++ now;
  }
  if(now < k) {
    for(int i = now + 1; i <= k; ++ i) puts("1 1");
  }
}