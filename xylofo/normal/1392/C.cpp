#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  int n;
  cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  reverse(all(a));
  ll ans = 0;
  rep(i,0,n-1) {
    if(a[i+1] > a[i]) ans += a[i+1]-a[i];
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