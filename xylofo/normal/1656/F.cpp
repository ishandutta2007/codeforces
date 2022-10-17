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

void solve() {
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,0,n) cin>>a[i];
  sort(all(a));

  ll lo = a[0], hi = a.back(), sm = 0;
  rep(i,0,n) sm += a[i];

  ld ans = -1/0.0;
  ll cost = 0;
  ll coeff = 0;
  auto go = [&](ld t) {
    //cerr << "    " << cost << " " << coeff << " " << t << endl;
    //cerr << "    " << cost + coeff*t << endl;
    if(coeff == 0) ans = max<ld>(ans, cost);
    else ans = max(ans, cost+coeff*t);
  };

  // match with lo if (a[i]+t) > 0, else with hi!

  ld t = 1/0.0;
  cost = lo*(sm-lo);
  coeff = (n-1)*lo + (sm-lo);
  go(t);
  rep(i,1,n-1) {
    cost -= lo*a[i];
    coeff -= lo+a[i];
    cost += hi*a[i];
    coeff += hi+a[i];
    t = -a[i];
    go(t);
  }
  t = -1/0.0;
  go(t);

  assert(cost == hi*(sm-hi));
  assert(coeff == (n-1)*hi + (sm-hi));

  //cerr << "    !!  " << ans << endl;

  if(ans >= 5e18) cout << "INF" << "\n";
  else if(ans <= -5e18) cout << "-INF" << "\n";
  else cout << ll(ans) << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}