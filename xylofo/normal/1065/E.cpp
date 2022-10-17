#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template<ll mod>
struct Mod {
  using M = Mod;
  using T = ll; // change to __int128 if needed
  static T inv(T a, T b) { return 1<a ? b - inv(b%a,a)*b/a : 1; }

  T x;
  Mod(T a = 0) : x(a % mod) { if(x < 0) x += mod; }

#define cmp(o) bool operator o(const M& r) const { return x o r.x; }
  cmp(<) cmp(>) cmp(<=) cmp(>=) cmp(==) cmp(!=);

#define op(o) M operator o(const M& r) const { return M(x o r.x); }
  op(+) op(-) op(*);
  M operator-() const { return M(mod-x); }
  M operator/(const M& r) const { return M(x * inv(r.x, mod)); }
  M operator^(T e) {
    M res = 1, acc = (*this);
    if(e < 0) e = -e, acc = M(1)/acc;
    for(; e; e /= 2) {
      if(e & 1) res *= acc;
      acc *= acc;
    }
    return res;
  }

#define opp(o) M& operator o##= (const M& r) { return *this = (*this) o r; }
  opp(+) opp(-) opp(*) opp(/) opp(^);
};
template<ll mod> ostream& operator<<(ostream& out, Mod<mod> m) {
  return out << m.x;
}

constexpr ll mod = 998'244'353;
using M = Mod<mod>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll n, m, A;
  cin >> n >> m >> A;
  vector<ll> b(m);
  rep(i,0,m) cin>>b[i];

  M pos = M(A)^n, neg = M(A)^n;
  rep(i,0,m) {
    M ppos = neg * (M(A)^b[i]) + pos;
    M nneg = pos * (M(A)^(-b[i])) + neg;
    pos = ppos;
    neg = nneg;
  }

  M ans = neg / (M(2)^(m));
  cout << ans << endl;
}