#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int &x){
  char c=nc(),b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

const int N=100005;

struct edge{
  int u,v,w,next;
}G[N<<1];
int head[N],inum;
inline void add(int u,int v,int w,int p){
  G[p].u=u; G[p].v=v; G[p].w=w; G[p].next=head[u]; head[u]=p;
}
#define V G[p].v

int bla[N];
int dis[N],dis2[N];
int pt,maxd;

inline void find(int u,int fa){
  if (bla[u] && dis[u]>maxd) maxd=dis[u],pt=u;
  for (int p=head[u];p;p=G[p].next)
    if (V!=fa)
      dis[V]=dis[u]+G[p].w,find(V,u);
}

int size[N];
int cur,rt[N];
int f[N],g[N];

inline void dfs(int u,int fa){
  rt[u]=cur;
  size[u]=bla[u];
  for (int p=head[u];p;p=G[p].next)
    if (V!=fa)
      dis[V]=dis[u]+G[p].w,dfs(V,u),size[u]+=size[V];
  if (bla[u]) f[u]=dis[u],g[u]=1;
  for (int p=head[u];p;p=G[p].next)
    if (V!=fa){
      if (f[V]>f[u])
    f[u]=f[V],g[u]=g[V];
      else if (f[V]==f[u])
    g[u]+=g[V];
    }
}

int n,m,RT;

int main(){
  int x,y,iu,iv,iw;
  read(n); read(m); y=m;
  while (y--) read(x),bla[x]=1;
  for (int i=1;i<n;i++)
    read(iu),read(iv),read(iw),add(iu,iv,iw,++inum),add(iv,iu,iw,++inum);
  maxd=0; find(1,0);
  for (int i=1;i<=n;i++) dis[i]=0;
  x=pt; maxd=0; find(pt,0);
  for (int i=1;i<=n;i++) dis2[i]=dis[i],dis[i]=0;;
  maxd=0; find(pt,0);
  RT=0;
  for (int i=1;i<=n;i++)
    if(dis[i]+dis2[i]==dis[x])
      if(!RT || abs(dis[i]-dis2[i])<abs(dis[RT]-dis2[RT]))
    RT=i;
  dis[RT]=0,size[RT]=bla[RT];
  for (int p=head[RT];p;p=G[p].next)
    dis[V]=G[p].w,cur=V,dfs(V,RT),size[RT]+=size[V];
  int mx1=0,mx2=0,id1=0,id2=0;
  for(int p=head[RT];p && ~id1 && ~id2;p=G[p].next){
    if (!size[V]) continue;
    if (f[V]>mx1)
      mx2=mx1,id2=id1,mx1=f[V],id1=V;
    else if(f[V]==mx1)
      mx1==mx2?id1=id2=-1:(mx2=f[V],id2=V);
    else if(f[V]>mx2)
      mx2=f[V],id2=V;
    else if (f[V]==mx2)
      id2=-1;
  }
  int ans=0,tot=0;
  if (!bla[RT]) ans=m,tot=1;
  for (int i=1;i<=n;i++){
    if (i==RT || bla[i]) continue;
    int ret=size[i];
    if (~id1 && ~id2 && size[i] && f[i]==f[rt[i]] && g[i]==g[rt[i]]){
      if (rt[i]==id1)
        f[id1]>f[id2]?ret+=m-size[id1]:ret+=size[id2];
      else if (rt[i]==id2)
    ret+=size[id1];
    }
    if (ret>ans)
      ans=ret,tot=1;
    else if(ret==ans)
      tot++;
  }
  printf("%d %d\n",ans,tot);
  return 0;
}