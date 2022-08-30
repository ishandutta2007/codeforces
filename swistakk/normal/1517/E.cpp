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

const int P = 998244353;
struct Sol {
  void Test() {
    int n;
    cin>>n;
    
    VI a(n + 2);
    RE (i, n) {
      cin>>a[i];
    }
    if (n == 1) {
      cout<<1<<"\n";
      return;
    }
    if (n == 2) {
      cout<<1 + (a[1] != a[2])<<"\n";
      return;
    }
    VI pref(n + 2);
    VI pref2(n + 2);
    RE (i, n) {
      pref[i] = pref[i - 1] + a[i];
      pref2[i] = a[i];
      if (i >= 2) {
        pref2[i] += pref2[i - 2];
      }
    }
    int max_val = (pref[n] - 1) / 2;
    auto Sum = [&](int a, int b) {
      return pref[b] - pref[a - 1];
    };
    int res = 0;
    FOR (b, 0, n) {
      REP (take_P, 2) {
        REP (take_C, 2) {
          int k = b - take_P;
          if (k == -1 || (take_P && k <= 1)) { continue; }
          int kl = 0, kp = (n - b) / 2, faj = -1;
          if (take_C) {
            if (n - b - 3 < 0) {
              kp = -1;
            } else {
              kp = (n - b - 3) / 2;
            }
          }
          while (kl <= kp) {
            int aktc = (kl + kp) / 2;
            if (Sum(take_P + 1, b) + pref2[b + 2 * aktc] - pref2[b] + take_C * a[n] <= max_val) {
              faj = aktc;
              kl = aktc + 1;
            } else {
              kp = aktc - 1;
            }
          }
          debug(b, take_P, take_C, faj + 1);
          res += faj + 1;
        }
      }
    }
    FOR (k, 2, n - 2) {
      if (Sum(k + 1, n) <= max_val) {
        res++;
      }
    }
    cout<<res % P<<"\n";
    
  }
};
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   int n = 10;
//   REP (mask, 1 << n) {
//     VI cs, ps;
//     string s;
//     REP (bit, n) {
//       if (mask & (1 << bit)) {
//         cs.PB(bit);
//         s += "C";
//       } else {
//         ps.PB(bit);
//         s += "P";
//       }
//     }
//     int fail = 0;
//     REP (i, SZ(cs) - 2) {
//       if (cs[i + 1] - cs[i] > cs[i + 2] - cs[i + 1]) {
//         fail = 1;
//       }
//     }
//     REP (i, SZ(ps) - 2) {
//       if (ps[i + 1] - ps[i] < ps[i + 2] - ps[i + 1]) {
//         fail = 1;
//       }
//     }
//     if (!fail) {
//       cout<<s<<endl;
//     }
//     
//     int ok = 0;
//     if (s[0] == 'P' && s.back() == 'C') {
//       
//   }
  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}