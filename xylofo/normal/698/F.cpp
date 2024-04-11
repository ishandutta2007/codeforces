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

const int LIM = 1e6+10;
bitset<LIM> isPrime;
vi eratosthenes() {
  const int S = (int)round(sqrt(LIM)), R = LIM / 2;
  vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
  vector<pii> cp;
  for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
    cp.push_back({i, i * i / 2});
    for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
  }
  for (int L = 1; L <= R; L += S) {
    array<bool, S> block{};
    for (auto &[p, idx] : cp)
      for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
    rep(i,0,min(S, R - L))
      if (!block[i]) pr.push_back((L + i) * 2 + 1);
  }
  for (int i : pr) isPrime[i] = 1;
  return pr;
}


void bad(string s = "0") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vi pi = eratosthenes();
  while(pi.back() > n) pi.pop_back();
  vi siz(sz(pi)+1,1);
  rep(i,0,sz(pi)) siz[i] = n/pi[i];
  debug(pi);
  debug(siz);

  vector<vi> cliques(n+1);
  vector<vi> cliques_siz(n+1);
  cliques[1].emplace_back(sz(pi));
  cliques_siz[1].emplace_back(1);
  rep(i,0,sz(pi)) for(int x = pi[i]; x <= n; x += pi[i]) {
    cliques[x].emplace_back(i);
    cliques_siz[x].emplace_back(siz[i]);
  }

  // elements in cliques_siz[x] are unique?

  debug(cliques_siz);

  vi undef_of_siz(n+1,0);
  rep(i,0,sz(siz)) ++undef_of_siz[siz[i]];

  const int undef = -1;
  vi perm(sz(pi)+1,undef); // was i, now is j
  vi iperm(sz(pi)+1,undef);

  auto set_perm = [&](int i, int j) {
    debug(i,"to",j);
    assert(siz[i] == siz[j]);
    if(perm[i] == undef) {
      perm[i] = j;
      --undef_of_siz[siz[i]];
    }
    if(iperm[j] == undef) iperm[j] = i;
    if(perm[i] != j || iperm[j] != i) bad();
  };

  vi a(n+1);
  rep(i,1,n+1) cin>>a[i];
  rep(i,1,n+1) if(a[i] != 0) {
    if(cliques_siz[a[i]] != cliques_siz[i]) bad();
    debug(cliques[i], cliques[a[i]]);
    rep(k,0,sz(cliques[i])) {
      set_perm(cliques[a[i]][k], cliques[i][k]);
    }
  }
  debug(perm);

  M perm_free = 1;

  vector<M> fac(n+10,1);
  rep(i,1,sz(fac)) fac[i] = fac[i-1]*i;

  rep(i,0,sz(undef_of_siz)) perm_free *= fac[undef_of_siz[i]];
  debug(undef_of_siz);

  debug(perm_free);

  map<vi,int> clique_free;
  rep(i,1,n+1) if(a[i] == 0) ++clique_free[cliques[i]];

  M c_free = 1;
  for(auto [_,s] : clique_free) c_free *= fac[s];

  debug(c_free);
  debug(cliques);

  M ans = perm_free*c_free;
  cout << ans << endl;
}