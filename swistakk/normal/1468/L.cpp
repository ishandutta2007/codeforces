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
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

using LL = long long;
using ULL = unsigned long long;


template<class T, class U, class Op>
T fastop(T a, U b, T r, const Op &op) {
  while (b > 0) {
    if (b % 2 == 1) { r = op(r, a); }
    a = op(a, a);
    b /= 2;
  }
  return r;
}

// MILLER-RABIN

template<class T>
bool witness(T wit, T n) {
  if (wit >= n) {return false; }
  
  auto addmod = [&](const T &a, const T &b) { return (a + b) % n; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto powmod = [&](const T &a, const T &b) { return fastop(a, b, T(1), mulmod); };
  int s; T t;
  for(s = 0, t = n - 1; t % 2 == 0; s++, t /= 2);
  wit = powmod(wit, t);
  if(wit == 1 || wit == n - 1)
    return false;
  
  for(int i = 1; i < s; ++i) {
    wit = mulmod(wit, wit);
    
    if(wit == 1)
      return true;
    if(wit == n - 1)
      return false;
  }
  
  return true;
}

// Is n prime?
template<class T>
bool miller(T n) {
  if(n == 2)
    return true;
  if(n % 2 == 0 || n < 2)
    return false;
  //vector<int> hehs{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
  vector<int> hehs{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  
  for (auto p : hehs) {
    if (witness(T(p), n)) { return false; }
  }
//   REP (i, 30) {
//     if (witness(T(2 + rand() % 1000), n)) { return false; }
//   }
//   if(witness(T(2), n) || witness(T(7), n) || witness(T(61), n))
//     return false;
  
  return true;
}

// BABY STEP - GIANT STEP

// Returns dicrete log_a val (mod mod) 
// -1 if no such exponent exists
LL disc_log(LL a, LL val, LL mod) {
  LL d = __gcd(a, mod);
  if(d != 1 && d != mod)
    return -1;
  
  LL sq = sqrt(mod) + 2;
  
  auto mulmod = [&](const LL &a, const LL &b) { return ((__int128_t) a * b) % mod; };
  auto powmod = [&](const LL a, const LL b) { return fastop(a, b, 1ll, mulmod); };
  
  map<LL, int> M;
  
  LL b = 1, c;
  for(int i = 0; i <= sq; ++i) {
    M[b] = i;
    b = mulmod(b, a);
  }
  
  c = powmod(a, mod - 1 - sq);
  b = val;
  for(int i = 0; i <= sq; ++i) {
    if(M.count(b))
      return i * sq + M[b];
    
    b = mulmod(b, c);
  }
  
  return -1;
}

// SOLOVAY-STRASSEN

// Computes jacobi symbol
// m must be odd
// if m is prime, then the result is 0 if m | n, 1 if n is a quadr. resid. mod m, -1 otherwise
template<class T>
int jacobi(T n, T m) {
  int r = 1;
  n %= m;
  while(n > 1) {
    while(n % 2 == 0) {
      n /= 2;
      if(m % 8 == 3 || m % 8 == 5)
        r *= -1;
    }
    
    swap(n, m);
    if(n % 4 == 3 && m % 4 == 3)
      r *= -1;
    
    n %= m;
  }
  
  return r;
}

template<class T>
bool solovay_witness(const T &a, const T &n) {
  T d = __gcd(a, n);
  
  if(d != 1 && d != n)
    return true;
  if(d == n)
    return false;
  
  auto addmod = [&](const T &a, const T &b) { return (a + b) % n; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto powmod = [&](const T &a, const T &b) { return fastop(a, b, T(1), mulmod); };
  
  return (T(jacobi(a, n)) - powmod(a, (n - 1)/2)) % n != 0;
}

// Is n prime?
template<class T>
bool solovay(T n) {
  if(n == 2)
    return true;
  if(n % 2 == 0 || n < 2)
    return false;
  
  if(solovay_witness(T(2), n))
    return false;
  
  for(int i = 0; i < 40; ++i)
    if(solovay_witness(T(2 + rand() % 1000), n))
      return false;
    
    return true;
}


// POLARD'S RHO

// a - parameter, shall not be equal to 0 or -2.
// returns a divisor, a proper one when succeeded, equal to n if failed
// in case of failure, change a
template<class T>
T rho(const T &n, const T a) {
  auto addmod = [&](const T &a, const T &b) { return (a + b) % n; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto f = [&](const T &x) { return addmod(mulmod(x, x), a); };
  
  T x = 2, y = 2;
  while(true) {
    x = f(x);
    y = f(f(y));
    T d = __gcd(n, abs(x - y));
    if(d != 1) 
      return d;
  }
}

template<class T>
T get_factor(T n) {
  if(n % 2 == 0)
    return 2;
  
  if(n % 3 == 0)
    return 3;
  
  if(n % 5 == 0)
    return 5;
  
  while(true) {
    T d = rho(n, T(rand()%100 + 2));
    if(d != n)
      return d;
  }
}

template<class T>
void __factorize(const T &n, vector<T> &x) {
  if(n == 1)
    return;
  else if(miller(n))
    x.push_back(n);
  else {
    T d = get_factor(n);
    __factorize(d, x);
    __factorize(n / d, x);
  }
}

template<class T>
vector<T> factorize(const T &n) {
  vector<T> x;
  __factorize(n, x);
  return x;
}

// TONELLI-SHANKS
// p must be prime, n must be a quadratic residue mod p
// returns a, such that a^2 mod p = n
template<class T>
T sqrtmod(T n, T p) {
  auto addmod = [&](const T &a, const T &b) { return (a + b) % p; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto powmod = [&](const T &a, const T &b) { return fastop(a, b, T(1), mulmod); };
  
  int s; T q;
  for(s = 0, q = p - 1; q % 2 == 0; s++, q /= 2);
  
  if(s == 1)
    return powmod(n, (p + 1) / 4);
  
  LL z;
  do {
    z = rand() % (p - 1) + 1;
  } while(powmod(z, (p - 1) / 2) == 1);
  
  T c = powmod(T(z), q);
  T r = powmod(n, (q + 1) / 2);
  T t = powmod(n, q);
  T m = s;
  
  while(true) {
    if(t == 1)
      return r;
    
    int i;
    for(i = 1; powmod(t, T(1ll << i)) != 1; ++i);
    
    T b = powmod(c, T(1ll << (m - i - 1)));
    r = mulmod(r, b);
    c = mulmod(b, b);
    t = mulmod(t, c);
    m = i;
  }
}

template<class T>
T primitive_root(T p) {
  vector<T> v = factorize(p - 1);
  v.erase(unique(v.begin(), v.end()), v.end());
  
  auto addmod = [&](const T &a, const T &b) { return (a + b) % p; };
  auto mulmod = [&](const T &a, const T &b) { return fastop(a, b, T(0), addmod); };
  auto powmod = [&](const T &a, const T &b) { return fastop(a, b, T(1), mulmod); };
  
  T x;
  
  do {
    x = rand() % (p - 1) + 1;
  } while(any_of(v.begin(), v.end(), [&](const T &y) { return powmod(x, (p - 1) / y) == 1; }));
  
  return x;
}



int IsPrime(int p) {
  for (int i = 2; i * i <= p; i++) {
    if (p % i == 0) { return 0; }
  }
  return 1;
}
int powuj(int a, int b) {
  int r = 1;
  RE (i, b) {
    r = r * a;
  }
  return r;
}
void Exit() {
  cout<<"0\n";
  exit(0);
}
const int N = 1e6;
int sieve[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  FOR (i, 2, N - 1) {
    if (sieve[i] == 0) {
      FOR (j, 2, (N - 1) / i) {
        sieve[i * j] = 1;
      }
    }
  }
  
  
  int n, k;
  cin>>n>>k;
  if (k == 1) {
    debug("k=1");
    Exit();
  }
  map<int, VI> pows_by_p;
  //vector<pair<int, set<int>>> oth;
  set<int> all_ps;
  VI gowno;
  RE (i, n) {
    int a;
    cin>>a;
    int ok = 0;
    FOR (p, 2, 1000) {
      if (sieve[p]) { continue; }
      int ziom = a;
      while (ziom % p == 0) {
        ziom /= p;
      }
      if (ziom == 1) {
        all_ps.insert(p);
        pows_by_p[p].PB(a);
        ok = 1;
        break;
      }
    }
    if (ok) { continue; }
    FOR (deg, 1, 5) {
      int sqr = pow(a, 1. / deg);
      FOR (cand, max(1ll, sqr - 2), sqr + 2) {
        if (miller(cand) && powuj(cand, deg) == a) {
          all_ps.insert(cand);
          pows_by_p[cand].PB(a);
          ok = 1;
        }
      }
    }
    if (!ok) {
      gowno.PB(a);
    }
    //vector<int> facts = factorize(a);
    //debug(facts);
//     sort(ALL(facts));
//     if (facts[0] == facts.back()) {
//       pows_by_p[facts[0]].PB(a);
//     } else {
//       oth.PB({a, set<int>(ALL(facts))});
//     }

  }
  
  debug("ok");
  set<int> good_p;
  VI bad_p;
  int sum_pows = 0;
  int any_non2 = 0;
  for (auto pr : pows_by_p) {
    if (SZ(pr.nd) >= 2) {
      sum_pows += SZ(pr.nd);
      if (SZ(pr.nd) >= 3) {
        any_non2 = 1;
      }
      good_p.insert(pr.st);
    } else {
      bad_p.PB(pr.st);
    }
  }
  for (auto p : bad_p) {
    pows_by_p.erase(p);
    all_ps.erase(p);
  }
  vector<pair<int, set<int>>> filtered;
  for (auto a : gowno) {
    int cp = a;
    set<int> facts;
    for (auto p : all_ps) {
      if (a % p == 0) {
        facts.insert(p);
      }
      while (a % p == 0) {
        a /= p;
      }
    }
    if (a == 1) {
      filtered.PB({cp, facts});
    }
  }
//   for (auto pr : oth) {
//     int fail = 0;
//     for (auto p : pr.nd) {
//       if (good_p.count(p) == 0) {
//         fail = 1;
//       }
//     }
//     if (!fail) {
//       filtered.PB(pr);
//     }
//   }
  if (SZ(filtered) + sum_pows < k) {
    debug("not sufficient numbers");
    Exit();
  }
  if (k >= sum_pows) {
    for (auto p : pows_by_p) {
      for (auto v : p.nd) {
        cout<<v<<" ";
      }
    }
    REP (i, k - sum_pows) {
      cout<<filtered[i].st<<" ";
    }
    cout<<endl;
    debug("easy");
  } else {
    if (any_non2 == 0 && k % 2 == 1) {
      int smallest_cnt = 1000;
      set<int> best_set;
      int best_num;
      for (auto p : filtered) {
        int here = SZ(p.nd);
        if (here < smallest_cnt) {
          smallest_cnt = here;
          best_set = p.nd;
          best_num = p.st;
        }
      }
      if (smallest_cnt * 2 <= k) {
        debug("best nonpow succ");
        int oth = (k - 1) / 2 - smallest_cnt;
        for (auto p : pows_by_p) {
          if (best_set.count(p.st) || oth > 0) {
            oth -= (best_set.count(p.st) == 0);
            for (auto num : p.nd) {
              cout<<num<<" ";
            }
          }
        }
        cout<<best_num<<"\n";
      } else {
        debug("best nonpow fail");
        Exit();
      }
    } else if (any_non2 == 0) {
      int zioms = k / 2;
      for (auto p : pows_by_p) {
        if (zioms) {
          zioms--;
          for (auto num : p.nd) {
            cout<<num<<" ";
          }
        }
      }
      cout<<"\n";
      debug("only 2pows");
    } else {
      vector<int> twos;
      vector<PII> bigs;
      for (auto pr : pows_by_p) {
        if (SZ(pr.nd) == 2) {
          twos.PB(pr.st);
        } else {
          bigs.PB({pr.st, SZ(pr.nd)});
        }
      }
      VPII res;
      while (k >= 4 && !twos.empty()) {
        res.PB({twos.back(), 2});
        twos.pop_back();
        k -= 2;
      }
      while (k) {
        int num = bigs.back().st;
        int freq = bigs.back().nd;
        if (k <= freq) {
          res.PB({num, k});
          k = 0;
          break;
        } else if (k >= freq + 2) {
          res.PB({num, freq});
          k -= freq;
        } else {
          res.PB({num, freq - 1});
          k = 2;
        }
        bigs.pop_back();
      }
      for (auto x : res) {
        int num = x.st;
        int freq = x.nd;
        auto v = pows_by_p[num];
        REP (i, freq) {
          cout<<v[i]<<" ";
        }
      }
      cout<<endl;
      assert(k == 0);
  
      debug("only pows hard");
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}