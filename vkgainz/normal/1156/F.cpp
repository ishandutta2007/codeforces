#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 200+5;

ll num[5000][5001]; //number of increasing sequences that end at a[i] and have j numbers
ll mod = 998244353;

ll getpow(ll b, ll p) {
  if(p == 0) return 1LL;
  ll x = getpow(b, p/2);
  if(p%2) return (((x*x)%mod*b)%mod+mod)%mod;
  else return ((x*x)%mod+mod)%mod;
}
ll inv(ll x) {
  return getpow(x, mod - 2);
}
int main() {
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  sort(a, a+n);
  for(int j=1;j<=5000;j++) {
    int l = 0;
    ll x = 0LL;
    for(int i=0;i<n;i++) {
      if(j==1) num[i][j] = 1LL;
      else {
        while(l<n && a[l] < a[i]) {
          x+=num[l][j-1];
          x%=mod;
          ++l;
        }
        num[i][j] = x;
      }
    }
  }
  ll fac[5001];
  fac[0] = 1LL;
  for(int i=1;i<=5000;i++) fac[i] = fac[i-1]*1LL*i%mod;
  ll numWin = 0LL;
  int numEq[n];
  memset(numEq, 0, sizeof(numEq));
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(a[j] == a[i]) ++numEq[i];
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=1;j<n;j++) {
      numWin+=num[i][j]*1LL*(numEq[i]-1)%mod*fac[n-j-1]%mod;
      numWin%=mod;
    }
  }
  ll numTot = inv(fac[n]);
  cout << (numWin*numTot%mod+mod)%mod << "\n";
}