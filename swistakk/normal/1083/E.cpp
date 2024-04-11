#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


const ll is_query = -(1LL << 62);
 
struct Line {
    ll m, b;
    mutable function<const Line *()> succ;
 
    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

// bool AreEqual(int a, int b, int c, int d) {
//   if (a % P * c % P != b % P * d % P) { return false; }
//   int ga = __gcd(a, b);
//   int gc = __gcd(c, d);
//   a /= ga;
//   b /= ga;
//   c /= gc;
//   d /= gc;
//   if (a < 0) { a *= -1; b *= -1; }
//   if (c < 0) { c *= -1; d *= -1; }
//   return a == c && b == d;
// }
  

bool Gr(int a, int b, int c, int d) {
  if (b < 0) { a *= -1; b *= -1; }
  if (d < 0) { c *= -1; d *= 1; }
  if ((a >= 0) != (c >= 0)) {
    return a >= 0;
  }
  if (a < 0) { return Gr(-c, d, -a, b); }
  if (c == 0) { return true; }
  if (a == 0) { return false; }
  int fla = a / b;
  int flc = c / d;
  if (fla != flc) {
    return fla >= flc;
  }
  a -= fla * b;
  c -= flc * d;
  if (c == 0) { return 1; }
  if (a == 0) { return 0; }
  return Gr(d, c, b, a);
}
bool Wrap(int a, int b, int c, int d) {

  // czy a * b >= c * d;
  //int sign1, sign2;
  if (a == 0 || b == 0) {
    a = 0;
  } else {
    if (b < 0) { a *= -1; b *= -1; }
  }
  if (c == 0 || d == 0) {
    c = 0;
  } else {
    if (d < 0) { c *= -1; d *= -1; }
  }
  if (c == 0) {
    return a >= 0;
  }
  if (a == 0) {
    return c <= 0;
  }
  if ((a > 0) != (c > 0)) {
    return a > 0;
  }
  return Gr(a, c, d, b);
}

struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
//         if (AreEqual((x->b - y->b), (y->b - z->b), (z->m - y->m), (y->m - x->m))) {
//           return true;
//         }

//         return Gr((x->b - y->b), (y->b - z->b), (z->m - y->m), (y->m - x->m));
        //if (z->m == y->m) {
        int a = (x->b - y->b);
        int b = (z->m - y->m);
        int c = (y->b - z->b);
        int d = (y->m - x->m);
//         int g1 = Wrap(a, b, c, d);
//         int g2 = (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
//         if (g1 != g2) {
//           debug(g1, g2, a, b, c, d);
//         }
        return Wrap(a, b, c, d);
        //return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
    }
 
    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
 
    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  vector<TIII> recs;
  RE (i, n) {
    int x, y, a;
    cin>>x>>y>>a;
    recs.PB({x, y, a});
  }
  sort(ALL(recs));
  
  HullDynamic hull;
  hull.insert_line(0, 0);
  int ans = 0;
  for (auto r : recs) {
    int best = hull.eval(r.nd) - r.rd + r.st * r.nd;
    maxi(ans, best);
    hull.insert_line(-r.st, best);
  }
  cout<<ans<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}