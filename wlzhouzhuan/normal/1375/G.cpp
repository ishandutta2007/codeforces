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
vector<int>adj[N];
int n;
int B,W;
int col[N];
void dfs(int u,int fa){
  col[u]=col[fa]^1;
  if(col[u])W++;else B++;
  for(auto v:adj[u]){
    if(v==fa)continue;
    dfs(v,u);
  }
}
int main(){
  n=read();
  rep(i,1,n-1){
    int u=read(),v=read();
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,0);
  printf("%d\n",min(B,W)-1);
  return 0;
}