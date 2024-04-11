#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
ll A[200001], B[200001];
map<pair<ll,ll>,ll> M;

ll gcd(ll a, ll b){
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

pair<ll,ll> bruch(ll a, ll b){
  if(a * b < 0){
    a = abs(a);
    b = abs(b);
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    return make_pair(-a, b);
  }
  else{
    a = abs(a);
    b = abs(b);
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    return make_pair(a, b);
  }
}

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }

  ll allPos = 0;
  for(int i=0; i<N; i++){
    if(A[i] == 0){
      if(B[i] == 0)
        allPos ++;
    }
    else{
      M[bruch(B[i], A[i])]++;
    }
  }

  ll best = 0;
  for(auto p : M){
    best = max(p.second, best);
  }
  cout << (best+allPos) << endl;

  return 0;
}