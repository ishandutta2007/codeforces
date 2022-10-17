#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl;
#define CNO cout<<"No"<<endl;

typedef long long LL;
typedef long double LD;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> f(n);
  rep(i,n) cin >> f[i];
  sort(all(f));
  vector<int> dp(n+1,IINF);
  dp[0]=0;
  repp(i,1,n+1){
    int ma=0;
    perr(j,max(i-k,0),i){
      ma=max(ma,f[j]);
      dp[i]=min(dp[i],dp[j]+2*(ma-1));
    }
  }
  cout << dp[n] << endl;
  return 0;
}