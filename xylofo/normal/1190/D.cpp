#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;


struct Tree {
  typedef ll T;
  static constexpr T unit = 0;
  T f(T a, T b) { return a + b; }
  vector<T> s; int n;
  Tree(ll n = 0, T def = unit) : s(2*n, def), n(n) {}
  void update(ll pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(ll b, ll e) {
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  ll n;
  cin>>n;
  map<ll,ll> xs;
  map<ll,vi> pts;
  rep(i,0,n) {
    ll x,y;
    cin>>x>>y;
    pts[-y].eb(x);
    ++xs[x];
  }
  ll cnt = 1;
  trav(p, xs) p.second = ++cnt;

  ll ans = 0;

  Tree st(n+5);
  trav(_p, pts) {
    vi X = _p.second;
    trav(x,X) x = xs[x];
    sort(all(X));
    trav(x, X) {
      if(st.query(x, x+1) == 0)
        st.update(x, 1);
    }

    ll x0 = 0;
    trav(x, X) {
      ll left = st.query(x0, x);
      ll right = st.query(x+1, n+5);

      ans += (left + 1) * (right + 1);

      x0 = x+1;
    }
  }

  cout << ans << endl;
}