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
const int N=100005;
vector<int>adj[N];
int mx[N][2];
int lo[N],n,m,k;
void dfs1(int u,int fa){
  if(lo[u]){
    mx[u][0]=0;
  }
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs1(v,u);
    if(mx[v][0]+1>=mx[u][0])mx[u][1]=mx[u][0],mx[u][0]=mx[v][0]+1;
    else if(mx[v][0]+1>=mx[u][1])mx[u][1]=mx[v][0]+1;
  }
} 
int qwq[N],ans;
void dfs2(int u,int fa){
  if(max(mx[u][0],qwq[u])<=k)ans++;
  for(auto v:adj[u]){
    if(v==fa)continue;
    if(mx[v][0]+1==mx[u][0])qwq[v]=max(qwq[u],mx[u][1])+1;
    else qwq[v]=max(qwq[u],mx[u][0])+1;
    dfs2(v,u);
  } 
}
int main(){
  memset(mx,-0x3f,sizeof(mx));
  memset(qwq,-0x3f,sizeof(qwq));
  n=read(),m=read(),k=read();
  for(int i=1;i<=m;i++)lo[read()]=1;
  for(int i=1;i<n;i++){
    int u=read(),v=read();
    adj[u].pb(v),adj[v].pb(u);
  }
  dfs1(1,0),dfs2(1,0);
  printf("%d\n",ans);
}