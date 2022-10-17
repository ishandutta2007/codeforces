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
  vi a(n);
  rep(i,0,n) cin>>a[i];
  if(n <= 2) {
    cout << 0 << endl;
    return;
  }
  int ans = 1e9;
  rep(i,0,n) rep(j,i+1,n) {
    int cnt = n;
    rep(k,0,n) {
      if((a[k]-a[i]) * (j-i) == (a[j]-a[i]) * (k-i)) --cnt;
    }
    ans = min(ans, cnt);
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