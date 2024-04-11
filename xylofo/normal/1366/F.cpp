#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif


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


const ll mod = 1'000'000'007;
using M = modnum<mod>;

bool smin(auto &a, auto&& b) { return (b < a) ? (a = b, 1) : 0; } 
bool smax(auto &a, auto&& b) { return (a < b) ? (a = b, 1) : 0; } 


struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, m, q;
  cin >> n >> m >> q;

  vector<vector<pair<int,ll>>> g(n);
  rep(i,0,m) {
    int x,y,w;
    cin>>x>>y>>w;
    --x,--y;
    g[x].emplace_back(y,w);
    g[y].emplace_back(x,w);
  }
  const int MAGIC = 3000;
  vector<vector<ll>> dist(n, vector<ll>(MAGIC,-1e18));
  dist[0][0] = 0;
  rep(l,1,MAGIC) {
    rep(x,0,n) for(auto [y,w] : g[x]) {
      smax(dist[y][l], dist[x][l-1]+w);
    }
  }

  LineContainer lc;
  rep(x,0,n) {
    ll mw = 0;
    for(auto [y,w] : g[x]) smax(mw,w);
    lc.add(mw, dist[x].back()+mw);
  }

  M ans = 0;
  rep(i,0,min<ll>(MAGIC,q+1)) {
    ll mx = 0;
    rep(x,0,n) smax(mx, dist[x][i]);
    ans += mx;
  }

  debug(ans);

  ll lo = 0, hi = q - MAGIC;

  //rep(i,lo,hi+1) { ans += lc.query(i); }

  vector<Line> ls(all(lc));
  rep(i,0,sz(ls)) {
    debug(ls[i].k, ls[i].m, ls[i].p);
    if(ls[i].p < lo) continue;
    ll up = min(ls[i].p, hi);
    // [lo, up] are by this line
    if(lo <= up) {
      M k = ls[i].k;
      M m = ls[i].m;
      // sum_{i = lo}^up k*x + m
      M t = (k*lo+m + k*up+m) * M(up-lo+1) / M(2);
      ans += t;
    }

    lo = min(hi,ls[i].p)+1;
  }

  cout << ans << endl;
}