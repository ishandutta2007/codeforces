#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll n,m,k,p;
  cin>>n>>m>>k;
  ll i = 0;
  ll cnt = 0;
  cin>>p; ++i;
  while(true) {
    ll T = i;
    ll pos = p - T;
    ll page = pos/k;
    ++cnt;
    debug(page, p);
    while(i <= m) {
      if(i == m) goto done;
      cin>>p; ++i;
      pos = p - T;
      ll page2 = pos/k;
      if(page != page2) break;
    }
  }
done:
  cout << cnt << endl;
}