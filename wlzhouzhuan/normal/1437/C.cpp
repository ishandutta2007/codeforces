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

const int N=505;
int t[N],n;
int dp[N][N];

void work(){
  n=read();
  for(int i=1;i<=n;i++)t[i]=read();
  sort(t+1,t+n+1);
  for(int i=0;i<=2*n;i++){
    for(int j=0;j<=n;j++){
      dp[i][j]=1e9;
    }
  }
  dp[0][0]=0;
  for(int i=1;i<=2*n;i++){
    for(int j=0;j<=n;j++){
      dp[i][j]=min(dp[i-1][j],j?dp[i-1][j-1]+(int)abs(t[j]-i):1000000000);
    }
  }
  int ans=1e9;
  for(int i=1;i<=2*n;i++)ans=min(ans,dp[i][n]);
  printf("%d\n",ans);
}
int main(){
  int T=read();
  while(T--)work();
  return 0;
}