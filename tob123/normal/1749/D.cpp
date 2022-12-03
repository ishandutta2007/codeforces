#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 998244353;

int main(){
  ll N, M;
  cin >> N >> M;
  ll non = 0;
  ll cur_non = 1;
  ll fac = 1;
  ll cur2 = 1;
  ll tot = 0;
  vector<char> p(N+1, 1);
  p[1] = false;
  for(int i=1; i<=N; i++){
    if(p[i]){
      for(int j=2*i; j<=N; j+=i)
        p[j] = false;
    }
    if(fac <= M){
      if(p[i])
        fac *= i;
      (cur_non *= (M/fac)%MOD) %= MOD;
      (non += cur_non) %= MOD;
    }
    (cur2 *= M%MOD) %= MOD;
    (tot += cur2) %= MOD;
  }
  ll res = (tot+MOD-non)%MOD;
  cout << res << endl;

  return 0;
}