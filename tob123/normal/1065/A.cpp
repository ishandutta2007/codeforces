#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  ll T, s, a, b, c;
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> s >> a >> b >> c;
    ll cnt = s/c;
    ll res = cnt + (cnt/a)*b;
    cout << res << endl;
  }

  return 0;
}