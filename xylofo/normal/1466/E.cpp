#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll mod = 1'000'000'007;

void solve(int tc) {
  int n;
  cin>>n;
  vi v(n);
  rep(i,0,n) cin>>v[i];
  int LG = 61;
  vi cnt(LG);
  rep(i,0,n) {
    rep(bit,0,LG)
      if(v[i]>>bit&1) ++cnt[bit];
  }

  ll ans = 0;
  rep(i,0,n) {
    ll f = 0, g = 0;
    rep(bit,0,LG) {
      ll pw = (1LL<< (ll(bit))) % mod;
      if(v[i]>>bit&1) {
        f = (f + (cnt[bit] * pw) % mod) % mod;
        g = (g + (n * pw) % mod) % mod;
      }
      else {
        g = (g + (cnt[bit] * pw) % mod) % mod;
      }
    }
    ans = (ans + (f * g) % mod) % mod;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}