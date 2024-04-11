#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll N;

int main(){
  int T;
  cin >> T;
  while(T--){
    cin >> N;
    ll mx = 0;
    map<ll, ll> M;
    for(ll i=(ll)(sqrt(N)+10); i>1; i--){
      ll val = i*(i-1)/2;
      ll cnt = N / val;
      if(cnt > 0){
        mx = max(mx, i);
        M[i] = cnt;
        N %= val;
      }
    }
    string res = "1";
    for(int i=1; i<=mx; i++){
      res.push_back('3');
      for(int j=0; j<M[i]; j++){
        res.push_back('7');
      }
    }
    cout << res << "\n";
  }

  return 0;
}