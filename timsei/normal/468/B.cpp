#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = N * 2;

map <int,int> Map;

int n , m , x , y , val[N] , A , B , scc[N] , dfn[N] , col[N] , dfs_clock , low[N] , fir[N] , ne[M] , to[M] , cnt , stk[N] , tot , sy;

void add(int x , int y) {
  ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
  add(x , y); add(y ^ 1 , x ^ 1);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

void dfs(int x) {
  dfn[x] = low[x] = ++ dfs_clock; stk[++ tot] = x;
  Foreachson(i , x) {
    int V = to[i];
    if(!dfn[V]) dfs(V);
    if(!col[V]) low[x] = min(low[x] , low[V]);
  }
  if(low[x] == dfn[x]) {
    ++ sy;
    for(;;) {
      col[stk[tot --]] = sy;
      if(stk[tot + 1] == x) break;
    }
  }
}

#define in(i) (i << 1)
#define out(i) (i << 1 | 1)

main(void) {
  scanf("%d%d%d" , &n , &A , & B);
  for(int i = 1;i <= n;++ i) scanf("%d" , &val[i]) , Map[val[i]] = i;
  for(int i = 1;i <= n;++ i) {
    int now = Map[A - val[i]];
    if(!now) link(in(i) , out(i));
    if(now >= i) {
      link(in(i) , in(now));
      link(in(now) , in(i));
    }
    now = Map[B - val[i]];
    if(!now) link(out(i) , in(i));
    if(now >= i) {
      link(out(i) , out(now));
      link(out(now) , out(i));
    }
  }
  for(int i = 2;i <= n * 2 + 1;++ i) if(!dfn[i]) dfs(i);
  for(int i = 1;i <= n;++ i) if(col[in(i)] == col[out(i)]) return 0 * puts("NO");
  puts("YES");
  for(int i = 1;i <= n;++ i) {
    if(col[in(i)] < col[out(i)]) printf("0 ");
    else printf("1 ");
  }
}