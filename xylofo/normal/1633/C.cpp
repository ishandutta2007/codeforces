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
  ll hc,dc;
  cin>>hc>>dc;
  ll hm,dm;
  cin>>hm>>dm;
  ll k,w,a;
  cin>>k>>w>>a;
  rep(i,0,k+1) {
    ll _dc = dc + i * w;
    ll _hc = hc + (k-i) * a;
    if((hm+_dc-1)/_dc <= (_hc+dm-1)/dm) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}