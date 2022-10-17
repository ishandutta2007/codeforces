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

void solve() {
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  auto [l,r] = minmax_element(all(a));
  cout << 1+l-begin(a) << " " << 1+r-begin(a) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}