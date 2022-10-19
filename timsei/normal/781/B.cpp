#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int M = N * 8;

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

string S[1005][2];

void print(int x, int y)  {
  cout << S[x][y - 1] << endl;
}

main(void) {
  cin.sync_with_stdio(0);
  cin >> n;
  string A, B;
  for(int i = 1; i <= n; ++ i) {
    cin >> A >> B;
    S[i][0] += A[0];
    S[i][0] += A[1];
    S[i][0] += A[2];
    S[i][1] = S[i][0];
    S[i][1].pop_back();
    S[i][1] += B[0];
  }
  for(int i = 1; i <= n; ++ i) {
    for(int j = i + 1; j <= n; ++ j) {
      for(int a = 0; a < 2; ++ a) {
	for(int b = 0;b < 2; ++ b) {
	  if(S[i][a] == S[j][b]) {
	    link((i << 1) + a, ((j << 1) + b) ^ 1);
	  }
	}
      }
      if(S[i][0] == S[j][0]) {
	link(out(i), out(j));
	link(out(j), out(i));
      }
    }
  }
  for(int i = 2;i <= n * 2 + 1;++ i) if(!dfn[i]) dfs(i);
  for(int i = 1;i <= n;++ i) if(col[in(i)] == col[out(i)]) return 0 * puts("NO");
  cout << "YES" << endl;
  for(int i = 1; i <= n; ++ i) {
    if(col[in(i)] < col[out(i)]) print(i, 1);
    else print(i, 2);
  }
}