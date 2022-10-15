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
const int N=200005;
struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w};
  head[u]=tot;
}
int a[N],n; 
int ban[N],mx[N],sz[N],sum,rt;
void getrt(int u,int fa){
  sz[u]=1,mx[u]=-1;
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(v==fa||ban[v])continue;
    getrt(v,u);
    mx[u]=max(mx[u],sz[v]),sz[u]+=sz[v];
  }
  mx[u]=max(mx[u],sum-sz[u]);
  if(mx[u]<mx[rt])rt=u;
}
double getans(int u,int fa,ll dis){
  double ret=1.0*a[u]*dis*sqrt(dis);
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(v==fa)continue;
    ret+=getans(v,u,dis+edge[i].val); 
  }
  return ret;
}
int dot=-1;
double ans=1e100;
double getdao(int u,int fa,ll dis){
  double ret=1.0*a[u]*sqrt(dis);
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(v==fa)continue;
    ret+=getdao(v,u,dis+edge[i].val);
  }
  return ret;
}
void dfz(int u){
  //printf("dfz %d\n",u);
  ban[u]=1;
  double _=getans(u,0,0ll);
  if(_<ans)ans=_,dot=u;
  double maxx=-1e100;
  int cur=-1; 
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(ban[v])continue;
    double delta=getdao(v,u,edge[i].val);
    if(delta>maxx)maxx=delta,cur=v;
  }
  if(~cur){
    if(sz[cur]>sz[u])sum-=sz[u];
    else sum=sz[cur];
    rt=0;
    getrt(cur,0);
    dfz(rt);
  }
}
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  for(int i=1;i<n;i++){
    int u=read(),v=read(),w=read();
    add(u,v,w),add(v,u,w);
  }  
  mx[rt=0]=1e9,sum=n,getrt(1,0);
  dfz(rt);
  printf("%d %.12lf\n",dot,ans);
  return 0; 
}