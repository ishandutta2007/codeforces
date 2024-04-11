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
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<endl; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++;
  cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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

#define pow poww
string s, t;
const int P = 1e9 + 7;
int Q;
const int N = 1e6 + 5;
int hash_pref[N];
int any0, any1;
int pow[N];
int n;
int GetHash(int a, int b) {
  debug(n, b);
  return (hash_pref[b] - hash_pref[a - 1] + P) * pow[n - b] % P;
}
bool Check(int x, int y) {
  int H0 = -1, H1 = -1;
  if (any0 == 0) {
    H0 = GetHash(1, x);
    H1 = GetHash(x * any1 + 1, x * any1 + y);
  } else {
    H1 = GetHash(1, y);
    H0 = GetHash(y * any0 + 1, y * any0 + x);
  }
  if (H0 == H1) {
    return false;
  }
  int nxt = 1;
  REP (i, SZ(s)) {
    if (s[i] == '0') {
      if (GetHash(nxt, nxt + x - 1) != H0) { return false; }
      nxt += x;
    }
    if (s[i] == '1') {
      if (GetHash(nxt, nxt + y - 1) != H1) { return false; }
      nxt += y;
    }
  }
  return true;
}
    
#include <chrono>
using namespace std::chrono;
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  Q = system_clock::now().time_since_epoch().count() % P;
  pow[0] = 1;
  RE (i, N - 1) {
    pow[i] = pow[i - 1] * Q % P;
  }
  cin>>s>>t;
  n = SZ(t);
  t = ' ' + t;
  RE (i, SZ(t)) {
    hash_pref[i] = (hash_pref[i - 1] + pow[i] * t[i]) % P;
  }
  int c0 = 0, c1 = 0;
  REP (i, SZ(s)) {
    if (s[i] == '0') {
      any0 = i;
      break;
    } 
  }
  REP (i, SZ(s)) {
    if (s[i] == '1') {
      any1 = i;
      break;
    } 
  }
  for (auto x : s) {
    if (x == '0') {
      c0++;
    } else {
      c1++;
    }
  }
  int cnt = 0;
  RE (x, SZ(t) / SZ(s)) {
    int y = (n - x * c0) / c1;
    if (x * c0 + y * c1 == n) {
      cnt += Check(x, y);
    }
  }
  RE (y, SZ(t) / SZ(s)) {
    int x = (n - y * c1) / c0;
    if (x * c0 + y * c1 == n && x > SZ(t) / SZ(s)) {
      cnt += Check(x, y);
    }
  }
  cout<<cnt<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}