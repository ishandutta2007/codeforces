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
const int N=600005;
const int inf=1e9;
struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],etot;
void add(int u,int v,int val){
  edge[++etot]={v,head[u],val},head[u]=etot;
}

int val[N],x[N],y[N],opt[N],dot[N];
int ban[N],n,m,q,tot;

int f[N];
int find(int x){
  return f[x]==x?x:f[x]=find(f[x]);
}
int jump[N][20],g[N][20];
int dfn[N],id[N],sz[N],scc;
void dfs(int u){
  dfn[u]=++scc,id[scc]=u,sz[u]=1; 
  for(int j=1;j<20;j++){
    jump[u][j]=jump[jump[u][j-1]][j-1];
    g[u][j]=min(g[u][j-1],g[jump[u][j-1]][j-1]);
  }
  for(register int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    jump[v][0]=u,g[v][0]=edge[i].val;
    dfs(v),sz[u]+=sz[v]; 
  }
}

struct SegmentTree{
  #define ls (u<<1)
  #define rs (u<<1|1)
  int mx[N<<2],mxpos[N<<2];
  void pushup(int u){
    if(mx[ls]<mx[rs])mx[u]=mx[rs],mxpos[u]=mxpos[rs];
    else mx[u]=mx[ls],mxpos[u]=mxpos[ls];
  }
  void build(int u,int l,int r){
    if(l==r){
      mx[u]=val[id[l]];
      mxpos[u]=id[l];
      return;
    }
    int mid=l+r>>1;
    build(ls,l,mid),build(rs,mid+1,r);
    pushup(u);
  }
  void modify(int u,int l,int r,int pos){
    if(l==r){
      mx[u]=val[id[l]];
      mxpos[u]=id[l];
      return;
    }
    int mid=l+r>>1;
    if(pos<=mid)modify(ls,l,mid,pos);
    else modify(rs,mid+1,r,pos);
    pushup(u);
  }
  pii query(int u,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return make_pair(mx[u],mxpos[u]);
    int mid=l+r>>1;
    if(qr<=mid)return query(ls,l,mid,ql,qr);
    else if(ql>mid)return query(rs,mid+1,r,ql,qr);
    else{
      pii lc=query(ls,l,mid,ql,qr),rc=query(rs,mid+1,r,ql,qr);
      if(lc.fir<rc.fir)return rc;
      else return lc;
    }
  }
}smt;
int main(){
  mset(g,0x3f);
  n=read(),m=read(),q=read();
  rep(i,1,n)val[i]=read();
  rep(i,n+1,N-1)val[i]=-inf;
  rep(i,1,m)x[i]=read(),y[i]=read();
  rep(i,1,q){
    opt[i]=read(),dot[i]=read();
    if(opt[i]==2)ban[dot[i]]=1;
  }
  rep(i,1,n)f[i]=i;
  tot=n;
  rep(i,1,m)if(!ban[i]){
    int u=find(x[i]),v=find(y[i]);
    if(u==v)continue;
    tot++,f[tot]=f[u]=f[v]=tot;
    add(tot,u,inf),add(tot,v,inf);
  }
  per(i,q,1)if(opt[i]==2){
    int u=find(x[dot[i]]),v=find(y[dot[i]]);
    if(u==v)continue;
    tot++,f[tot]=f[u]=f[v]=tot;
    add(tot,u,i),add(tot,v,i);
  }
  tot++;
  rep(i,1,tot-1)if(find(i)==i)add(tot,i,-inf);
  dfs(tot);
  smt.build(1,1,tot);
  rep(i,1,q)if(opt[i]==1){
    int u=dot[i];
    for(int j=19;j>=0;j--){
      if(jump[u][j]&&g[u][j]>=i){
        u=jump[u][j];
      }
    }
    pii ans=smt.query(1,1,tot,dfn[u],dfn[u]+sz[u]-1);
    //assert(ans.sec>=0);
    printf("%d\n",ans.fir);
    val[ans.sec]=0;
    smt.modify(1,1,tot,dfn[ans.sec]);
  }
  return 0;
}
// I AK IOI !