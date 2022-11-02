#include <bits/stdc++.h>
using namespace std;

int N, P, L, R;

int main(){
  cin >> N >> P >> L >> R;
  if(L == 1 && R == N){
    cout << 0 << endl;
  }
  else if(L == 1){
    cout << abs(P-R)+1 << endl;
  }
  else if(R == N){
    cout << abs(P-L)+1 << endl;
  }
  else{
    cout << 2+R-L + min(abs(P-L), abs(P-R)) << endl;
  }

  return 0;
}