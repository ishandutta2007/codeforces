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
const int N=100005;
int id[N],tot; 
vector<int>fuck_szh[66];
ll a[N],n,bit[66];
ll f[666][666],g[666][666],ans=1e9;
void floyd(int n){
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i^j)ans=min(ans,g[i][j]+f[i][k]+f[k][j]);
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
}
int main(){
  scanf("%lld",&n);
  rep(i,1,n){
    scanf("%lld",&a[i]);
    rep(j,0,60){
      if(a[i]>>j&1){
        bit[j]++;
        fuck_szh[j].push_back(i);
      }
    }
  }
  rep(j,0,60){
    if(bit[j]>=3){
      puts("3"),exit(0);
    }
  }
  for(int i=1;i<=122;i++){
    for(int j=1;j<=122;j++){
      f[i][j]=g[i][j]=1e9;
    }
  }
  rep(j,0,60){
    if(fuck_szh[j].size()==2){
      int u=fuck_szh[j][0],v=fuck_szh[j][1];
      if(!id[u])id[u]=++tot;
      if(!id[v])id[v]=++tot;
      f[id[u]][id[v]]=f[id[v]][id[u]]=1;
      g[id[u]][id[v]]=g[id[v]][id[u]]=1;
    }
  }
  floyd(tot);
  if(ans==1e9)ans=-1;
  printf("%lld\n",ans);
}