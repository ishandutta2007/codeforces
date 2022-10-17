#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=int(b); a<int(c); ++a)
using namespace std;
typedef long long ll;


const ll mod = 998244353;
int N = 5000+10;
vector<ll> inv(N,1), fac(N, 1), ifac(N, 1);

ll binom(ll m, ll k) {
  if(k < 0 || k > m) return 0LL;
  return fac[m] * ifac[k] % mod * ifac[m-k] % mod;
};

int n;
vector<int> a;
vector<vector<vector<ll>>> DP;

ll calc(int c, int holes, int done, int tot) {
  if(holes<0) return 0;
  if(holes>=(n/2)+1) return 0;
  if(c<0 && holes==0) return 1;
  else if(c<0 && holes>0) return 0;
  if(DP[c][holes][done]!=-1) return DP[c][holes][done];
  if(a[c]==0) {
    return DP[c][holes][done]=calc(c-1,holes,done,tot)%mod;
  }
  DP[c][holes][done]=0;
  if(holes>=a[c]) {
    DP[c][holes][done]+=binom(holes, a[c])*calc(c-1,holes-a[c],done,tot)%mod;
  }
  if(holes>=a[c]-1 && tot<n/2-1) {
    DP[c][holes][done]+=binom(holes,a[c]-1)*calc(c-1, holes-a[c]+2,done,tot+1)%mod;
  } else if(holes>=a[c]-1 && tot==n/2-1) {
    DP[c][holes][done]+=binom(holes,a[c]-1)*calc(c-1,holes-a[c]+3,1,tot+1)%mod;
  }
  return DP[c][holes][done]%mod;
}

void solve() {
  cin >> n;
  a.clear();
  a.resize(n,0);
  int ma = 0;
  rep(i,0,n){
    int ai; cin >> ai;
    ++a[ai-1];
    ma=max(ma,ai-1);
  }
  if(a[ma]>1) {
    cout << 0 << endl;
    return;
  }
  DP.clear();
  DP.resize(n,vector<vector<ll>>(n/2+2,vector<ll>(2,-1)));
  if(n==2) cout << 1 << endl;
  else cout << calc(ma-1,0,0,1) << endl;
}

int main() {
  rep(i,2,N) {
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    fac[i] = fac[i-1] * i % mod;
    ifac[i] = ifac[i-1] * inv[i] % mod;
  }
  int t; cin >> t;
  rep(i,0,t) solve();
}