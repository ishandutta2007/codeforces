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
const int N=202;
char s[N],t[N];
int dp[N][N][N];
int n,K;
int main(){
  scanf("%d%d",&n,&K);
  scanf("%s%s",s+1,t+1);
  if(t[1]==t[2]){
    int cur=0;
    for(int i=1;i<=n;i++){
      if(s[i]==t[1])cur++;
      else if(K)s[i]=t[1],K--,cur++;
    }
    printf("%d\n",(cur-1)*cur/2);
  }else{
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
      for(int k=0;k<=K;k++){
        for(int j=0;j<=i;j++){
          ckmax(dp[i][k][j],dp[i-1][k][j]);
          if(s[i]==t[1]||s[i]==t[2]){
            if(k>=1)ckmax(dp[i][k][j],dp[i-1][k-1][j]);
          }
          if(s[i]==t[1]){
            if(j>=1)ckmax(dp[i][k][j],dp[i-1][k][j-1]);
          }else if(k>=1&&j>=1)ckmax(dp[i][k][j],dp[i-1][k-1][j-1]);
          if(s[i]==t[2]){
            ckmax(dp[i][k][j],dp[i-1][k][j]+j);
          }else if(k>=1)ckmax(dp[i][k][j],dp[i-1][k-1][j]+j);
          //printf("dp[%d][%d][%d]=%d\n",i,k,j,dp[i][k][j]);
        }
      } 
    }
    int ans=-1e9;
    for(int k=0;k<=K;k++){
      for(int j=0;j<=n;j++){
        ans=max(ans,dp[n][k][j]);
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}