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
  int t, n, d;
  cin >> t;
  rep(_,0,t) {
    cin >> n >> d;
    vi a(n);
    trav(x, a) cin >> x;
    ll ans = 0;
    rep(i,0,n) {
      int k = min(a[i], i == 0 ? (int (1e9)) : d/i);
      ans += k;
      d -= k*i;
    }
    cout << ans << endl;
  }
}