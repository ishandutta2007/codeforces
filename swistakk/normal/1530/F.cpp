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


const int P = 31607;
int inv(int a) {
  int b = P - 2;
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n;
  cin>>n;
  int i10k = inv(10000);
  VVI orig(n, VI(n));
  REP (i, n) {
    REP (j, n) {
      int a;
      cin>>a;
      orig[i][j] = a * i10k % P;
    }
  }
  int res = 0;
  REP (is_main, 2) {
    REP (is_anti, 2) {
      auto p = orig;
      int mult = 1;
      REP (i, n) {
        REP (j, n) {
          if ((is_main && i == j) || (is_anti && i + j == n - 1)) {
            mult = orig[i][j] * mult % P;
            p[i][j] = 1;
          }
        }
      }
      vector<VI> cols(n, VI(1 << n, 1));
      vector<int> p_row(n, 1);
      REP (i, n) {
        REP (j, n) {
          p_row[i] = p_row[i] * p[i][j] % P;
        }
      }
      vector<int> p_mask_row(1 << n, 1);
      FOR (mask, 1, (1 << n) - 1) {
        REP (bit, n) {
          if (mask & (1 << bit)) {
            p_mask_row[mask] = p_mask_row[mask - (1 << bit)] * p_row[bit] % P;
            break;
          }
        }
      }
      FORD (mask, (1 << n) - 1, 0) {
        REP (bit, n) {
          if (mask & (1 << bit)) { continue; }
          REP (i, n) {
            cols[i][mask] = cols[i][mask + (1 << bit)] * p[bit][i] % P;
          }
          //p_mask_row[mask] = p_mask_row[mask + (1 << bit)] * p_row[bit] % P;
          break;
        }
        int prod = p_mask_row[mask];
        debug(16 * p_mask_row[mask] % P);
        REP (i, n) {
          prod = (P + 1 - cols[i][mask]) * prod % P;
        }
        debug(16 * prod % P);
        int sign = 1;
        if (__builtin_popcount(mask) % 2 == 1) {
          sign = -1;
        }
        if (is_main) {
          sign *= -1;
        }
        if (is_anti) {
          sign *= -1;
        }
        res = (res + sign * prod % P * mult % P + P) % P;
      }
    }
  }
  
  cout<<(P + 1 - res) % P<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}