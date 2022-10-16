#include <bits/stdc++.h>

using namespace std;

const int siz = 524288;
const int maxn = siz * 3;

int n;
int a[maxn], b[maxn], f[maxn], from[maxn];
vector<pair<int, int> > g[maxn];

inline void build(){
  for(int i = siz - 1; i; --i){
    g[i + n].push_back(make_pair((i << 1) + n, 0));
    g[i + n].push_back(make_pair((i << 1 | 1) + n, 0));
  }
  for(int i = 0; i <= n; ++i)
    g[i + siz + n].push_back(make_pair(i, 0));
  return;
}

inline void query(int u, int l, int r){
  for(l += siz, r += siz + 1; l < r; l >>= 1, r >>= 1){
    if(l & 1)
      g[u].push_back(make_pair((l++) + n, 1));
    if(r & 1)
      g[u].push_back(make_pair((--r) + n, 1));
  }
  return;
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
    scanf("%d", a + i);
  for(int i = 1; i <= n; ++i)
    scanf("%d", b + i);

  build();
  for(int i = 1; i <= n; ++i){
    query(i, i + b[i] - a[i + b[i]], i + b[i]);
    //printf("%d %d %d\n", i, i + b[i] - a[i + b[i]], i + b[i]);
  }
  memset(f, 0x3f, sizeof(f));

  deque<int> que;
  for(int i = 0; i <= a[n]; ++i)
    f[n - i] = 1, que.push_back(n - i), from[n - i] = n;
  for(; !que.empty(); ){
    int u = que.front(); que.pop_front();
    //printf("u = %d f = %d\n", u, f[u]);
    for(int i = 0; i < g[u].size(); ++i){
      int v = g[u][i].first, w = g[u][i].second;
      if(f[v] > f[u] + w){
	//printf("u = %d v = %d\n", u, v);
	f[v] = f[u] + w;
	if(w)
	  que.push_back(v);
	else
	  que.push_front(v);
	from[v] = u;
      }
    }
  }

  if(f[0] == 0x3f3f3f3f)
    puts("-1");
  else{
    vector<int> ans;
    for(int u = 0; u != n; u = from[u]){
      //printf("u = %d\n", u);
      if(u <= n)
	ans.push_back(u);
    }
    printf("%d\n", f[0]);
    for(int i = ans.size() - 1; i >= 0; --i)
      printf("%d ", ans[i]); puts("");
  }
  return 0;
}