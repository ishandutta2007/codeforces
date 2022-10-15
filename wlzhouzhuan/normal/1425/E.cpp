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
#define int long long
const long long N=400005;
ll s[N],a[N],d[N],mi[N],pre[N],suf[N];
int n,k;
signed main(){
  n=read(),k=read();
  rep(i,1,n)a[i]=read(),s[i]=s[i-1]+a[i];
  rep(i,1,n)d[i]=read();
  mi[1]=d[1];
  rep(i,2,n)mi[i]=min(mi[i-1],d[i]);
  suf[n]=max(0ll,a[n]-d[n]);
  per(i,n-1,1)suf[i]=max(suf[i+1],s[n]-s[i-1]-d[i]);
  pre[1]=max(0ll,s[n]-d[1]);
  rep(i,2,n)pre[i]=max(pre[i-1],s[n]-s[i-1]-d[i]);
  long long ans=0,sum=0;
  if(!k)ckmax(ans,suf[1]);
  if(k>=1){
    rep(i,1,n-1)ckmax(ans,max(0ll,s[i]-mi[i])+suf[i+1]);
    rep(i,2,n-1)ckmax(ans,max(suf[i+1],pre[i-1]-a[i])+max(0ll,a[i]-d[i]));
  } 
  if(k>=2)ckmax(ans,s[n]-mi[n-1]);
  printf("%lld\n",ans);
  return 0;
}