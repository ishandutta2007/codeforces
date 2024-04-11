#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,0,n) cin>>v[i];

  ll ans = 0;
  rep(l,0,n) if(l % 2  == 0) {
    ll hi = v[l];
    ll lo = 1;
    rep(r,l+1,n) {
      if(r%2) {
        debug(l, r, lo, hi);
        if(v[r] >= lo) {
          ll cur = min(hi, v[r])-lo+1;
          debug(cur);
          ans += cur;
        }
        hi -= v[r], lo -= v[r];
      }
      else hi += v[r], lo += v[r];
      lo = max<ll>(lo,0);
      hi = max<ll>(hi,-1);
    }
  }
  cout << ans << endl;
}