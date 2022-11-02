#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll Q, L, R, D;

int main(){
  cin >> Q;
  while(Q--){
    cin >> L >> R >> D;
    if(D < L)
      cout << D << endl;
    else
      cout << (D * (R/D+1)) << "\n";
  }

  return 0;
}