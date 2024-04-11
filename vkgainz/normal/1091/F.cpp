#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 1e5+5;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  ll l[n];
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  string s; cin >> s;
  ll stam = 0LL;
  ll ans = 0LL;
  ll numGrass = 0LL;
  bool wat = false;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'L') {
      stam -= l[i];
      ans += l[i];
      if(stam < 0) {
        if(wat) ans += 3*abs(stam);
        else ans+= 5*abs(stam);
        stam = 0LL;
      }
    }
    else {
      if(s[i] == 'W') {
        wat = true;
        ans += 3*l[i];
      }
      else {
        ans += 5*l[i];
        numGrass += 2*l[i];
      }
      stam += l[i];
    }
    numGrass = min(numGrass, stam);
  }
  if(stam  > 0) {
    ans -= 2*numGrass;
    ans -= stam - numGrass;
  }
  cout << ans;
}