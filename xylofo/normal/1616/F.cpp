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


using M = modnum<3>;


typedef vector<M> vd;

int solveLinear(vector<vd>& A, vd& b, vd& x) {
  int n = sz(A), m = sz(x), rank = 0, br, bc;
  if (n) assert(sz(A[0]) == m);
  vi col(m); iota(all(col), 0);

  rep(i,0,n) {
    M v, bv = 0;
    rep(r,i,n) rep(c,i,m)
      if ((v = A[r][c]) != 0) {
        br = r, bc = c, bv = v;
        break;
      }
    if (bv == 0) {
      rep(j,i,n) if (b[j] != 0) return -1;
      break;
    }
    swap(A[i], A[br]);
    swap(b[i], b[br]);
    swap(col[i], col[bc]);
    rep(j,0,n) swap(A[j][i], A[j][bc]);
    bv = 1/A[i][i];
    rep(j,i+1,n) {
      M fac = A[j][i] * bv;
      if(fac == 0) continue;
      b[j] -= fac * b[i];
      rep(k,i+1,m) A[j][k] -= fac*A[i][k];
    }
    rank++;
  }

  x.assign(m, 0);
  for (int i = rank; i--;) {
    b[i] /= A[i][i];
    x[col[i]] = b[i];
    rep(j,0,i) b[j] -= A[j][i] * b[i];
  }
  return rank; // (multiple solutions if rank < m)
}

void solve(int tc) {
  int n, m;
  cin >> n >> m;
  vector<vi> g(n, vi(n));
  vector<vi> idx(n, vi(n,-1));

  rep(i,0,m) {
    int x,y,c;
    cin>>x>>y>>c;
    --x,--y;

    //c = -1; x = i%n; y = i/n;

    g[x][y] = g[y][x] = c;
    idx[x][y] = idx[y][x] = i;
  }

  vector<vd> A;
  vd B;
  rep(i,0,n) rep(j,i+1,n) rep(k,j+1,n) {
    int a = idx[i][j];
    int b = idx[j][k];
    int c = idx[k][i];
    if(a == -1 || b == -1 || c == -1) continue;

    vd row(m);
    row[a] = row[b] = row[c] = 1;
    A.emplace_back(row);
    B.emplace_back(0);
  }

  rep(i,0,n) rep(j,i+1,n) {
    int a = idx[i][j];
    if(a == -1 || g[i][j] == -1) continue;
    assert(g[i][j] >= 1);
    vd row(m);
    row[a] = 1;
    A.emplace_back(row);
    B.emplace_back(g[i][j]%3);
  }

  vd x(m);
  int rk = solveLinear(A, B, x);
  if(rk == -1) cout << -1 << endl;
  else {
    rep(i,0,m) cout << (x[i] == 0 ? 3 : int(x[i])) << " ";
    cout << endl;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  rep(t,1,T+1) solve(t);
}