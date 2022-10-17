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
  cin >> n;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  vi b = a;
  reverse(all(b));
  if(a == b) {
    cout << "YES\n";
    return;
  }
  else {
    vi c;
    rep(i,0,n) if(a[i] != b[i]) {
      c.emplace_back(a[i]);
      c.emplace_back(b[i]);
    }
    rep(r,0,2) {
      int i = 0;
      int j = 0;
      while(i < n && j < n) {
        while(i < n && a[i] == c[r]) ++i;
        while(j < n && b[j] == c[r]) ++j;
        if(i < n && j < n && a[i] != b[j]) goto bad;
        ++i, ++j;
      }
      cout << "YES\n";
      return;
bad:;
    }
  }
  cout << "NO\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin>>t;
  rep(_,0,t) solve();
}