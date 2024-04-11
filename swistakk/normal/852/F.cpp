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

const int N = 1e6 + 555;
int sito[N];
int spow(int a, int b, int P) {
  int r = 1;
  while (b) {
    if (b % 2 == 1) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
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
      fact_inv[i] = fact_inv[i - 1] * inv[tmp % P] % P;
//       if (i < 5) {
//         debug(i, fact[i], fact_inv[i], tmp, inv[tmp]);
//       }
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
      //debug("here", fact[n], fact_inv[k], fact_inv[n - k], n, k);
      return fact[n] * fact_inv[k] % P * fact_inv[n - k] % P;
    } else {
      return 0;
    }
  }
  
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, a, Q;
  cin>>n>>m>>a>>Q;
  int fi = Q;
  int cur_q = Q;
  FOR (i, 2, N - 1) {
    if (sito[i] == 0) {
      if (cur_q % i == 0) {
        fi /= i;
        fi *= (i - 1);
        while (cur_q % i == 0) {
          cur_q /= i;
        }
      }
      FOR (j, 2, (N - 1) / i) {
        sito[i * j] = 1;
      }
    }
  }
  if (cur_q > 1) {
    fi /= cur_q;
    fi *= (cur_q - 1);
  }
  int ord = -1;
  int cur_fi = fi;
  FOR (i, 2, N - 1) {
    while (cur_fi % i == 0) {
      cur_fi /= i;
    }
    if (fi % i == 0 && sito[i] == 0) {
      if (spow(a, i, Q) == 1) {
        ord = i;
        break;
      }
    }
  }
  if (ord == -1) {
    ord = cur_fi;
  }
  debug(ord);
  FastNewton newt(ord, N);
  int res = 1;
  REP (i, n + m + 2) {
    if (i > m || i >= n) { break; }
    res = res * spow(a, newt.choose(m, i), Q) % Q;
    debug(m, i, newt.choose(m, i));
  }
  REP (i, n) {
    cout<<res<<" ";
    if (n - 1 - i <= m) {
      debug(newt.choose(m, n - 1 - i));
      res = res * spow(spow(a, newt.choose(m, n - 1 - i), Q), fi - 1, Q) % Q;
    }
  }
  cout<<endl;
    
    

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}