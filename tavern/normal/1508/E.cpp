#include <bits/stdc++.h>
 
using namespace std;
 
#define PB push_back
#define eprintf( ... ) fprintf(stderr, __VA_ARGS__)
 
typedef long long ll;
 
const int maxn = 3e5 + 5;
 
int n, clko, clki;
int a[maxn], dep[maxn], par[maxn], mn[maxn], dfi[maxn], dfo[maxn], tag[maxn], ind[maxn], ifd[maxn];
vector<int> tree[maxn];
 
inline bool cmp(const int &i, const int &j){ return a[i] < a[j]; }
inline bool cmp2(const int &i, const int &j){ return ifd[i] < ifd[j]; }

inline void dfs(int u, int p, int &x){
  par[u] = p;
  if(~p)
    dep[u] = dep[p] + 1;
  sort(tree[u].begin(), tree[u].end(), cmp);
  tag[u] = clki;
  ifd[u] = clki;
  dfi[clki++] = u;
  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    if(!~x || a[v] > a[u] && a[u] < a[x]){
      //eprintf("x = %d u = %d a = %d\n", x, u, a[u]);
      x = u;
    }
    dfs(v, u, x);
  }
  ind[clko] = ifd[u];
  dfo[clko++] = u;
  return;
}
 
inline void dfs2(int u, int p, int x){
  int lst = -1;
  for(int i = 0; i < tree[u].size(); ++i){
    int v = tree[u][i];
    if(v == p)
      continue;
    dfs2(v, u, x);
    if(!~lst && a[v] >= (~x ? a[x] : n))
      /*eprintf("v = %d\n", v), */mn[v] = true, lst = v;
  }
  return;
}
 
int main(){
  //freopen("1508E.in", "r", stdin);
  
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), --a[i];
  for(int i = 1; i < n; ++i){
    int u, v; scanf("%d%d", &u, &v); --u, --v;
    tree[u].PB(v), tree[v].PB(u);
  }
 
  int x = -1;
  dfs(0, -1, x);
 
  bool ok = true; ll ans = 0;
 
  for(int i = 0; i < (~x ? a[x] : n); ++i)
    ok &= (a[dfo[i]] == i), ans += dep[dfo[i]]/*, eprintf("%d %d\n", dfo[i], dep[dfo[i]])*/;
 
  //eprintf("x = %d a = %d\n", x, a[x]);
  
  dfs2(0, -1, x);
  
  if(~x){
    ans += dep[x];
    for(; ~par[x]; x = par[x]){
      ok &= mn[x];
      //eprintf("x = %d a = %d %d\n", x, a[x], a[par[x]]);
      swap(a[x], a[par[x]]);
    }
  }
 
  //for(int i = 0; i < n; ++i)
  //eprintf("%d ", dfo[i]); eprintf("\n");

  vector<int> vec1, vec2;
  for(int i = (~x ? a[x] : n); i < n; ++i)
    vec1.PB(dfo[i]), vec2.PB(dfo[i]);

  sort(vec1.begin(), vec1.end(), cmp);
  sort(vec2.begin(), vec2.end(), cmp2);

  for(int i = 0; i < vec1.size(); ++i)
    ok &= (vec1[i] == vec2[i]);
  
  if(!ok)
    puts("NO");
  else{
    puts("YES");
    printf("%lld\n", ans);
    for(int i = 0; i < n; ++i)
      printf("%d ", tag[i] + 1); puts("");
  }
  return 0;
}