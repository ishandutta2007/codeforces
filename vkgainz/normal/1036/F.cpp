#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 2e6+5;
bool getPow(ll d, int x, ll n) {
  ll ans = 1;
  for(int i=1;i<=x;i++) {
    if(ans*d>n) return false;
    ans*=d;
  }
  return true;
}
int main() {
  int t; cin >> t;
  int num[60];
  for(int i=0;i<60;i++)
    num[i] = 0;
  num[1] = 1;
  for(int i=1;i<60;i++) {
    for(int j=2*i;j<60;j+=i)
      num[j]-=num[i];
  }
  while(t--) {
    ll n; cin >> n;
    ll ans = 0;
    ans+=(n-1)*1LL*num[1];
    ll x = sqrt(n);
    if((x+1)*(x+1)<=n)
      x = x+1;
    if(x*x>n)
      --x;
    ans+=(x-1)*1LL*num[2];
    for(ll i=3;i<60;i++) {
      ll d = pow(n, 1.0/i);
      if(getPow(d+1, i, n))
        ++d;
      if(!getPow(d, i, n))
        --d;
      ans+=(d-1)*1LL*num[i];
    }
    cout << ans << "\n";
  }
}