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
#define MOD 998244353
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<LL> dp(k+1,0);
  dp[0]=m;
  for(int i=0;i<n-1;i++){
    // for(int j=0;j<=k;j++){
    //   cout << dp[j] << " ";
    // }
    // cout << endl;
    for(int j=k;j>=1;j--){
      dp[j]=(dp[j]+dp[j-1]*(m-1)%MOD)%MOD;
    }
  }
  cout << dp[k] << endl;
  return 0;
}