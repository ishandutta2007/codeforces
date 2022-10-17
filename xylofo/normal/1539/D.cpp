#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi a(n), b(n);
  rep(i,0,n) cin>>a[i]>>b[i];
  set<pii> by_b;
  rep(i,0,n) by_b.emplace(b[i], i);

  ll ans = 0;
  ll bought = 0;
  while(sz(by_b)) {
    int cheap = begin(by_b)->second;
    if(bought >= b[cheap]) {
      by_b.erase(pii(b[cheap],cheap));
      bought += a[cheap];
      ans += a[cheap];
      a[cheap] = 0;
      continue;
    }
    int expensive = rbegin(by_b)->second;
    ll buy = min(a[expensive], b[cheap] - bought);
    ans += 2*buy;
    a[expensive] -= buy;
    bought += buy;
    if(a[expensive] == 0) by_b.erase(pii(b[expensive],expensive));
  }

  cout << ans << endl;
}