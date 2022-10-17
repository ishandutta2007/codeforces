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

LL waru(LL x){
  LL ans=1;
  LL c=MOD-2;
  while(c){
    if(c%2) ans=ans*x%MOD;
    x=x*x%MOD;
    c/=2;
  }
  return ans;
}

int main(){
  LL w[61];
  w[0]=0;
  for(int i=1;i<=60;i++) w[i]=waru(i);
  LL n,m;
  int k;
  cin >> n >> k;
  m=n;
  list<pair<LL,int>> so;
  int count;
  for(LL i=2;i<=sqrt(m);i++){
    if(m%i==0){
      count=0;
      while(m%i==0){
        m/=i;
        count++;
      }
      so.push_back({i,count});
    }
  }
  if(m>1) so.push_back({m,1});
  LL ans=1;
  LL p,c;
  for(auto pp:so){
    p=pp.first;
    c=pp.second;
    vector<vector<int>> dp(c+1,vector<int>(k+1,0));
    dp[0][0]=1;
    for(int i=1;i<=c;i++){
      dp[i][0]=dp[i-1][0]*p%MOD;
    }
    for(int i=1;i<=k;i++){
      for(int j=0;j<=c;j++){
        for(int k=0;k<=j;k++){
          dp[j][i]=(dp[j][i]+dp[k][i-1]*w[j+1]%MOD)%MOD;
        }
      }
    }
    // cout << p SP c SP dp[c][k] << endl;
    ans=ans*dp[c][k]%MOD;
  }
  cout << ans << endl;
  return 0;
}