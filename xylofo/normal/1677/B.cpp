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
  int n, m;
  cin >> n >> m;
  string s;
  cin>>s;

  vi cols(m,false);
  int good_cols = 0;

  vi ans(n*m);

  rep(i,0,n*m) {
    if(!cols[i%m] && s[i] == '1') cols[i%m] = true, ++good_cols;
    ans[i] += good_cols;
  }

  vi good_rows(m,0);
  int last = -1e9;

  rep(i,0,n*m) {
    if(s[i] == '1') last = i;
    if(i-last < m) ++good_rows[i%m];
    ans[i] += good_rows[i%m];
  }

  rep(i,0,n*m) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}