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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
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

struct FastNewton {
 private:
  long long P;
  long long range;
  vector<long long> inv;
  vector<long long> fact;
  vector<long long> fact_inv;
  vector<long long> v_p;
 
 public:
  FastNewton (long long _P, long long _range = 0) {
    init(_P, _range);
  }
  
  // Initialize structures to support computing n choose k mod _P, where n <= range
  void init(long long _P, long long _range = -1) {
    P = _P;
    if (_range == -1) {
      range = P;
    } else {
      range = _range;
    }
    inv.resize(range + 5);
    fact.resize(range + 5);
    fact_inv.resize(range + 5);
    v_p.resize(range + 5);
    fact[0] = 1;
    fact_inv[0] = 1;
    inv[0] = -1;
    inv[1] = 1;
    for (int i = 2; i < min(range, P); i++) {
      inv[i] = P - (P / i) * inv[P % i] % P;
    }
    for (int i = 1; i <= range; i++) {
      ll tmp = i;
      while (tmp % P == 0) {
        tmp /= P;
      }
      fact[i] = tmp * fact[i - 1] % P;
      fact_inv[i] = fact_inv[i - 1] * inv[tmp] % P;
    }
    for (int i = 1; i <= range; i++) {
      v_p[i] = i / P + v_p[i / P];
    }
  }
  
  long long get_inv(long long a) const {
    if (a % P == 0) {
      cout<<"ERROR: 0 has not got its inverse\n";
      return -1;
    }
    return inv[a % P];
  }
  
  // Computes n! mod P
  long long get_normal_fact(long long n) const {
    if (n >= P) {
      return 0;
    }
    return fact[n];
  }
  
  // Computes n!/p^(v_p(n!)) mod P
  long long get_better_fact(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return fact[n];
  }
  
  // Computes largest k such that p^k | n!
  long long get_v_p(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return v_p[n];
  }
  
  // Computes (n choose k) mod p
  long long choose(long long n, long long k) const {
    if (k < 0 || k > n) {
      return 0;
    }
    if (v_p[n] == v_p[k] + v_p[n - k]) {
      return fact[n] * fact_inv[k] % P * fact_inv[n - k] % P;
    } else {
      return 0;
    }
  }
  
};
  
const int P = 1e9 + 7;
  
const int N = 1e5 + 5;
int p25[N];
int p26[N];
int res[N];
map<int, vector<PII>> zap;
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = a * r % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) {
  return spow(a, P - 2);
}
int val[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  FastNewton newt(P, 2 * N);
  p25[0] = 1;
  p26[0] = 1;
  RE (i, N - 1) {
    p25[i] = p25[i - 1] * 25 % P;
    p26[i] = p26[i - 1] * 26 % P;
  }
  int m;
  cin>>m;
  string s;
  cin>>s;
  int q = 0;
  int c = 25 * Inv(26) % P;
  int len = SZ(s);
  RE (i, m) {
    int type;
    cin>>type;
    if (type == 1) {
      cin>>s;
      len = SZ(s);
    } else {
      int n;
      cin>>n;
      q++;
      zap[len].PB({n, q});
    }
  }
  
  for (auto p : zap) {
    int s1 = p.st;
    VPII v = p.nd;
    debug(s1);
    debug(v);
    
    int cp = 1;
    REP (i, N) {
      val[i] = 0;
      if (i) {
        val[i] += val[i - 1];
      }
      val[i] += newt.choose(i + s1 - 1, s1 - 1) * cp;
      val[i] %= P;
      cp = cp * c % P;
    }
    for (auto parka : v) {
      if (parka.st < s1) {
        res[parka.nd] = 0;
      } else {
        res[parka.nd] = val[parka.st - s1] * spow(26, parka.st - s1) % P;
      }
    }
  }
  
  
  
  
  RE (i, q) {
    cout<<res[i]<<"\n";
  }
    

  
  
  return 0;
}