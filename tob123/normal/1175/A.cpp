#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

ll N, K;

ll cnt(ll x){
  if(x == 0)
    return 0;
  if(x % K){
    return x%K + cnt(x - x%K);
  }
  else{
    return 1 + cnt(x/K);
  }
}

int main(){
  int T;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> K;
    cout << cnt(N) << endl;
  }

  return 0;
}