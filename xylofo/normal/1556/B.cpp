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

void solve(int tc) {
  int n;
  cin >> n;
  vi v(n);
  rep(i,0,n) {
    int x;
    cin>>x;
    v[i] = x%2;
  }

  ll ans = 1e18;
  rep(t,0,2) {
    int ones = t, zero = 1-t;
    ll cur = 0;
    rep(i,0,n) {
      if(v[i]) {
        if(ones >= n) cur = 1e18;
        cur += abs(ones-i);
        ones += 2;
      }
      else {
        if(zero >= n) cur = 1e18;
        cur += abs(zero-i);
        zero += 2;
      }
    }
    ans = min(ans, cur);
  }
  if(ans == 1e18) ans = -2;
  assert(ans%2 == 0);
  cout << ans/2 << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}