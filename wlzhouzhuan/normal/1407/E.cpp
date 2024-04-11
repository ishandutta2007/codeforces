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
const int N=500005;
struct Edge{
  int to,nxt,tag;
}edge[N<<1];
int head[N],tot;
void add(int u,int v,int tag){
  edge[++tot]={v,head[u],tag};
  head[u]=tot;
}
int col[N],vis[N],dis[N],n,m;
int main(){
  memset(col,-1,sizeof(col));
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read(),tag=read();
    add(v,u,tag);
  }
  if(n==1){
    puts("0");
    puts("0");
    return 0; 
  }
  queue<int>q;
  q.push(n),col[n]=0,dis[n]=0;
  while(!q.empty()){
    int u=q.front();q.pop();
    vis[u]=1;
    for(int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to,tag=edge[i].tag;
      if(vis[v])continue; 
      if(~col[v]&&col[v]==tag){
        vis[v]=1,q.push(v);
        dis[v]=dis[u]+1;
      }else{
        col[v]=tag^1;
      }
    }
  }
  printf("%d\n",dis[1]?dis[1]:-1);
  for(int i=1;i<=n;i++){
    if(col[i]==-1)col[i]=0;
    printf("%d",col[i]);
  }
  puts("");
  return 0;
}