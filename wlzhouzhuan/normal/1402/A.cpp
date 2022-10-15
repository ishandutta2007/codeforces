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
const int N=200005;
struct E{
  int u,v,w;
  friend bool operator < (const E&x,const E&y){
    return x.w<y.w;
  }
}e[N];
struct Edge{
  int to,nxt,flow;
}edge[N<<1];
int head[N],tot=1;
void add(int u,int v,int flow){
  edge[++tot]={v,head[u],flow},head[u]=tot;
}
void addedge(int u,int v,int flow){
  add(u,v,flow),add(v,u,0);
}
int dep[N],cur[N];
int n,m,S,T;
bool bfs(int S,int T){
  rep(i,1,T)dep[i]=0,cur[i]=head[i]; 
  queue<int>q;q.push(S),dep[S]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    for(register int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to,fl=edge[i].flow;
      if(!dep[v]&&fl){
        dep[v]=dep[u]+1,q.push(v);
      }
    }
  }
  return dep[T]>0;
}
int dfs(int u,int T,int ans){
  if(u==T)return ans;
  int over=0;
  for(register int &i=cur[u];i;i=edge[i].nxt){
    int v=edge[i].to,fl=edge[i].flow;
    if(dep[v]==dep[u]+1&&fl){
      int res=dfs(v,T,min(ans,fl));
      over+=res,ans-=res;
      edge[i].flow-=res,edge[i^1].flow+=res;
      if(!res)dep[v]=0;
      if(!ans)break;
    }       
  }
  return over;
}
int Dinic(int S,int T){
  int ans=0;
  while(bfs(S,T))ans+=dfs(S,T,1e9);
  return ans;
}
bool check(int id){
  tot=1;
  S=2*n+1,T=S+1; 
  rep(i,1,T)head[i]=0;
  rep(i,1,n)addedge(S,i,1);
  rep(i,n+1,2*n)addedge(i,T,1);
  rep(i,1,id)addedge(e[i].u,e[i].v+n,1);
  return Dinic(S,T)==n;
} 
int main(){
  n=read(),m=read();
  rep(i,1,m){
    e[i].u=read(),e[i].v=read(),e[i].w=read();
  }
  sort(e+1,e+m+1);
  int l=1,r=m+1;
  while(l<r){
    int mid=l+r>>1;
    if(check(mid))r=mid;
    else l=mid+1;
  } 
  printf("%d\n",l==m+1?-1:e[l].w);
  return 0;
}