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
const int N=100005;
vector<int>adj[N];
int n,a,b,da,db;

int dep[N];
void dfs(int u,int fa){
  dep[u]=dep[fa]+1;
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs(v,u); 
  }
}
int main(){
  int T=read();
  while(T--){
    n=read(),a=read(),b=read(),da=read(),db=read();
    for(int i=1;i<=n;i++)adj[i].clear();
    for(int i=1;i<n;i++){
      int u=read(),v=read();
      adj[u].pb(v),adj[v].pb(u);
    }
    if(2*da>=db){
      puts("Alice");continue;
    }
    dfs(a,0);
    int rt=0;
    for(int i=1;i<=n;i++)if(dep[rt]<dep[i])rt=i;
    if(dep[b]-1<=da){
      puts("Alice");continue;
    }
    dfs(rt,0);
    rt=0;
    for(int i=1;i<=n;i++)if(dep[rt]<dep[i])rt=i;
    if(dep[rt]<=2*da+1){
      puts("Alice");
    }else{
      puts("Bob");
    }
  }
  return 0;
}