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
  rep(i,0,n) cin >> a[i];
  map<int,int> cnt;
  rep(i,0,n) ++cnt[a[i]];
  int mx = a[0], mxc = 0;
  rep(i,0,n) if(mxc < cnt[a[i]]) mx = a[i], mxc = cnt[a[i]];

  vi ord(n);
  iota(all(ord),0);
  sort(all(ord),[&](int x, int y) { return a[x] < a[y]; } );

  vi ans(n,-1);
  rep(i,0,n) { ans[ord[i]] = a[ord[(i+mxc)%n]]; }
  rep(i,0,n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}