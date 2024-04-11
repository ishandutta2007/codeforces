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
const int N=200005;
struct Edge{
  int to,nxt,flip;
}edge[N<<1];
int head[N],tot=1;
void add(int u,int v){
  edge[++tot]={v,head[u],-1};
  head[u]=tot;
}
int vis[N];
int n,m;
void dfs(int u,int fa,int rev){
  if(vis[u])return;
  vis[u]=1;
  for(int i=head[u];i;i=edge[i].nxt){
    int v=edge[i].to;
    if(v==fa)continue;
    if(~edge[i].flip&&edge[i].flip!=rev)puts("NO"),exit(0);
    if(~edge[i^1].flip&&edge[i^1].flip==rev)puts("NO"),exit(0);
    edge[i].flip=rev,edge[i^1].flip=rev^1;
    dfs(v,u,rev^1);
  }
}
int main(){
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    add(u,v),add(v,u);
  }
  dfs(1,0,0);
  puts("YES");
  for(int i=2;i<=tot;i+=2){
    if(edge[i].flip)putchar('1');
    else putchar('0');
  }
  puts("");
  return 0;
}