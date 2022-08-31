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
const int N = 505;
int dp[N][N];
int col[N];
int Solve(int l, int r) {
  if (dp[l][r] != -1) { return dp[l][r]; }
  if (l >= r) { return dp[l][r] = 1; }
  int wh_min = l;
  FOR (i, l, r) {
    if (col[i] < col[wh_min]) {
      wh_min = i;
    }
  }
  int left = 0, right = 0;
  FOR (i, l, wh_min) {
    left = (left + Solve(l, i - 1) * Solve(i, wh_min - 1)) % P;
  }
  FOR (i, wh_min, r) {
    right = (right + Solve(wh_min + 1, i) * Solve(i + 1, r)) % P;
  }
  int res = left * right % P;
  return dp[l][r] = res;
}
int SolveVec(vector<int> v) {
  int n = SZ(v);
  REP (i, n + 2) {
    REP (j, n + 2) {
      dp[i][j] = -1;
    }
    if (i < n) {
      col[i + 1] = v[i];
    }
  }
  return Solve(1, n);
}
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  VI was(n + 2);
  VI blocked(n + 2);
  VI stos;
  int res = 1;
  RE (i, m) {
    int c;
    cin>>c;
    if (was[c]) {
      if (blocked[c]) {
        cout<<"0\n";
        return 0;
      }
      vector<int> heh;
      while (stos.back() != c) {
        if (stos.back() < c) {
          cout<<"0\n";
          return 0;
        }
        heh.PB(stos.back());
        blocked[stos.back()] = 1;
        stos.pop_back();
      }
      res = res * SolveVec(heh) % P;
    } else {
      stos.PB(c);
      was[c] = 1;
    }
  }
  cout<<res * SolveVec(stos) % P<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}