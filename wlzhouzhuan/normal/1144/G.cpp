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
const int inf=1e9;
int dp[N][2];
int a[N],ans[N],n;
int main(){
  n=read();
  for(int i=1;i<=n;i++)a[i]=read();
  //dp[0][0]=-inf,dp[0][1]=inf;
  dp[1][0]=inf,dp[1][1]=-inf;
  for(int i=2;i<=n;i++){
    dp[i][0]=-inf,dp[i][1]=inf;
    if(a[i]>a[i-1])dp[i][0]=max(dp[i][0],dp[i-1][0]);
    if(a[i]>dp[i-1][1])dp[i][0]=max(dp[i][0],a[i-1]);
    if(a[i]<a[i-1])dp[i][1]=min(dp[i][1],dp[i-1][1]);
    if(a[i]<dp[i-1][0])dp[i][1]=min(dp[i][1],a[i-1]);
    //printf("dp[%d][0]=%d,dp[%d][1]=%d\n",i,dp[i][0],i,dp[i][1]);
  }
  if(dp[n][0]==-inf&&dp[n][1]==inf)puts("NO"),exit(0);
  int op;
  if(dp[n][0]!=-inf)op=0;
  else op=1;
  for(int i=n;i>=1;i--){
    ans[i]=op;
    if(i==1)break;
    if(!op){
      if(a[i]>a[i-1]&&dp[i-1][0]==dp[i][0])op=0;
      else if((a[i]>dp[i-1][1])&&dp[i][0]==a[i-1])op=1;
    }else{
      if(a[i]<a[i-1]&&dp[i][1]==dp[i-1][1])op=1;
      else if((a[i]<dp[i-1][0])&&dp[i][1]==a[i-1])op=0;
    }
  }
  puts("YES");
  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
  puts("");
  return 0;
}