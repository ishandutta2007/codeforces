#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 2e5 + 5;

int n, ans;
int son[maxn], isLeaf[maxn], f[maxn], g[maxn];
vector<int> tree[maxn];

inline void dfs(int u, int p){
  son[u] = isLeaf[u] = f[u] = g[u] = 0;
  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    dfs(v, u);
    if(isLeaf[v])
      ++son[u];
    f[u] += f[v];
    g[u] += g[v];
  }
  if(!son[u])
    isLeaf[u] = true;
  else
    ++f[u];
  g[u] += son[u];
  //printf("u = %d isLeaf = %d son = %d f = %d g = %d\n", u, isLeaf[u], son[u], f[u], g[u]);
  return;
}

inline void calc(int u, int p, int sum, int cnt){
  //printf("u = %d sum = %d cnt = %d\n", u, sum, cnt);
  if(~p && tree[u].size() == 1){
    ans = min(ans, sum - cnt + 1);
    return;
  }
  int sumf = 0, sumg = 0, sumh = 0;

  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    sumf += f[v], sumg += g[v], sumh += (!son[v]);
  }
  
  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    calc(v, u, sum + sumg - g[v] + (sumh - (!son[v])), cnt + sumf - f[v]);
  }
  return;
}

inline void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    tree[i].clear();
  
  for(int i = 1; i < n; ++i){
    int u, v; scanf("%d%d", &u, &v); --u, --v;
    tree[u].PB(v), tree[v].PB(u);
  }

  dfs(0, -1);
  ans = 0x3f3f3f3f;
  calc(0, -1, 0, 0);

  printf("%d\n", ans);

  return;
}

int main(){
  //freopen("E.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}