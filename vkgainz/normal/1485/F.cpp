#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 2e6+5;
const int LOG = 21;
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin >> b[i];
    vector<ll> dp(n+1);
    vector<ll> numzero(n+1);
    map<ll, ll> in;
    dp[0] = 1LL;
    numzero[0] = 1LL;
    ll sum = 0LL;
    in[sum] = 1LL;
    ll mod  = 1e9 + 7;
    for(int i=1;i<=n;i++) {
      sum+=b[i-1];
      dp[i] = (dp[i-1]*1LL*2-numzero[i-1]) % mod;
      numzero[i] = in[sum]%mod;
      in[sum] = dp[i]%mod;
    }
    if(dp[n]<0) dp[n]+=mod;
    cout << dp[n] << "\n";
  }
}