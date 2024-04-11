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
ll dp[N],sum[N];
int x[N],y[N],t[N],r,n;
int main(){
  r=read(),n=read();
  memset(dp,-0x3f,sizeof(dp)),dp[0]=0;
  x[0]=1,y[0]=1,t[0]=0;
  for(int i=1;i<=n;i++){
    t[i]=read(),x[i]=read(),y[i]=read();
    if(i>=2*r)ckmax(dp[i],sum[i-2*r]+1);
    for(int j=i-1;j>i-2*r&&j>=0;j--){
      if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
        ckmax(dp[i],dp[j]+1);
      }
    }
    sum[i]=max(sum[i-1],dp[i]);
  }
  printf("%lld\n",max(0ll,*max_element(dp+1,dp+n+1)));
  return 0;
}