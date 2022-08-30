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

// const int N = 1e6;
// int ind_inad[N];
// 
// vector<int> inads;
// 
// 
// bool IsInad(int x) {
//   if (x <= 9) { return 1; }
//   if (ind_inad[x / 10] == 0) { return 0; }
//   return (x % 10) < ind_inad[x / 10] % 11;
// }
  
const int N = 1e5 + 5;
int dp[N][11]; // last included position

string s;
int Go(int p, int c) {
  if (dp[p][c] != -1) {
    return dp[p][c];
  }
  if (p == SZ(s)) {
    return dp[p][c] = SZ(s) - 1;
  }
  int l = s[p] - '0';
  if (l >= c) {
    return dp[p][c] = p - 1;
  }
  int nc = (l + c * (c - 1) / 2 + 10) % 11;
  return dp[p][c] = Go(p + 1, nc);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   int cnt = 0;
//   RE (i, 10000) {
//     if (IsInad(i)) {
//       ind_inad[i] = ++cnt;
//       cerr<<i<<" ";
//     }
//     if (i % 10 == 9) {
//       cerr<<endl;
//     }
//   }
//   cerr<<endl;
  
  REP (i, N) {
    REP (j, 11) {
      dp[i][j] = -1;
    }
  }
  cin>>s;
    int res = 0;
  REP (i, SZ(s)) {
    if (s[i] == '0') { continue; }
    res += Go(i + 1, s[i] - '0') - i + 1;
    //debug(i, Go(i, 0));
  }
//   for (int i = 0; i < SZ(s); i++) {
//     if (s[i] == '0') { continue; }
//     res++;
//     int c = s[i] - '0';
//     int d1 = 0;
//     int d2 = 9;
//     FOR (j, i + 1, SZ(s) - 1) {
//       int l = s[j] - '0';
//       if (l >= c) { break; }
//       res++;
//       
//       //c = ((1 + l + d2 + c * (c - 1) / 2 - d1 * (d1 + 1) / 2) % 11 + 11) % 11;
//       c = (l + c * (c - 1) / 2 + 10) % 11;
// //       if (SZ(s) < 20) {
// //         debug(c, d1, d2, s.substr(i, j - i + 1));
// //       }
// //       int cpd2 = d2;
// //       d2 = (((d2 + d2 * (d2 + 1) / 2 - d1 * (d1 + 1) / 2) % 11) + 11) % 11;
// //       d1 = cpd2;
// //       debug(d1, d2);
//     }
//   }
//   
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}