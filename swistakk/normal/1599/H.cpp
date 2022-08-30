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

int X1, Y1, X2, Y2;
int Ask(int a, int b) {
#ifdef LOCAL
  if (a >= X1 && a <= X2 && b >= Y1 && b <= Y2) { exit(1); }
  int len = 0;
  if (a < X1) { len += X1 - a; }
  if (a > X2) { len += a - X2; }
  if (b < Y1) { len += Y1 - b; }
  if (b > Y2) { len += b - Y2; }
  return len;
#endif
  cout<<"? "<<a<<" "<<b<<endl;
  int r;
  cin>>r;
  return r;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  //int cl = clock() + 10000 * clock();
  int cl = 246274620;
  srand(cl);
  debug(cl);
  int M = 1e9;
  
  #ifdef LOCAL
  X1 = 2 + rand() % (M - 3);
  X2 = 2 + rand() % (M - 3);
  Y1 = 2 + rand() % (M - 3);
  Y2 = 2 + rand() % (M - 3);
  if (X1 > X2) { swap(X1, X2); }
  if (Y1 > Y2) { swap(Y1, Y2); }
  debug(X1, Y1, X2, Y2);
#endif
  int c1 = Ask(1, 1);
  int c2 = Ask(1, M);
  int y = (M + 1 + c1 - c2) / 2;
  debug(c1, c2, y);
  int x1 = Ask(1, y) + 1;
  int y1 = c1 + 2 - x1;
  int y2 = M - 1 - c2 + x1;
  int c3 = Ask(M, M);
  int x2 = 2 * M - y2 - c3;
  cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
#ifdef LOCAL
  assert(x1 == X1 && x2 == X2 && y1 == Y1 && y2 == Y2);
#endif
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}