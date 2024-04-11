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

const int N=300005;
char str[N];
int a[N],ed[N];
int ch[N][26],tot;
void ins(char *s,int id){
  int rt=0,len=strlen(s+1);
  for(int i=1;i<=len;i++){
    int &tmp=ch[rt][s[i]-'a'];
    if(!tmp)tmp=++tot;
    rt=tmp;
  }
  ed[id]=rt; 
  //printf("ed[%d]=%d\n",id,ed[id]);
}

vector<int>adj[N];
int fail[N]; 
int n,m;
int fa[N],son[N],sz[N],dep[N];
void dfs1(int u){
  sz[u]=1;
  for(auto v:adj[u]){
    dep[v]=dep[u]+1;
    fa[v]=u;
    dfs1(v),sz[u]+=sz[v];
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}
int bl[N],dfn[N],id[N],scc; 
void dfs2(int u,int topf){
  bl[u]=topf,dfn[u]=++scc,id[scc]=u;
  if(son[u])dfs2(son[u],topf);
  for(auto v:adj[u]){
    if(v!=son[u])dfs2(v,v);
  }
}

bool tag[N];

void build(){
  queue<int>q;
  for(int i=0;i<26;i++){
    if(ch[0][i]){
      fail[ch[0][i]]=0;
      q.push(ch[0][i]);
    }
  }
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<26;i++){
      int tmp=ch[u][i];
      if(tmp)fail[tmp]=ch[fail[u]][i],q.push(tmp);
      else ch[u][i]=ch[fail[u]][i];
    }
  }
  for(int i=1;i<=tot;i++)adj[fail[i]+1].pb(i+1); 
  tot++;
/*
  for(int i=1;i<=tot;i++){
    printf("node(%d): ",i);
    for(auto v:adj[i])printf("%d ",v);puts(""); 
  }
*/
  dfs1(1);
  dfs2(1,1);
  for(int i=1;i<=n;i++){
    ed[i]++;
    tag[dfn[ed[i]]]=1;
  }
}

#define ls (u<<1)
#define rs (u<<1|1)
int maxx[N<<2];
void pushup(int u){
  maxx[u]=max(maxx[ls],maxx[rs]);
}
/*
void pushdown(int u){
  if(lzy[u]){
    lzy[ls]+=lzy[u],lzy[rs]+=lzy[u];
    maxx[ls]+=lzy[u],maxx[rs]+=lzy[u];
    lzy[u]=0;
  }
}
*/
void build(int u,int l,int r){
  if(l==r){
    if(tag[l])maxx[u]=0;
    else maxx[u]=-1e9;
    return;
  }
  int mid=l+r>>1;
  build(ls,l,mid),build(rs,mid+1,r);
  pushup(u);
}
/*
void update(int u,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr){
    maxx[u]+=x,lzy[u]+=x;
    return;
  }
  pushdown(u);
  int mid=l+r>>1;
  if(ql<=mid)update(ls,l,mid,ql,qr,x);
  if(qr>mid)update(rs,mid+1,r,ql,qr,x);
  pushup(u);
}
*/
void cover(int u,int l,int r,int pos,int x){
  if(l==r){
    maxx[u]=x;
    return;
  }
  int mid=l+r>>1;
  if(pos<=mid)cover(ls,l,mid,pos,x);
  else cover(rs,mid+1,r,pos,x);
  pushup(u);
}
int query(int u,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return maxx[u];
  int mid=l+r>>1,ret=-1e9;
  if(ql<=mid)ret=max(ret,query(ls,l,mid,ql,qr));
  if(qr>mid)ret=max(ret,query(rs,mid+1,r,ql,qr));
  return ret;
}
int query(int x){
  int res=-1e9;
  while(bl[x]!=0){
    res=max(res,query(1,1,tot,dfn[bl[x]],dfn[x]));
    x=fa[bl[x]];
  }
  return res;
}
multiset<int>qaq[N];

int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    scanf("%s",str+1);
    ins(str,i);
  }
  build();
  build(1,1,tot);
  while(m--){
    int opt;scanf("%d",&opt);
    if(opt==1){
      int pos,x;
      scanf("%d%d",&pos,&x);
      int _=pos;
      pos=ed[pos];
      if(qaq[dfn[pos]].count(a[_]))
        qaq[dfn[pos]].erase(qaq[dfn[pos]].lower_bound(a[_]));
      a[_]=x;
      qaq[dfn[pos]].insert(a[_]);
      //printf("modify %d %d\n", dfn[pos],*qaq[dfn[pos]].rbegin());
      cover(1,1,tot,dfn[pos],*qaq[dfn[pos]].rbegin());
    }else{
      scanf("%s",str+1);
      int len=strlen(str+1),rt=0,ans=-1;
      for(int i=1;i<=len;i++){
        int tmp=ch[rt][str[i]-'a'];
        ans=max(ans,query(tmp+1));
        rt=tmp;
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}

/*
2 20
c
bc
1 1 38
2 bc
*/