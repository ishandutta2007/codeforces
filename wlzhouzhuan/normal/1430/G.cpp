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
const int N=50005;
const ll inf=1e15;
struct Edge{
  int to,nxt;
  ll flow;
}edge[N<<1];
int cur[N],head[N],tot=1;
ll val[N];
void add(int u,int v,ll flow){
  edge[++tot]={v,head[u],flow},head[u]=tot;
}
void addedge(int u,int v,ll flow){
  //printf("addedge %d %d, flow = %lld\n",u,v,flow);
  add(u,v,flow),add(v,u,0);
}
int dep[N];
bool bfs(int S,int T){
  queue<int>q;
  rep(i,0,T)cur[i]=head[i],dep[i]=0;
  q.push(S),dep[S]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    for(register int i=head[u];~i;i=edge[i].nxt){
      int v=edge[i].to;
      ll fl=edge[i].flow;
      if(!dep[v]&&fl){
        dep[v]=dep[u]+1;
        q.push(v);
      }
    }
  }
  return dep[T]>0;
}
ll dfs(int u,int T,ll ans){
  if(u==T)return ans;
  ll over=0;
  for(register int &i=cur[u];~i;i=edge[i].nxt){
    int v=edge[i].to;
    ll fl=edge[i].flow;
    if(dep[v]==dep[u]+1&&fl){
      ll res=dfs(v,T,min(ans,fl));
      edge[i].flow-=res,edge[i^1].flow+=res;
      ans-=res,over+=res;
      if(!res)dep[v]=0;
      if(!ans)break;
    }
  }
  return over;
}
ll Dinic(int S,int T){
  ll ans=0;
  while(bfs(S,T))ans+=dfs(S,T,inf);
  return ans; 
}
bool visited[N];
void fuck_szh_dzh(int S){
  queue<int>q;
  q.push(S),visited[S]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    for(register int i=head[u];~i;i=edge[i].nxt){
      int v=edge[i].to;
      ll fl=edge[i].flow;
      if(fl&&!visited[v]){
        visited[v]=1;
        q.push(v);
      }
    }
  }
} 
int n,m,S,T;
int main(){
  mset(head,-1);
  n=read(),m=read();
  rep(i,1,m){
    int x=read()-1,y=read()-1,w=read();
    swap(x,y);
    rep(j,0,n-1)addedge(x*(n+1)+j,y*(n+1)+j+1,inf);
    val[x]-=w,val[y]+=w;
  }
  S=n*(n+1),T=S+1;
  //cerr<<"S="<<S<<", T="<<T<<'\n';
  rep(i,0,n-1){
    addedge(S,i*(n+1),inf),addedge(i*(n+1)+n,T,inf);
    rep(j,0,n-1){
      addedge(i*(n+1)+j,i*(n+1)+j+1,val[i]*j+1e9);
    }
  }
  ll flow=Dinic(S,T);
  //cerr<<"flow = "<<flow<<'\n';
  fuck_szh_dzh(S);
  rep(i,0,n-1){
    int kk=i*(n+1);
    while(visited[kk])kk++;
    printf("%d ",kk-i*(n+1));
  }
  puts("");
  return 0;
}