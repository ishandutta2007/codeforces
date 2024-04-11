#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;
const ll MOD = 998244353;

int N;
ll dp[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  dp[0] = 1;
  for(int i=1; i<=N; i++){
    dp[i] = dp[i-1]*10%MOD;
  }
  for(int i=1; i<=N; i++){
    int x = N-i;
    ll res;
    if(x == 0){
      res = 10;
    }
    else if(x == 1){
      res = 2*90;
    }
    else{
      res = 2*90*dp[x-1]%MOD;
      res += 10*(x-1)*9*9*dp[x-2];
      res %= MOD;
    }
    cout << res << " ";
  }
  cout << endl;

  return 0;
}