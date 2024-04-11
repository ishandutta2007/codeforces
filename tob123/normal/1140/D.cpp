#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;

int main(){
  cin >> N;
  ll res = 0;
  for(ll i=3; i<=N; i++){
    res += i*(i-1);
  }

  cout << res << endl;

  return 0;
}