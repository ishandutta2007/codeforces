#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=1000005;
vector<int>adj[N];
int len[N],son[N];
int n;
void dfs(int u,int fa){
  len[u]=0;
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs(v,u);
    if(len[v]>len[son[u]])son[u]=v;
  }
  len[u]=len[son[u]]+1;
}
int *f[N],tmp[N],*id=tmp;
int ans[N];
void dp(int u,int fa){
  f[u][0]=1;
  if(son[u])f[son[u]]=f[u]+1,dp(son[u],u),ans[u]=ans[son[u]]+1;
  for(auto v:adj[u]){
    if(v==fa||v==son[u])continue;
    f[v]=id,id+=len[v];
    dp(v,u);
    for(register int j=1;j<=len[v];j++){
      f[u][j]+=f[v][j-1];
      if(f[u][j]>f[u][ans[u]]||(f[u][j]==f[u][ans[u]]&&j<ans[u]))
        ans[u]=j;
    }
  }
  if(f[u][ans[u]]==1)ans[u]=0;
}
int main(){
  n=read();
  for(register int i=1;i<n;i++){
    int u=read(),v=read();
    adj[u].pb(v),adj[v].pb(u);
  }
  dfs(1,0);
  f[1]=id,id+=len[1];
  dp(1,0);
  for(register int i=1;i<=n;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}