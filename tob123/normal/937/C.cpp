#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll K, D, T;

int main(){
  cin >> K >> D >> T;
  T *= 2;

  ll oldD = D;
  D = D * (K/D);
  while(D < K)
    D += oldD;
  ll cycle = K + D;
  ll cycleT = D;
  ll full = T/cycle;
  ld res = cycleT * full;
  T -= full * cycle;
  if(T > 2*K){
    res += K; 
    T -= 2*K;
    res += T;
  }
  else{
    res += ((ld)T) / 2.0;
  }

  cout << fixed << setprecision(2) << res << endl;

  return 0;
}