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
  if(count(all(a),1) == 0) {
    cout << "YES\n";
    return;
  }
  sort(all(a));
  rep(i,0,n-1) if(a[i]+1 == a[i+1]) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}