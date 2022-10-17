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


const ll mod = 998'244'353;
using M = modnum<mod>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, x;
  cin >> n >> x;
  vi v(n);
  rep(i,0,n) cin>>v[i];

  vector<M> pw2(n+10,1);
  rep(i,1,sz(pw2)) pw2[i] = pw2[i-1]*2;


  function<M(vi,vi,int)> solve = [&](vi a, vi b, int bit) -> M {
    //auto solve = [&](vi a, vi b, int bit) -> M {
    //  M res = solve_(a,b,bit);
    //  debug(a, b, bit, res);
    //  return res;
    //};
    if(sz(a) == 0 || sz(b) == 0) return 0;
    if(bit < 0) return (pw2[sz(a)]-1) * (pw2[sz(b)]-1);

    vi a0, a1;
    vi b0, b1;
    for(int t : a) { if(t>>bit&1) a1.emplace_back(t^(1<<bit)); else a0.emplace_back(t); }
    for(int t : b) { if(t>>bit&1) b1.emplace_back(t^(1<<bit)); else b0.emplace_back(t); }

    if(x>>bit&1) {
      M res01 = solve(a0,b1,bit-1);
      M res10 = solve(a1,b0,bit-1);
      M res = 0;
      res += res01 * res10; // nothing empty
      res += res01; // a1,b0 empty
      res += res10; // a0,b1 empty
      res += (pw2[sz(a0)]-1) * (pw2[sz(b0)]-1) ; // a1,b1 empty
      res += (pw2[sz(a1)]-1) * (pw2[sz(b1)]-1) ; // a0,b0 empty
      res += res01 * (pw2[sz(b0)]-1) ; // a1 empty
      res += res10 * (pw2[sz(b1)]-1) ; // a0 empty
      res += res01 * (pw2[sz(a1)]-1) ; // b0 empty
      res += res10 * (pw2[sz(a0)]-1) ; // b1 empty
      return res;
    }
    else {
      return solve(a0,b0,bit-1) + solve(a1,b1,bit-1);
    }
  };

  if(x == 0) {
    map<int,int> q;
    rep(i,0,n) q[v[i]]++;
    M ans = 0;
    for(auto [_,c] : q) ans += pw2[c]-1;
    cout << ans << endl;
    return 0;
  }

  int hbit = 1, idx = 0;
  while(2*hbit <= x) hbit *= 2, ++idx;

  map<int,vi> groups;
  rep(i,0,n) groups[v[i]/(2*hbit)].emplace_back(v[i]);

  M ans = 0;

  for(auto [_,vv] : groups) {
    vi a, b;
    for(int t : vv) { if(t&hbit) a.emplace_back(t%hbit); else b.emplace_back(t%hbit); }
    M sep = (pw2[sz(a)]-1) + (pw2[sz(b)]-1);
    M together = solve(a,b,idx-1);
    debug();
    debug(vv);
    debug(a, b);
    debug(sep, together);
    ans += sep + together;
  }
  cout << ans << endl;
}