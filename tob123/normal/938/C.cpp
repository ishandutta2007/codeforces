#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x;

int main(){
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> x;
    ll m=1, n=1;
    for( ; n <= 100000; m++, n++){
      for( ; m>0; m--){
        ll res = n*n-(n/m)*(n/m);
        if(res == x){
          cout << n << " " << m << endl;
          goto END;
        }
        if(res < x){
          break;
        }
      }
      if(n*n-(n/m)*(n/m) == x){
        cout << "fail..." << endl;
        goto END;
      }
    }
    cout << -1 << endl;
END: ;
  }

  return 0;
}