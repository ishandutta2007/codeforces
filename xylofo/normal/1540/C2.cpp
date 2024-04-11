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


template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

  private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

  public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v -= MOD-o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pw(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}


const ll mod = 1'000'000'007;
using M = modnum<mod>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi c(n), b(n);
  rep(i,0,n) cin>>c[i];
  rep(i,0,n-1) cin>>b[i];

  M LARGE = 1, SMALL = 0;
  rep(i,0,n) LARGE *= M(c[i]+1);

  int min_X = -1e9, max_X = 1e9;

  map<ll,M> store;
  auto solve = [&](ll x) {
    if(x < min_X) return LARGE;
    if(x > max_X) return SMALL;
    if(store.count(x)) return store[x];

    int HI = 110*n;
    vector<vector<M>> dp(n+1, vector<M>(HI));
    dp[0][0] = 1;

    // k * lo + (k-1) * b_0 + (k-2) * b_1 + ... + b_{k-2}
    //     q = <^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 
    ll q = 0, delta = 0;
    rep(k,1,n+1) {
      vector<M> pref(HI+1,0);
      rep(sm,0,HI) pref[sm+1] = pref[sm] + dp[k-1][sm];
      rep(sm,0,HI) {
        int lo = max(0,sm-c[k-1]);
        int hi = sm+1;
        // dp[k][sm] = sum_{lo <= i < hi} dp[k-1][i]
        dp[k][sm] = pref[hi] - pref[lo];
      }
      //rep(ai,0,c[k-1]+1) rep(sm,0,HI-ai) dp[k][sm+ai] += dp[k-1][sm];

      q += delta;
      delta += b[k-1];

      rep(sm,0,HI) if(sm < k * x + q) dp[k][sm] = 0;
    }

    M ans = 0;
    rep(sm,0,HI) ans += dp[n][sm];
    return store[x] = ans;
  };

  {
    int l=-1e6,r=1e6;
    while(l+1 != r) {
      int m = (l+r)/2;
      if(solve(m) != SMALL) l = m;
      else r=m;
    }
    max_X = r+10;
  }
  {
    int l=-1e6,r=1e6;
    while(l+1 != r) {
      int m = (l+r)/2;
      if(solve(m) == LARGE) l = m;
      else r=m;
    }
    min_X = r-10;
  }
  debug(min_X, max_X);
  debug(LARGE, SMALL);

  int q;
  cin>>q;
  rep(i,0,q) {
    int x;
    cin>>x;
    M ans = solve(x);
    cout << ans << "\n";
  }
}