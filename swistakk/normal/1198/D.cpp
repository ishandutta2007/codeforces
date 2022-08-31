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

const int N = 52;
int dp[N][N][N][N];
int prefs[N][N];
int board[N][N];
int Ask(int il, int ir, int jl, int jr) {
  return prefs[ir][jr] - prefs[il - 1][jr] - prefs[ir][jl - 1] + prefs[il - 1][jl - 1];
}
int Go(int il, int ir, int jl, int jr) {
  if (dp[il][ir][jl][jr] != -1) {
    return dp[il][ir][jl][jr];
  }
  if (il > ir || jl > jr) { return 0; }
  int wi = ir - il + 1;
  int wj = jr - jl + 1;
  dp[il][ir][jl][jr] = max(wi, wj);
  FOR (i, il, ir) {
    if (Ask(i, i, jl, jr) == 0) {
      mini(dp[il][ir][jl][jr], Go(il, i - 1, jl, jr) + Go(i + 1, ir, jl, jr));
    }
  }
  FOR (j, jl, jr) {
    if (Ask(il, ir, j, j) == 0) {
      mini(dp[il][ir][jl][jr], Go(il, ir, jl, j - 1) + Go(il, ir, j + 1, jr));
    }
  }
  return dp[il][ir][jl][jr];
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  REP (i, N) {
    REP (j, N) {
      REP (k, N) {
        REP (l, N) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
  int n;
  cin>>n;
  RE (i, n) {
    RE (j, n) {
      char c;
      cin>>c;
      if (c == '#') {
        board[i][j] = 1;
      }
      prefs[i][j] = prefs[i - 1][j] + prefs[i][j - 1] - prefs[i - 1][j - 1] + board[i][j];
    }
  }
  cout<<Go(1, n, 1, n)<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}