#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1000000000000ll;

int N, L;
vector<ll> C;
vector<ll> V;

ll calc(ll l){
  int i;
  for(i=0; V[i]<l; i++) ;
  //cout << l << endl;

  if(V[i] == l){
    return C[i];
  }
  return min(C[i], C[i-1] + calc(l - V[i-1]));
}

int main(){
  cin >> N >> L;
  C.resize(N);
  V.resize(N);
  V[0] = 1;
  for(int i=0; i<N; i++){
    cin >> C[i];
    if(i > 0){
      C[i] = min(C[i], 2*C[i-1]);
      V[i] = V[i-1] * 2;
    }
  }
  for(int i=N-1; V[i] < L; i++){
    V.push_back(2*V[i]);
    C.push_back(2*C[i]);
  }
  for(int i=C.size()-2; i>=0; i--){
    C[i] = min(C[i], C[i+1]);
  }
  /*
  for(int i=0; i<V.size(); i++){
    cout << i << ": " << V[i] << ", " << C[i] << endl;
  }
  */

  cout << calc(L) << endl;

  return 0;
}