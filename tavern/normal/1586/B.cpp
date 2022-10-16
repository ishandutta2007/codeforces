#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;
int vis[maxn];

inline void solve(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i)
    vis[i] = false;
  for(int i = 0; i < m; ++i){
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    vis[b] = true;
  }
  for(int i = 1; i <= n; ++i){
    if(!vis[i]){
      for(int j = 1; j <= n; ++j)
	if(i != j)
	  printf("%d %d\n", i, j);
      break;
    }
  }
  return;
}

int main(){
  //freopen("B.in", "r", stdin);
  
  int T;
  for(scanf("%d", &T); T--; solve()); 
  return 0;
}