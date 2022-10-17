#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

using bs = bitset<1000*1000+10>;

void solve(int tc) {
  int k;
  cin>>k;
  vi a(k);
  rep(i,0,k) cin>>a[i];
  cin>>k;
  vi b(k);
  rep(i,0,k) cin>>b[i];

  auto knapsack = [&](auto v) -> pair<vi,vi> {
    int n = sz(v), w = 0;
    for(int x:v) w += x;
    if(w % 2 != 0) return {{},{}};
    vector<bs> ok(sz(v)+1);
    ok[0][0] = 1;
    rep(i,0,n) {
      ok[i+1] = (ok[i] | (ok[i]<<v[i]));
    }
    if(!ok[n][w/2]) return {{},{}};

    vi left, right;
    int t = w/2;
    for(int i = n; i--;) {
      if(ok[i][t]) right.emplace_back(v[i]);
      else {
        t -= v[i];
        assert(ok[i][t]);
        left.emplace_back(v[i]);
      }
    }
    assert(t == 0);

    if(sz(left) > sz(right)) swap(left, right);
    return {left, right};
  };

  auto [al, ar] = knapsack(a);
  auto [bl, br] = knapsack(b);
  if(sz(al) == 0 || sz(bl) == 0 || sz(a) != sz(b)) {
    cout << "No" << endl;
    return;
  }
  cout << "Yes" << endl;

  complex<int> pt(0,0), up(1,0), right(0,1);
  auto pr = [&]() { cout << real(pt) << " " << imag(pt) << "\n"; };

  for(int& x:al) x = -x;
  for(int& x:bl) x = -x;

  sort(all(al)); sort(all(ar));
  sort(all(bl)); sort(all(br));

  rep(i,0,sz(bl)) {
    pt += bl[i] * right; pr();
    pt += ar[i] * up; pr();
  }
  rep(i,0,k-sz(bl)-sz(al)) {
    pt += br[i+sz(al)] * right; pr();
    pt += ar[i+sz(bl)] * up; pr();
  }
  for(int i = sz(al); i--;) {
    pt += br[i] * right; pr();
    pt += al[i] * up; pr();
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}