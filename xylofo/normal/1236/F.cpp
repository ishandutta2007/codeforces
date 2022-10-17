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
//using M = ld;


vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
  int me = num[at] = ++Time, e, y, top = me;
  for (auto pa : ed[at]) if (pa.second != par) {
    tie(y, e) = pa;
    if (num[y]) {
      top = min(top, num[y]);
      if (num[y] < me)
        st.push_back(e);
    } else {
      int si = sz(st);
      int up = dfs(y, e, f);
      top = min(top, up);
      if (up == me) {
        st.push_back(e);
        f(vi(st.begin() + si, st.end()));
        st.resize(si);
      }
      else if (up < me) st.push_back(e);
      else { } // bridge
    }
  }
  return top;
}

template<class F>
void bicomps(F f) {
  num.assign(sz(ed), 0);
  rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;

  ed.resize(n);
  vector<pii> edges(m);
  vector<vi> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    ed[x].emplace_back(y,i);
    ed[y].emplace_back(x,i);
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    edges[i] = pii(x,y);
  }

  vector<vi> in_cyc(n);
  vector<vi> cyc;

  auto bcc = [&](vi c) {
    vi verts;
    int us = sz(cyc);
    for(int e : c) {
      auto [x,y] = edges[e];
      if(!sz(in_cyc[x]) || in_cyc[x].back() != us) {
        in_cyc[x].emplace_back(us);
        verts.emplace_back(x);
      }
      if(!sz(in_cyc[y]) || in_cyc[y].back() != us) {
        in_cyc[y].emplace_back(us);
        verts.emplace_back(y);
      }
    }
    cyc.emplace_back(verts);
  };
  bicomps(bcc);
  debug(in_cyc);
  debug(cyc);

  M Var_V = n * (1/M(2)) * (1/M(2));

  M Var_E = [&](){
    M res = m * (1/M(4) - 1/M(16));
    rep(i,0,n) res += M(sz(g[i])) * M(sz(g[i])-1) * (1/M(8) - (1/M(16)));
    return res;
  }();

  M Var_F = [&](){
    M res = 0;
    rep(i,0,sz(cyc)) {
      M p = 1/pw(M(2),sz(cyc[i]));
      res += p*(1-p);
    }
    rep(i,0,n) {
      M term = 0;
      M surplus = 0;
      for(int c : in_cyc[i]) {
        M q = pw(M(2), sz(cyc[c]));
        term += 1/q;
        surplus += 1/(q*q);
      }
      res += term*term - surplus;
    }
    return res;
  }();

  M Cov_VE = m/M(4);

  M Cov_VF = [&](){
    M res = 0;
    rep(c,0,sz(cyc)) res += sz(cyc[c]) / pw(M(2), sz(cyc[c])+1);
    return res;
  }();

  M Cov_EF = [&](){
    M res = 0;
    rep(c,0,sz(cyc)) res += sz(cyc[c]) * 3 / (pw(M(2), sz(cyc[c])+2));
    rep(c,0,sz(cyc)) {
      int extra = 0;
      for(int x : cyc[c]) extra += sz(g[x])-2;
      res += extra / pw(M(2), sz(cyc[c])+2);
    }
    return res;
  }();


  /*
  auto est_var = [&](auto &f) {
    ld xy=0, x=0, y=0;
    const int Q = 1000;
    rep(i,0,Q) {
      auto [X,Y] = f();
      x += X;
      y += Y;
      xy += X*Y;
    }
    return xy/Q-x/Q*y/Q;
  };
  auto vef = [&](){
    vi alive(n);
    rep(i,0,n) alive[i] = 1-(rand()%2);
    int v = count(all(alive),1);
    int e = 0;
    int f = 0;
    rep(i,0,n) for(int j : g[i]) if(i < j && alive[i] && alive[j]) ++e;
    rep(c,0,sz(cyc)) {
      bool ok = true;
      for(int x : cyc[c]) if(!alive[x]) ok = false;
      if(ok) ++f;
    }
    return make_tuple(v,e,f);
  };
  auto _vv = [&](){ auto t = vef(); return make_pair(get<0>(t), get<0>(t)); };
  auto _ee = [&](){ auto t = vef(); return make_pair(get<1>(t), get<1>(t)); };
  auto _ff = [&](){ auto t = vef(); return make_pair(get<2>(t), get<2>(t)); };
  auto _ve = [&](){ auto t = vef(); return make_pair(get<0>(t), get<1>(t)); };
  auto _vf = [&](){ auto t = vef(); return make_pair(get<0>(t), get<2>(t)); };
  auto _ef = [&](){ auto t = vef(); return make_pair(get<1>(t), get<2>(t)); };
  auto _ans = [&](){
    auto t = vef();
    int r = get<0>(t)-get<1>(t)+get<2>(t);
    return make_pair(r,r);
  };
  debug(est_var(_vv));
  debug(est_var(_ee));
  debug(est_var(_ff));
  debug(est_var(_ve));
  debug(est_var(_vf));
  debug(est_var(_ef));

  debug(Var_V);
  debug(Var_E);
  debug(Var_F);
  debug(Cov_VE);
  debug(Cov_VF);
  debug(Cov_EF);

  debug();
  debug(est_var(_ans));
  */

  // ans = Var(V-E+F)
  M ans = Var_V + Var_E + Var_F + 2*Cov_VF - 2*Cov_VE - 2*Cov_EF;
  cout << ans << endl;
}