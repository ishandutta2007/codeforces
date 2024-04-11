#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int t, n;
  ll x;
  cin >> t;
  rep(_,0,t) {
    cin >> n >> x;
    vi a(n);
    trav(y, a) cin >> y;
    ll d = *max_element(all(a));
    ll use = (x+d-1)/d;
    use = max<ll>(use, 2);
    if(count(all(a), x)) use = 1;
    cout << use << endl;
  }
}