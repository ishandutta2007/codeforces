#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;

int main(){
  cin >> N;
  ll res = 0;
  ll n;
  for(n = 2; n<=2*N; n*=2){
    res += (N/n) * (n/2);
    if(N > (N/n)*n + n/2){
      res += n/2;
    }
  }
  cout << res << endl;

  return 0;
}