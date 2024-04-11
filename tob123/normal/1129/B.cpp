#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;

int main(){
  cin >> K;
  for(ll i=1000000; i>10; i--){
    ll prod = i + K;
    for(ll j=2; j<=1998; j++){
      if(prod % j == 0 && prod/j <= i && (prod/j+i-1000000)*(j+2) < prod && (prod/j+1+i-1000000)*3 < prod){
        cout << j+2 << endl;
        for(int x=0; x<j-2; x++){
          cout << "0 ";
        }
        cout << "-1 ";
        cout << (prod/j+1) << " ";
        cout << "-1000000 ";
        cout << i << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;

  return 0;
}