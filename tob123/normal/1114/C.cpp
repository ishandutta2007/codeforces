#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

ll N, B;
vector<pll> F;

void factorize(){
  ll tmp = B;
  for(ll i=2; i*i<=tmp; i++){
    ll cnt = 0;
    while(tmp%i == 0){
      cnt++;
      tmp /= i;
    }
    if(cnt > 0)
      F.push_back({i, cnt});
  }
  if(tmp > 1){
    F.push_back({tmp, 1ll});
  }
}

ll howMany(ll f, ll x){
  if(f > x)
    return 0;
  ll res = x/f;
  res += howMany(f, x/f);
  return res;
}

int main(){
  cin >> N >> B;
  factorize();
  ll res = INF;
  for(auto p : F){
    ll cur = howMany(p.first, N);
    cur /= p.second;
    res = min(res, cur);
  }

  cout << res << endl;

  return 0;
}