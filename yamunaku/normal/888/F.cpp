#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  vector<vector<LL>> dp(n,vector<LL>(n,0)),dp2(n,vector<LL>(n,0));
  for(int i=0;i<n;i++){
    dp[i][i]=dp2[i][i]=1;
  }
  for(int i=0;i<n-1;i++){
    if(a[i][i+1]==1) dp[i][i+1]=dp2[i][i+1]=1;
  }
  for(int d=2;d<n;d++){
    for(int i=0;i<n-d;i++){
      if(a[i][i+d]==1){
        for(int k=0;k<d;k++){
          dp[i][i+d]=(dp[i][i+d]+dp2[i][i+k]*dp2[i+k+1][i+d]%MOD)%MOD;
        }
      }
      for(int k=0;k<d;k++){
        dp2[i][i+d]=(dp2[i][i+d]+dp[i][i+k+1]*dp2[i+k+1][i+d]%MOD)%MOD;
      }
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout << dp2[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  vector<LL> dp3(n,0);
  dp3[0]=1;
  // cout << dp3[0] << " ";
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      dp3[i]=(dp3[i]+dp3[j]*dp[j][i]%MOD)%MOD;
    }
    // cout << dp3[i] << " ";
  }
  // cout << endl;
  cout << dp3[n-1] << endl;
  return 0;
}