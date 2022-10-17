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
  int n,k;
  cin>>n>>k;
  vi a(n);
  rep(i,0,n) cin>>a[i];
  unordered_set<int> s(all(a));
  rep(i,0,n) if(s.count(a[i]+k)) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}