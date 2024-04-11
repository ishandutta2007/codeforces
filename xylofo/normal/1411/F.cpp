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

const int KILL = 7;
map<vi,int> dist;
void init() {
  queue<vi> q;
  auto push = [&](const vi& c, int d) {
    if(dist.count(c)) return;
    dist[c] = d;
    q.emplace(c);
  };
  rep(t,0,15) {
    vi zero(KILL);
    zero[3] = t;
    push(zero,0);

    zero[2] = 1;
    push(zero,0);

    zero[2] = 2;
    push(zero,0);

    zero[2] = 0;
    zero[4] = 1;
    push(zero,0);
  }

  while(sz(q)) {
    vi c = q.front();
    q.pop();
    int d = dist[c];
    rep(i,0,KILL) rep(j,0,KILL) if(c[i] && c[j] && i+j < KILL && (i!=j || c[i]>=2)) {
      vi c2 = c;
      --c2[i]; --c2[j]; ++c2[i+j];
      push(c2,d+1);
    }
    rep(i,0,KILL) if(c[i]) rep(a,1,i) {
      int b = i-a;
      assert(a && b);
      vi c2 = c;
      --c2[i]; ++c2[a]; ++c2[b];
      push(c2,d+1);
    }
  }
}

void solve(int tc) {
  int n;
  cin >> n;
  vi p(n);
  rep(i,0,n) {
    cin>>p[i];
    --p[i];
  }

  M ans = 0;
  if(n%3 == 0) ans = pw(M(3),n/3);
  if(n%3 == 1) ans = pw(M(3),n/3-1)*M(4);
  if(n%3 == 2) ans = pw(M(3),n/3)*M(2);

  vi vis(n);
  vi cyc(n+1);
  rep(i,0,n) if(!vis[i]) {
    int x = i, c = 0;
    while(!vis[x]) {
      vis[x] = 1;
      ++c;
      x = p[x];
    }
    ++cyc[c];
  }


  ll cost = 0;
  for(int c = n; c > 3; --c) {
    int k = max(0,cyc[c]-1);
    if(c >= KILL) k = cyc[c];
    cost += k;
    cyc[c-3] += k;
    cyc[3] += k;
    cyc[c] -= k;
  }
  cyc.resize(KILL);
  debug(cyc);

  while(cyc[1] > 4 && cyc[2] > 2) {
    cost += 1;
    --cyc[1];
    --cyc[2];
    ++cyc[3];
  }
  cyc[3] = min(cyc[3],1);

  int tot = 0;
  rep(i,0,sz(cyc)) tot += i*cyc[i];
  assert(tot%3 == n%3);

  assert(dist.count(cyc));
  cost += dist[cyc];

  cout << ans << " " << cost << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  init();
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}