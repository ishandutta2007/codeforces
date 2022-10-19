#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
const int M = N * 2;
int n, m, fir[N], ne[M], to[M], cnt, x, y, fa[N], who[N], tot;
//who 
bool vis[N]; 
void add(int x, int y) { //
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}
void link(int x, int y) {//
  add(x, y);
  add(y, x);
}
#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])
//
int dp[N];int K, ans;
void dfs(int x, int f) {
  fa[x] = f;
  who[++ tot] = x;
  Foreachson(i, x) {
 int V = to[i];
 if(V == f) continue;
 dfs(V, x);
  }
}
int res[N];
int solve(int k) {
//O(n) 
  if(vis[k]) return res[k];
  //
  if(k == 1) return n;
  ans = 0;
  for(int i = 1; i <= n; ++ i) dp[i] = 0;
  //
  for(int i = 1; i < n; ++ i) {
 int V = who[i];
 ++ dp[V];
 if(dp[fa[V]] == -1) continue;
 if(dp[fa[V]] + dp[V] + 1 >= k) {
   dp[fa[V]] = -1;
   ++ ans;
 }
 else dp[fa[V]] = max(dp[fa[V]], dp[V]);
  }
  return res[k] = ans;
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; ++ i) {scanf("%d%d", &x, &y), link(x, y);}
  dfs(1, 0);
  reverse(who + 1, who + n + 1);
  if(n <= 1500) {
 for(int i = 1; i <= min(1500, n); ++ i) printf("%d\n", solve(i));
 return 0;
  }
  for(int i = 1; i <= 1500; ++ i) printf("%d\n", res[i] = solve(i));
  int last;
  for(int i = 1501; i <= n; i = last + 1) {
 int l = i, r = n; last = i - 1;
 int now = solve(i);
 if(!now) {
   for(int j = i; j <= n; ++ j) printf("%d\n", now);
   return 0;
 }
 while(l <= r) {
   int mid = (l + r) >> 1;
   if(solve(mid) != now) r = mid - 1;
   else last = mid, l = mid + 1;
 }
 for(int j = i; j <= last; ++ j) printf("%d\n", now);
  }
}