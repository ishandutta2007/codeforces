#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 1e6+10;

ll N, X;
ll A[n], B[n], S[n];
ll sc, bc;

void printSB(){
  for(int i=0; i<X; i++){
    cout << S[i] << " ";
  }
  cout << endl;
  for(int i=0; i<X; i++){
    cout << B[i] << " ";
  }
  cout << endl;
  cout << endl;
}

int main(){
  cin >> N >> X;
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i]--;
  }
  for(int i=0; i<X; i++){
    S[i] = i;
    B[i] = i;
  }
  ll x = 0;
  for(int i=0; i<N; i++){
    x = max(x, A[i]);
    B[A[i]] = x;
  }
  x = X-1;
  for(int i=N-1; i>=0; i--){
    x = min(x, A[i]);
    S[A[i]] = x;
  }
  //printSB();
  sc = X+1;
  bc = -1;
  for(ll i=0; i<X; i++){
    if(S[i] != i){
      sc = min(sc, i);
      bc = max(bc, S[i]);
    }
    if(B[i] != i){
      bc = max(bc, i);
      sc = min(sc, B[i]);
    }
  }
  //cout << sc << " " << bc << endl;

  ll m = 0, s = 0;
  //cout << "X: " << X << endl;
  for(ll i=0; i<=min(sc, X-1); i++){
    m = max(m, i);
    //cout << m << " " << bc << " -> ";
    //cout << X - max(m, bc) << endl;
    s += X - max(m, bc);
    m = max(m, B[i]);
  }

  cout << s << endl;

  return 0;
}