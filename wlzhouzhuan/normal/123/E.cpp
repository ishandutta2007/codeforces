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
const int N=100005;
vector<int>adj[N];
int n;
double x[N],y[N],sum[N];
int sz[N],dep[N];
void dfs(int u,int fa){
  sz[u]=1,sum[u]=x[u],dep[u]=dep[fa]+1;
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs(v,u);
    sz[u]+=sz[v];
    sum[u]+=sum[v]; 
  }
}
double ans=0;
void dp(int u,int fa,double Sum){
  ans+=(n-sz[u])*(sum[1]-sum[u])*y[u];
  ans+=(Sum+sz[u]*y[fa])*x[u]; 
  for(auto v:adj[u]){
    if(v==fa)continue;
    dp(v,u,Sum+y[fa]*sz[u]);
  }
}
int main(){
  n=read();
  for(register int i=1;i<n;i++){
    int u=read(),v=read();
    adj[u].pb(v),adj[v].pb(u);
  }
  double sumx=0,sumy=0;
  for(register int i=1;i<=n;i++){
    x[i]=read(),y[i]=read();
    sumx+=x[i],sumy+=y[i];
  }
  for(register int i=1;i<=n;i++)x[i]/=sumx,y[i]/=sumy;
  dfs(1,0);
  dp(1,0,0);
  printf("%.12lf\n",ans);
  return 0;
}