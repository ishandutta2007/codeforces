#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<LL> dp(n+1,0),ndp;
  dp[0]=1;
  LL ans=0;
  for(int i=0;i<2*n;i++){
    if(i%2){
      for(int j=0;j<=n;j++){
        ans=(ans+dp[j])%MOD;
      }
    }
    ndp=vector<LL>(n+1);
    ndp[0]=dp[1];
    for(int j=1;j<n;j++){
      ndp[j]=(dp[j-1]+dp[j+1])%MOD;
    }
    ndp[n]=dp[n-1];
    for(int j=n-max(0,i-n)+1;j<=n;j++) ndp[j]=0;
    dp=ndp;
  }
  cout << ans <<endl;
  return 0;
}