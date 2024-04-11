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
  using ll = int;

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


const ll mod = 31607;
using M = modnum<mod>;
//using M = ld;

//M a[22][22];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;

  vector<vector<M>> a(n,vector<M>(n));
  rep(i,0,n) rep(j,0,n) {
    M x;
    cin>>x;
    //x = 5000;
    a[i][j] = x/M(int(1e4));
  }


  auto solve = [&](const auto& a) -> M {
    M prob_row = 0;

    vector<M> rows(n,1);
    rep(i,0,n) rep(j,0,n) rows[i] *= a[i][j];

    vector<M> cols(n,1);
    rep(i,0,n) rep(j,0,n) cols[j] *= a[i][j];

    rep(msk,1,1<<n) {
      M p = 1;
      rep(i,0,n) if(msk>>i&1) p *= rows[i];

      if(__builtin_popcount(msk)%2 == 1) prob_row += p;
      else prob_row -= p;
    }
    //debug(prob_row); //debug(M(7)/M(16));

    //vector<vector<M>> rowsC(n, vector<M>(1<<n));
    //rep(i,0,n) {
    //  rep(j,0,n) rowsC[i][1<<j] = a[i][j];
    //  rep(bit,0,n) rep(msk,0,1<<n) if(msk>>bit&1)
    //  }
    //}

    M prob_col_and_no_row = 0;
    rep(msk,1,1<<n) {
      M p = 1;
      rep(j,0,n) if(msk>>j&1) p *= cols[j];

      vector<M> qq(n,1);
      rep(j,0,n) if(!(msk>>j&1)) rep(i,0,n) qq[i] *= a[i][j];
      rep(i,0,n) p *= (1-qq[i]);


      if(__builtin_popcount(msk)%2 == 1) prob_col_and_no_row += p;
      else prob_col_and_no_row -= p;
    }
    //debug(prob_col_and_no_row); //debug(M(2)/M(16));

    return prob_row + prob_col_and_no_row;
  };


  M prob_rc = solve(a);

  M prob_d0 = 1;
  auto a0 = a;
  rep(i,0,n) rep(j,0,n) if(i == j) {
    prob_d0 *= a0[i][j];
    a0[i][j] = 1;
  }
  M prob_d0_and_rc = solve(a0) * prob_d0;

  M prob_d1 = 1;
  auto a1 = a;
  rep(i,0,n) rep(j,0,n) if(i == n-j-1) {
    prob_d1 *= a1[i][j];
    a1[i][j] = 1;
  }
  M prob_d1_and_rc = solve(a1) * prob_d1;

  M prob_d0_and_d1 = 1;
  auto a01 = a;
  rep(i,0,n) rep(j,0,n) if(i == j || i == n-j-1) {
    prob_d0_and_d1 *= a01[i][j];
    a01[i][j] = 1;
  }
  M prob_d0_and_d1_and_rc = solve(a01) * prob_d0_and_d1;

  M ans = 0;
  ans += prob_rc + prob_d0 + prob_d1;
  ans -= prob_d0_and_rc + prob_d1_and_rc + prob_d0_and_d1;
  ans += prob_d0_and_d1_and_rc;
  cout << ans << endl;

  debug(prob_rc , prob_d0 , prob_d1);
  debug(prob_d0_and_rc , prob_d1_and_rc , prob_d0_and_d1);
  debug(prob_d0_and_d1_and_rc);

}