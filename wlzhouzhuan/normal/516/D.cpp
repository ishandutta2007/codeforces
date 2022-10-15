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
#define int long long
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
struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w};
  head[u]=tot;
}
int n,q;
ll s[N],d[N];
void dfs1(int u,int fa){
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to,w=edge[i].val;
    if(v==fa)continue;
    s[v]=max(s[v],s[u]+w);
    dfs1(v,u);
  } 
}
void dfs2(int u,int fa){
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to,w=edge[i].val;
    if(v==fa)continue;
    d[v]=max(d[v],d[u]+w);
    dfs2(v,u);
  }
}
void dfs(int u,int fa){
  d[u]=max(d[u],s[u]);
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to,w=edge[i].val;
    if(v==fa)continue;
    s[v]=max(s[v],s[u]+w);
    dfs(v,u);
  }
}

int f[N],sz[N];
int id[N],mp[N];
int find(int x){
  return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
  x=find(x),y=find(y);
  if(x==y)return;
  if(sz[x]>sz[y])swap(x,y);
  f[x]=y,sz[y]+=sz[x]; 
}
signed main(){
  n=read();
  for(int i=1;i<n;i++){
    int u=read(),v=read(),w=read();
    add(u,v,w),add(v,u,w);
  }
  memset(s,0,sizeof(s));
  dfs1(1,0);
  //cerr<<"dfs1 ok!\n";
  int rt=0;
  for(int i=1;i<=n;i++)if(s[rt]<s[i])rt=i;
  memset(d,0,sizeof(d));
  dfs2(rt,0);
  //cerr<<"dfs2 ok!\n";
  rt=0;
  for(int i=1;i<=n;i++)if(d[rt]<d[i])rt=i;
  memset(s,0,sizeof(s));
  dfs(rt,0);
  //for(int i=1;i<=n;i++)printf("d[%d]=%d\n",i,d[i]);
  for(int i=1;i<=n;i++)id[i]=i;
  sort(id+1,id+n+1,[&](int x,int y){
    return d[x]>d[y];
  });
  for(int i=1;i<=n;i++)mp[id[i]]=i;
  q=read();
  while(q--){
    int l=read(),ans=0;
    for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
    for(int i=1,j=1;j<=n;j++){
      while(d[id[i]]-d[id[j]]>l){
        --sz[find(id[i])];
        i++;
      }
      for(int k=head[id[j]];k;k=edge[k].nxt){
        int v=edge[k].to;
        if(i<=mp[v]&&mp[v]<=j){
          merge(v,id[j]);
        }
      }
      ans=max(ans,sz[find(id[j])]);
    }
    printf("%lld\n",ans);
  }
  return 0;
}