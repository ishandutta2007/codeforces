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
const int N=1005;
const int inf=1e9;
struct Edge{
  int to,nxt,val;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w},head[u]=tot;
}
int dist[N][N],n,m,k;
void dijkstra(int *dist,int S){
  for(int i=1;i<=n;i++)dist[i]=inf;
  dist[S]=0;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.push(make_pair(0,S));
  while(!pq.empty()){
    pii tp=pq.top();pq.pop();
    int u=tp.sec;if(dist[u]<tp.fir)continue;
    for(int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to;
      if(dist[v]>dist[u]+edge[i].val){
        dist[v]=dist[u]+edge[i].val,pq.push({dist[v],v});
      } 
    }
  }
}
struct node{
  int u,v;
}route[N];
int main(){
  n=read(),m=read(),k=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read(),w=read();
    add(u,v,w),add(v,u,w);
  }
  for(int i=1;i<=k;i++)route[i].u=read(),route[i].v=read();
  for(int i=1;i<=n;i++)dijkstra(dist[i],i);
  int ans=1e9;
  for(int i=1;i<=m;i++){
    int u=edge[2*i-1].to,v=edge[2*i].to,w=edge[2*i].val;
    int cur=0;
    for(int i=1;i<=k;i++){
      cur+=min({dist[route[i].u][route[i].v],dist[route[i].u][u]+dist[v][route[i].v],dist[route[i].u][v]+dist[u][route[i].v]});
    }
    ans=min(ans,cur);
  }
  printf("%d\n",ans);
  return 0;
}