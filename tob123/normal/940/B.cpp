#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K, A, B;

int main(){
  cin >> N >> K >> A >> B;
  if(K == 1){
    cout << A*(N-1) << endl;
    return 0;
  }
  ll X = N;
  ll cost = 0;
  while(X >= K){
    ll rest = X%K;
    cost += A*rest;
    X -= rest;
    cost += min(B, A*(X - X/K));
    X /= K;
  }
  cost += A*(X-1);
  cout << cost << endl;

  return 0;
}