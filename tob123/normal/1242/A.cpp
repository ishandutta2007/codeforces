#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e6+10;

ll N;
vector<ll> D;
bool P[n];

bool notP(ll x){
  for(ll y=x; y<=N; y*=x){
    if(y == N){
      return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(ll i=2; i<n; i++){
    P[i] = true;
  }
  for(ll i=2; i<n; i++){
    if(P[i]){
      for(ll j=2*i; j<n; j+=i){
        P[j] = false;
      }
    }
  }
  for(ll i=2; i*i<=N; i++){
    if(N % i == 0 && P[i]){
      D.push_back(i);
      if(notP(i)){
        D.push_back(N/i);
      }
    }
  }
  /*
  for(int x : D)
    cout << x << " ";
  cout << endl;
  */
  if(sz(D) == 0){
    cout << N << endl;
  }
  else if(sz(D) == 1){
    cout << D[0] << endl;
  }
  else{
    cout << 1 << endl;
  }

  return 0;
}