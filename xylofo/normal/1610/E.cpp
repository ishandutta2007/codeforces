

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


void solve(){
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  sort(all(a));
  auto nxt_ge = [&](int x) { return int(lower_bound(all(a), x) - begin(a)); };

  int ans = 1;
  rep(st,0,n) {
    int cur = 0;
    int x = a[st];
    cur += nxt_ge(x+1) - nxt_ge(x);
    int r = nxt_ge(x+1);
    while(r < n) {
      int y = a[r];
      ++cur;
      r = nxt_ge(2*y-x);
    }
    ans = max(ans, cur);
  }
  cout << n - ans << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin>>t;
  rep(_,0,t) solve();
}