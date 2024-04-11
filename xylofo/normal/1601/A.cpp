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
  int g = 0;
  rep(bit,0,30) {
    int cnt = 0;
    rep(i,0,n) if(a[i]>>bit&1) ++cnt;
    g = gcd(g, cnt);
  }
  rep(i,1,n+1) if(g % i == 0) cout << i << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  rep(i,0,n) solve();
}