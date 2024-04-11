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

M win[20][20];
M iwin[20][20];
M iprob_cut2[4782969+100];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<M> a(n);
  rep(i,0,n) {
    cin >> a[i];
    //a[i] = rand()%10+1;
  }

  rep(i,0,n) rep(j,0,n) win[i][j] = a[i]/(a[i]+a[j]);
  rep(i,0,n) rep(j,0,n) iwin[i][j] = (a[i]+a[j])/a[i];

  auto base3 = [&](int msk) {
    int res = 0;
    rep(i,0,n) res = 3*res + (msk>>i&1);
    return res;
  };

  rep(msk,0,1<<n) {
    int msk3 = base3(msk);
    for(int sub = msk; sub; ) {
      sub = (sub-1)&msk;
      int here = msk3 + base3(sub);

      iprob_cut2[here] = 1;
      rep(i,0,n) if(sub>>i&1) rep(j,0,n) if(!(msk>>j&1)) {
        iprob_cut2[here] *= iwin[i][j];
      }
    }
  }

  M ans = 0;

  rep(x,0,n) {
    vector<M> smallest_cut(1<<n);
    rep(msk,1,1<<n) if(!(msk>>x&1)) {
      int msk3 = base3(msk);

      smallest_cut[msk] = 1;
      M prob_cut = 1;
      rep(i,0,n) if(msk>>i&1) rep(j,0,n) if(!(msk>>j&1)) {
        prob_cut *= win[i][j];
      }

      for(int sub = msk; sub; ) {
        sub = (sub-1)&msk;
        if(sub>>x&1) continue;
        int here = msk3 + base3(sub);
        smallest_cut[msk] -= smallest_cut[sub] * iprob_cut2[here];
      }
      smallest_cut[msk] *= prob_cut;
    }

    M prob_good = 1;
    rep(msk,1,1<<n) prob_good -= smallest_cut[msk];
    debug(x, prob_good);
    ans += prob_good;
  }

  cout << ans << endl;
}