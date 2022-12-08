#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;


int main() {
  int n,m;
  cin>>n>>m;
  int a[m+1];
  rep(i,m+1)a[i]=0;
  rep(i,n){
    int l,r;
    cin>>l>>r;
    a[l-1]++;
    a[r]--;
    }
  rep(i,m)a[i+1]+=a[i];
  int num1[m+1],num2[m+1];
  num1[0]=0;num2[m]=0;
  int dp1[m+1],dp2[m+1];
  rep(i,m+1)dp1[i]=dp2[i]=inf;
  rep(i,m){
    *upper_bound(dp1,dp1+m,a[i])=a[i];
    num1[i+1]=lower_bound(dp1,dp1+m,inf)-dp1;
    }
  reverse(a,a+m);
  rep(i,m){
    *upper_bound(dp2,dp2+m,a[i])=a[i];
    num2[m-1-i]=lower_bound(dp2,dp2+m,inf)-dp2;
    }
  int ans=0;
  rep(i,m+1)ans=max(ans,num1[i]+num2[i]);
  cout<<ans<<endl;
  return 0;
  }