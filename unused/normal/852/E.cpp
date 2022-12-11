#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

const int NMAX = 100000;
vector<int> g[NMAX];

ll dp[NMAX][2];

ll fastpow(ll x,ll y){
  if(y==0) return 1;
  if(y&1) return x*fastpow(x,y-1)%MOD;
  ll h = fastpow(x,y/2);
  return h*h%MOD;
}

ll pinv(ll x){return fastpow(x,MOD-2);}

void dfs(int u,int p){
  for(int v:g[u]) if(v!=p) dfs(v,u);
  int vcnt = 0; for(int v:g[u]) if(v!=p) vcnt++;
  if(!vcnt){
    dp[u][0] = dp[u][1] = 1;
    return;
  }
  for(int i=0;i<2;i++){
    ll cur = 1;
    for(int v:g[u]) if(v!=p) cur = cur * dp[v][i] % MOD;
    for(int j=0;j<2;j++) dp[u][(i+j)%2] = (dp[u][(i+j)%2] + cur)%MOD;
  }
}

ll ans[NMAX];

void dfs2(int u,int p,ll p0,ll p1){ //   p0, p1
  ll ch[2];
  for(int i=0;i<2;i++){ //   i
    ll cur = 1;
    for(int v:g[u]) if(v!=p) cur = cur * dp[v][i] % MOD;
    ch[i] = cur;
  }

  ans[u] = (ch[0]*p0%MOD + ch[1]*p1%MOD)%MOD;

  for(int v:g[u]) if(v!=p){
    ll e0 = p0 * pinv(dp[v][0]) % MOD;
    ll e1 = p1 * pinv(dp[v][1]) % MOD;
    e0 = e0*ch[0]%MOD;
    e1 = e1*ch[1]%MOD;
    dfs2(v, u, e0+e1, e0+e1);
  }
}

int main(){
  int N; scanf("%d",&N);
  for(int i=1;i<N;i++){
    int u,v; scanf("%d%d", &u,&v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0,-1);

  ans[0] = dp[0][0];
  ll ch[2]={1,1};
  for(int v:g[0]) for(int i=0;i<2;i++) ch[i] = ch[i] * dp[v][i]%MOD;
  for(int v:g[0]){
    ll e = ch[0]*pinv(dp[v][0])%MOD + ch[1]*pinv(dp[v][1])%MOD; e %= MOD;
    if(g[0].size()==1) dfs2(v,0,1,1);
    else dfs2(v,0,e,e);
  }

  ll sum = 0;
  for(int i=0;i<N;i++) sum = (sum + ans[i])%MOD;
  printf("%lld",sum);
}