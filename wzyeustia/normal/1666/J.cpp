#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

typedef long long ll;
const ll inf = 1e18;
const int maxn = 205;
ll a[maxn][maxn], b[maxn][maxn], sum[maxn];
ll dp[maxn][maxn][maxn];
int to[maxn][maxn][maxn];
int fa[maxn];
int n;

ll cal(int l, int m, int r){
  return b[m][r] - b[m][m - 1] - b[l - 1][r] + b[l - 1][m - 1];
}

ll dfs(int l, int r, int d){
  if(l > r) return dp[l][r][d] = 0;
  if(l == r) return dp[l][r][d] = sum[l] * d;
  if(dp[l][r][d] != -1) return dp[l][r][d];
  dp[l][r][d] = inf;
  rep(i, l, r){
    ll rnt = dfs(l, i - 1, d + 1) + dfs(i + 1, r, d + 1) - cal(l, i, r) * 2 * d + sum[i] * d;
    if(rnt < dp[l][r][d]){
      dp[l][r][d] = rnt;
      to[l][r][d] = i;
    }
  }
  return dp[l][r][d];
}

void print(int l, int r, int d, int f){
  if(l > r) return ;
  if(l == r) return (void) (fa[l] = f);
  int u = to[l][r][d];
  fa[u] = f;
  print(l, u - 1, d + 1, u);
  print(u + 1, r, d + 1, u);
}

int main(){
  memset(dp, -1, sizeof(dp));
  rd(n);
  rep(i, 1, n) rep(j, 1, n) 
    rd(a[i][j]), b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];
  rep(i, 1, n) rep(j, 1, n) sum[i] += a[i][j];
  dfs(1, n, 0);
  print(1, n, 0, 0);
  rep(i, 1, n) printf("%d ", fa[i]);
  return 0;
}