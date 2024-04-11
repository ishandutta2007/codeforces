#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

vector <int> G[N] ,no[N];

int n , m , x , y , tot , k , ne[N] , pre[N] , col[N];
bool vis[N] , ban[N];

void del(int x) {
  ne[pre[x]] = ne[x];
  pre[ne[x]] = pre[x];
}

void BFS(int x) {
  ++ tot;
  queue <int> q; while(!q.empty()) q.pop();
  q.push(x); col[x] = x; del(x); no[x].push_back(x);
  while(!q.empty()) {
    int ind = q.front(); q.pop();
    for(auto V : G[ind]) ban[V] = 1;
    for(int i = ne[0];i;i = ne[i]) {
      if(ban[i]) continue;
      del(i); col[i] = x; q.push(i); no[x].push_back(i);
    }
    for(auto V : G[ind]) ban[V] = 0;
  }
}

bool Kill[N];

main(void) {
  scanf("%d%d%d" , &n , &m , &k);
  for(int i = 1;i <= m;++ i) scanf("%d%d" , &x , &y) , G[x].push_back(y) , G[y].push_back(x);
  ne[0] = 2;
  pre[2] = 0; ne[2] = 3;
  for(int i = 3;i <= n;++ i) pre[i] = i - 1 , ne[i] = i + 1; ne[n] = 0;
  for(int i = 2;i <= n;++ i) if(!col[i]) {
      BFS(i);
    }
  if(k < tot) return puts("impossible") * 0;
  int p = n - 1;
  for(auto V : G[1]) ban[V] = 1 , -- p;
  if(p < k) return puts("impossible") , 0;
  for(int i = 2;i <= n;++ i) if(!ban[i]) {
      if(!Kill[col[i]]) {
	-- tot; Kill[col[i]] = 1;
      }
    }
  if(!tot) puts("possible"); else puts("impossible");
}