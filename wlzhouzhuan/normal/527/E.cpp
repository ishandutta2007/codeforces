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
const int N=300005;
struct Edge{
  int to,nxt,id;
}edge[N<<1];
int head[N],tot=1;
void add(int u,int v,int id){
  edge[++tot]={v,head[u],id};
  head[u]=tot;
}
vector<pii>ans;
int vis[N],rev;
void dfs(int u){
  for(register int &i=head[u];i;i=edge[i].nxt){
    if(vis[edge[i].id])continue; 
    vis[edge[i].id]=1;
    int v=edge[i].to;
    dfs(v);
    if(rev)ans.pb({v,u});
    else ans.pb({u,v});
    rev^=1;
  }
}
int deg[N],n,m;
int main(){
  n=read(),m=read();
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    add(u,v,i),add(v,u,i);
    deg[u]++,deg[v]++;
  }
  vector<int>odd;
  for(int i=1;i<=n;i++)if(deg[i]&1)odd.pb(i);
  for(int i=0,j=1;j<odd.size();i+=2,j+=2){
    m++;
    add(odd[i],odd[j],m);
    add(odd[j],odd[i],m);
    deg[odd[i]]++,deg[odd[j]]++;
  }
  if(m&1){
    m++;
    add(1,1,m);
  }
  dfs(1);
  printf("%d\n",m);
  for(auto v:ans)printf("%d %d\n",v.fir,v.sec); 
  return 0;
}