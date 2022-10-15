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
const int N=300005;
ll dp[N][2];
int a[N],n,q;
int main(){
  int T=read();
  while(T--){
    n=read(),q=read();
    rep(i,1,n){
      a[i]=read();
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]+a[i]);
      dp[i][1]=max(dp[i-1][1],dp[i-1][0]-a[i]);
    }
    printf("%lld\n",max(dp[n][0],dp[n][1]));
  }
  return 0;
}