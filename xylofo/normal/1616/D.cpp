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
  int n, x;
  cin >> n;
  vector<ll> a(n);
  rep(i,0,n) cin>>a[i];
  cin>>x;
  rep(i,0,n) a[i] -= x;
  debug(a);

  vector<ll> dp(4,-1e9);
  dp[0] = 0;
  rep(i,0,n) {
    vector<ll> ndp(4,-1e9);
    rep(msk,0,1<<3) {
      vector<ll> here(3,1e9);
      bool ok = true;
      rep(t,0,3) {
        if(msk>>t&1) {
          if(i-t < 0) ok = false;
          else here[t] = a[i-t];
        }
      }
      if(here[0]+here[1] < 0) ok = false;
      if(here[1]+here[2] < 0) ok = false;
      if(here[0]+here[1]+here[2] < 0) ok = false;
      if(msk == 0) assert(ok);
      if(ok) {
        ndp[msk%4] = max(ndp[msk%4], dp[msk/2]+(msk%2));
      }
    }
    dp = move(ndp);
    debug(i, a[i], dp);
  }
  cout << *max_element(all(dp)) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}