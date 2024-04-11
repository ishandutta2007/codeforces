#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;


vector<ll> f(ll x){
  vector<ll> res;
  for(ll i=2; i*i<=x; i++){
    ll cur = 1;
    while(x % i == 0){
      cur *= i;
      x /= i;
    }
    if(cur != 1){
      res.push_back(cur);
    }
  }
  if(x > 1)
    res.push_back(x);
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll X;
  cin >> X;
  vector<ll> x = f(X);
  ll p=1;
  for(ll a : x){
    p *= a;
    //cout << a << endl;
  }
  ll best = X;
  for(ll m=0; m<1ll<<sz(x); m++){
    ll p2=1;
    for(int i=0; i<sz(x); i++){
      if(m & (1<<i))
        p2 *= x[i];
    }
    best = min(best, max(p2, p/p2));
  }
  cout << best << " " << p/best << endl;

  return 0;
}