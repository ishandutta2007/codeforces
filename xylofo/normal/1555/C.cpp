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
  vi a(n), b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  ll sma = 0, smb = 0;
  rep(i,0,n) sma += a[i];
  ll ans = 1e18;
  rep(i,0,n) {
    sma -= a[i];
    ans = min(ans, max(sma, smb));
    smb += b[i];
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}