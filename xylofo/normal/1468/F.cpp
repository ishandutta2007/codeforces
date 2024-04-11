#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void simplify(pii& a) {
  int g = __gcd(abs(a.first), abs(a.second));
  a.first /= g;
  a.second /= g;
}

void solve() {
  int n; cin >> n;
  map<pii, ll> cnt;
  rep(i,0,n) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pii dir(x2-x1, y2-y1);
    simplify(dir);
    cnt[dir]++;
  }
  ll ans = 0;
  trav(p, cnt) {
    pii temp = p.first;
    temp.first = -temp.first;
    temp.second = -temp.second;
    ans += p.second * cnt[temp];
  }
  cout << ans / 2 << endl;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t; cin >> t;
  while(t--) solve();
}