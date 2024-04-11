#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;
ll dp[100001][2];
ll n,m,inv,a[100001],b[100001];

ll rec(int n,int ok){
  if(dp[n][ok]!=-1)return dp[n][ok];
  if(ok){
    ll ret1=rec(n-1,1);
    ll ret2=rec(n-1,0);
    if(0<a[n]&&a[n]<=b[n])ret2=0;
    if(a[n]==0&&b[n]==0) {
      ll res=m*(m-1)/2;
      ret2=ret2*res %mod;
      ret2=ret2*inv %mod;
      ret2=ret2*inv %mod;
      }
    if(a[n]==0&&b[n]>0){
      ret2=ret2*(m-b[n]) %mod;
      ret2=ret2*inv %mod;
      }
    if(a[n]>0&&b[n]==0){
      ret2=ret2*(a[n]-1) %mod;
      ret2=ret2*inv %mod;
      }
    return dp[n][1]=(ret1+ret2)%mod;
    }
  ll ret=rec(n-1,0);
  if(a[n]!=0&&a[n]==b[n])return dp[n][0]=ret;
  if(a[n]==0||b[n]==0) return dp[n][0]=ret*inv %mod;
  return dp[n][0]=0;
  }
  
int main(){
  cin>>n>>m;
  int k=mod-2;
  ll now=m;
  inv=1;
  while(k>0){
    if(k&1)inv=inv*now %mod;
    now=now*now %mod;
    k>>=1;
    }
  rep(i,n)cin>>a[i+1];
  rep(i,n)cin>>b[i+1];
  rep(i,n+1)dp[i][0]=dp[i][1]=-1;
  dp[0][0]=1;dp[0][1]=0;
  cout<<rec(n,1)<<endl;
  return 0;
  }