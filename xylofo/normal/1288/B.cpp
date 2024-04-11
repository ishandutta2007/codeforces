#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int t;
  ll a, b;
  cin >> t;
  rep(_,0,t) {
    cin >> a >> b;
    ll pw10 = 1;
    ll ans = 0;
    rep(i,0,10) {
      ll bb = pw10-1;
      if(1 <= bb && bb <= b) ans += a;
      pw10 *= 10;
    }
    cout << ans << endl;
  }
}