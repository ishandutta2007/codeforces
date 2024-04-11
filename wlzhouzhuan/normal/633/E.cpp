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
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=buf;
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
const int N=1e6+5;
int v[N],c[N],n,k,ans[N];
int f[N][20],g[N][20],lg[N];
void pre(){
  lg[1]=0;
  for(int i=2;i<N;i++)lg[i]=lg[i>>1]+1;
  for(int j=1;j<20;j++){
    for(int i=1;i+(1<<j)-1<=n;i++){
      f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
      g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
    }
  }
}
int frmq(int l,int r){
  int len=lg[r-l];
  return max(f[l][len],f[r-(1<<len)+1][len]);
}
int grmq(int l,int r){
  int len=lg[r-l];
  return min(g[l][len],g[r-(1<<len)+1][len]);
}
int main(){
  n=read(),k=read();
  for(int i=1;i<=n;i++)v[i]=f[i][0]=read();
  for(int i=1;i<=n;i++)c[i]=g[i][0]=read();
  pre();
  for(int i=1;i<=n;i++){
    int l=i,r=n;
    while(l<r){
      int mid=l+r>>1;
      int x=frmq(i,mid)*100,y=grmq(i,mid);
      if(x>=y)r=mid;
      else l=mid+1;
    }
    for(int j=max(i,l-3);j<=min(n,l+3);j++){
      ans[i]=max(ans[i],min(frmq(i,j)*100,grmq(i,j)));
    }
  }
  sort(ans+1,ans+n+1);
  double Ans=0,p=1;
  if(k==1){
    for(int i=1;i<=n;i++)Ans+=ans[i];
    printf("%.12lf\n",Ans/n);
    return 0;
  }
  //for(int i=n-1;i>=n-k+1;i--)p=p*i/i;
  p/=n;
  for(int i=1;i<=n;i++){
    Ans+=ans[i]*p;
    p=p*(n-i-k+1)/(n-i);
  }
  printf("%.12lf\n",k*Ans);
  return 0;
}