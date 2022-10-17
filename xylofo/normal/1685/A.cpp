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
  if(n % 2 == 1) {
    cout << "NO" << "\n";
    return;
  }
  sort(all(a));
  vi b(n);
  rep(i,0,n/2) b[2*i] = a[i];
  rep(i,0,n/2) b[2*i+1] = a[i+n/2];
  rep(i,0,n/2) if(b[2*i+1] == b[2*i] || b[2*i+1] == b[(2*i+2)%n]) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  rep(i,0,n) cout << b[i] << " ";
  cout << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}