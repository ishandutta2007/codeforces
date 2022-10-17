#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

using ld = long double;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  double dist() const { return sqrt((double)dist2()); }
  // angle to x-axis in interval [-pi, pi]
  ld angle() const { return atan2(y, x); }
  P unit() const { return *this/dist(); } // makes dist()=1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }
  // returns point rotated 'a' radians ccw around the origin
  P rotate(double a) const {
    return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
  friend ostream& operator<<(ostream& os, P p) {
    return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<ld>;


vector<P> tangents(P c1, double r1, P c2, double r2 = 0) {
  P d = c2 - c1;
  double dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
  if (d2 == 0 || h2 < 0)  return {};
  vector<P> out;
  for (double sign : {-1, 1}) {
    P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    out.push_back(c1 + v * r1);
  }
  //if (h2 == 0) out.pop_back();
  return out;
}

template<class I>
I bs(I a, I b, auto&& f) {
  assert(a < b);
  rep(i,0,50) {
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}


struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) { // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};


template<class P>
double lineDist(const P& a, const P& b, const P& p) {
  return (double)(b-a).cross(p-a)/(b-a).dist();
}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a,b) uniform_int_distribution<>(a,b-1)(rng) // [a,b)

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, k;
  cin >> n >> k;
  vector<P> pts(n);
  rep(i,0,n) {
    pts[i].x = uid(1000,2000);
    pts[i].y = uid(1000,2000);
    cin>>pts[i].x>>pts[i].y;
  }

  auto isec = [&](const vector<pii>& ivals, int t) {
    vector<pii> event;
    rep(i,0,sz(ivals)) {
      event.emplace_back(ivals[i].first, i);
      event.emplace_back(ivals[i].second, ~i);
    }
    sort(all(event));
    FT opened(t);
    ll ans = 0;
    for(auto [q,i]: event) {
      if(i < 0) { // end ival
        i = ~i;
        opened.update(ivals[i].first,-1);
        ll q = opened.query(ivals[i].second) - opened.query(ivals[i].first);
        ans += q;
        // debug("end", ivals[i], q);
      }
      else { // start ival
        // debug("start", ivals[i]);
        opened.update(ivals[i].first,+1);
      }
    }
    return ans;
  };

  auto calc = [&](ld r) {
    ld r2 = r*r;
    ll cnt = 0;

    vector<P> v;
    for(auto p:pts) if(p.dist2() > r2) v.emplace_back(p);
    ll bad = n-sz(v);
    cnt += (bad * (bad-1)) / 2;
    cnt += bad * sz(v);
    //debug(bad, cnt); debug(v);

    vector<pair<ld, int>> t;
    rep(i,0,sz(v)) {
      auto q = tangents(P{},r, v[i]);
      assert(sz(q));
      t.emplace_back(q[0].angle(), i);
      t.emplace_back(q[1].angle(), i);
    }
    sort(all(t));
    //debug(t);

    vi use(sz(v),-1);
    vector<pii> ivals;
    rep(i,0,sz(t)) {
      int& kk = use[t[i].second];
      if(kk != -1)  ivals.emplace_back(kk,i);
      kk = i;
    }
    //debug(ivals);
    ll q = sz(v)*1LL*(sz(v)-1)/2LL - isec(ivals, sz(t));
    //debug(q);
    cnt += q;
    return cnt >= k;
  };

  //debug(calc(1.5)); return 0;

  ld ans = bs<ld>(0,1e5,calc);
  cout << setprecision(14) << fixed;
  cout << ans << endl;

  auto brute = [&]() {
    vector<ld> v;
    rep(i,0,n) rep(j,i+1,n)
      v.emplace_back(abs(lineDist(pts[i],pts[j],P{})));
    sort(all(v));
    return v[k-1];
  };

  // ld ans2 = brute();
  // debug(ans2);
  // if(abs(ans - ans2) >= 1e-6) {
  //   debug(pts);
  //   assert(false);
  // }
}