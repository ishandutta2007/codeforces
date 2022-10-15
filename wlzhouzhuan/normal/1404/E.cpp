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
const int N=205;
const int E=500005;

struct Edge{
  int to,nxt,flow;
}edge[E<<1];
int head[E],tot=1;
void add(int u,int v,int flow){
  edge[++tot]={v,head[u],flow};
  head[u]=tot;
}
void addedge(int u,int v,int flow){
  //printf("add %d %d flow = %d\n", u, v, flow);
  add(u,v,flow),add(v,u,0);
}

char s[N][N];
int row[N][N],col[N][N],id;
int n,m,S,T;

int dep[E];
bool bfs(int S,int T){
  for(int i=0;i<=id;i++)dep[i]=0;
  queue<int>q;q.push(S),dep[S]=1;
  while(!q.empty()){
    int u=q.front();q.pop();
    for(register int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to,fl=edge[i].flow;
      if(!dep[v]&&fl){
        dep[v]=dep[u]+1;
        q.push(v);
      }
    }
  }
  return dep[T]>0;
}
int dfs(int u,int T,int res){
  if(u==T)return res;
  int ext=0;
  for(register int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to,fl=edge[i].flow;
    if(dep[v]==dep[u]+1&&fl){
      int cur=dfs(v,T,min(res,fl));
      if(!cur)dep[v]=0;
      ext+=cur,res-=cur;
      edge[i].flow-=cur,edge[i^1].flow+=cur;
      if(!res)break; 
    }
  }
  return ext;
}
int Dinic(int S,int T){
  int ret=0;
  while(bfs(S,T))ret+=dfs(S,T,1e9);
  //printf("Dinic ans = %d\n", ret);
  return ret;  
}

int main(){
  n=read(),m=read();
  int ans=0;
  for(int i=1;i<=n;i++){
    scanf("%s",s[i]+1);
    for(int j=1;j<=m;j++){
      if(s[i][j]=='#')ans++;
    }
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=m;j++){
      if(s[i][j]=='#'&&s[i+1][j]=='#')row[i][j]=++id;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<m;j++){
      if(s[i][j]=='#'&&s[i][j+1]=='#')col[i][j]=++id;
    }
  }
  int all=id;
  S=++id,T=++id;
  //printf("S = %d, T = %d\n", S, T);
  for(int i=1;i<n;i++){
    for(int j=1;j<=m;j++){
      if(s[i][j]=='#'&&s[i+1][j]=='#'){
        addedge(S,row[i][j],1);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<m;j++){
      if(s[i][j]=='#'&&s[i][j+1]=='#'){
        addedge(col[i][j],T,1);
      }
    }
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=m;j++){
      if(s[i][j]!='#'||s[i+1][j]!='#')continue;
      if(j<m&&s[i][j+1]=='#')addedge(row[i][j],col[i][j],1);
      if(j>1&&s[i][j-1]=='#')addedge(row[i][j],col[i][j-1],1);
      if(j<m&&s[i+1][j+1]=='#')addedge(row[i][j],col[i+1][j],1);
      if(j>1&&s[i+1][j-1]=='#')addedge(row[i][j],col[i+1][j-1],1);
    }
  }
  //printf("ans = %d\n", ans);
  printf("%d\n",ans-(all-Dinic(S,T)));
  return 0;
}