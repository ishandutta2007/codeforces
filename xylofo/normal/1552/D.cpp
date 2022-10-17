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
  int n; cin >> n;
  vi a(n);
  map<int, int> cnt;
  rep(i,0,n) cin >> a[i];
  rep(k,0,1<<n) {
    int curr = 0;
    rep(i,0,n) if (k & (1<<i)) curr += a[i];
    cnt[curr]++;
  }
  trav(p, cnt) if (p.second > 1) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t; cin >> t;
  while(t--) solve();
}