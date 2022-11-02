#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;


int main(){
  ll T, N, A, B;
  cin >> T;
  while(T--){
    cin >> N >> A >> B;
    cout << (N+1-min(A,B)) << endl;
  }

  return 0;
}