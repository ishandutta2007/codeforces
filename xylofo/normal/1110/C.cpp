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

vi large_div(30,1);

void solve(int tc) {
  ll a;
  cin>>a;
  ll c = a;
  rep(i,0,35) c = c|(c>>1);
  if(a != c) {
    cout << c << endl;
  }
  else {
    cout << large_div[__builtin_ctz(c+1)] << endl;
  }
}

int main() {
  rep(i,0,sz(large_div)) {
    ll q = (1LL<<i)-1;
    for(ll x = 2; x*x <= q; x++) if(q%x == 0) {
      large_div[i] = q/x;
      break;
    }
  }

  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}