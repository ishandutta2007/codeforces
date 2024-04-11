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


#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

void solve(int tc) {
  int n;
  cin >> n;
  vi p(n);
  rep(i,0,n) cin>>p[i];

  vi pref(n+10);
  vector<vi> suf(n+10, vi(n+10,0));

  for(int c = n-1; c >= 0; --c) {
    suf[c] = suf[c+1];
    rep(i,p[c],sz(suf[c])) ++suf[c][i];
  }

  ll ans = 0;
  rep(b,0,n) {
    for(int c = n-1; c > b; --c) {
      ans += pref[p[c]] * suf[c+1][p[b]];
    }
    rep(i,p[b],sz(pref)) ++pref[i];
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