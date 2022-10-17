#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  vi a(n,0);
  bool bad = false;
  rep(i,0,n) {
    int x;
    cin>>x;
    x += i;
    x = x%n;
    if(x < 0) x+=n;
    if(a[x]++) bad = true;
  }
  if(bad) cout << "NO" << endl;
  else cout << "YES" << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin>>t;
  rep(i,0,t) solve();
}