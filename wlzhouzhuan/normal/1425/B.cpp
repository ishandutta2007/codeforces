#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
#define int long long
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<20],*O=buf;
int getc(){
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
int read(){
  int x=0;
  char ch=getc();
  while(!isdigit(ch))ch=getc();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getc();
  return x;
}
void print(ll x){
  if(x>9)print(x/10);
  *O++=x%10+'0';
}
const int N=100005;
const int mod=1e9+7;
int a[N],ans;
int ff[N],sz[N],n,m,num;
int find(int x){
  return ff[x]==x?x:ff[x]=find(ff[x]);
}
signed main(){
  n=read(),m=read();
  for(int i=1;i<=n;i++)ff[i]=i;
  for(int i=1;i<=m;i++){
    int u=read(),v=read();
    if(u==1||v==1||find(u)==find(v));
    else{
      ff[find(u)]=find(v);
    }
  }
  for(int i=1;i<=n;i++)sz[find(i)]++;
  num=0;
  for(int i=2;i<=n;i++){
    if(find(i)==i){
      a[num++]=sz[i]+1;
    }
  }
  int mid=m+1;
  vector<int>f[2],dp;
  dp.resize(2*m+2);
  f[0].resize(2*m+2),f[1].resize(2*m+2);
  f[0][mid]=1;
  for(int i=0;i<num;i++){
    vector<int>g[2];
    g[0].resize(2*m+2),g[1].resize(2*m+2);
    f[0].swap(g[0]),f[1].swap(g[1]);
    for(int o=0;o<2;o++){
      for(int j=-m;j<=m;j++){
        if(abs(j-a[i])<=m){
          f[o][mid+j]=(f[o][mid+j]+g[o][mid+j-a[i]])%mod;
        }
        f[o][mid+j]=(f[o][mid+j]+g[o][mid+j])%mod;
        if(abs(j+a[i])<=m){
          f[o][mid+j]=(f[o][mid+j]+g[o][mid+j+a[i]])%mod;
        }
      }
    }
    //cerr<<"pass";
    for(int j=1;j<g[0].size();j++){
      g[0][j]=(g[0][j]+g[0][j-1])%mod;
    }
    //cerr<<"system";
    for(int j=-m;j<=m;j++){
      int l=max(-m,j-a[i]+2);
      int r=min(m,j+a[i]-2);
      if(l>r)continue;
      f[1][mid+j]=(f[1][mid+j]+g[0][mid+r]-g[0][mid+l-1]+mod)%mod;
    }
    //cerr<<"test";
  }
  //cerr<<"ok!\n";
  ans=2*f[1][mid]%mod;
  dp[mid]=1;
  for(int i=0;i<num;i++){
    vector<int>g;
    g.resize(2*m+2),dp.swap(g);
    for(int j=-m;j<=m;j++){
      if(abs(j-a[i])<=m){
        dp[mid+j]=(dp[mid+j]+g[mid+j-a[i]])%mod;
      }
      if(abs(j+a[i])<=m){
        dp[mid+j]=(dp[mid+j]+g[mid+j+a[i]])%mod;
      }
    }
  }
  ans=(ans+dp[mid])%mod;
  f[0].clear(),f[1].clear();
  f[0].resize(2*m+2),f[1].resize(2*m+2);
  f[0][mid]=1;
  for(int i=0;i<num;i++){
    vector<int>g[2];
    g[0].resize(2*m+2),g[1].resize(2*m+2);
    f[0].swap(g[0]),f[1].swap(g[1]);
    for(int o=0;o<2;o++){
      for(int j=-m;j<=+m;j++){
        if(abs(j-a[i])<=m){
          f[o][mid+j]=(f[o][mid+j]+g[o][mid+j-a[i]])%mod;
        }
        if(abs(j+a[i])<=m){
          f[o][mid+j]=(f[o][mid+j]+g[o][mid+j+a[i]])%mod;
        }
      }
    }
    for(int j=-m;j<=m;j++){
      if(abs(j-a[i]+1)<=m){
        f[1][mid+j]=(f[1][mid+j]+g[0][mid+j-a[i]+1])%mod;
      }
      if(abs(j-a[i]+1)<=m){
        f[1][mid+j]=(f[1][mid+j]+g[0][mid+j+a[i]-1])%mod;
      }
    }
  }
  ans=(ans+f[1][mid]*2)%mod;
  printf("%lld\n",(ans%mod+mod)%mod);
  return 0;
}