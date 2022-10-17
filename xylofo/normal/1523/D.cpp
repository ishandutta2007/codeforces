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


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, p;
  cin >> n >> m >> p;
  vector<ll> v(n);
  rep(i,0,n) {
    string s;
    cin>>s;
    rep(j,0,m) if(s[j]=='1') v[i] ^= (1LL<<j);
  }

  ll ans = 0;

  auto solve = [&](ll y) {
    vi bits;
    rep(j,0,m) if(y>>j&1) bits.emplace_back(j);
    assert(sz(bits) <= 15);
    vi cnt(1<<sz(bits));
    for(ll x : v) {
      int r = 0;
      rep(j,0,sz(bits)) if(x>>bits[j]&1) r ^= (1<<j);
      ++cnt[r];
    }
    const int T = (1<<sz(bits))-1;
    rep(b,0,sz(bits)) rep(msk,0,(1<<sz(bits)))
      if(msk>>b&1) cnt[T^msk] += cnt[T^msk^(1<<b)];

    rep(msk,0,(1<<sz(bits))) if(2*cnt[msk]>=n && __builtin_popcount(msk) > __builtin_popcount(ans)) {
      ans = 0;
      rep(j,0,sz(bits)) if(msk>>j&1) ans ^= (1LL<<bits[j]);
    }
  };

  shuffle(all(v), rng);
  rep(i,0,min(30,n)) solve(v[i]);
  rep(j,0,m) cout << "01"[ans>>j&1];
  cout << endl;
}