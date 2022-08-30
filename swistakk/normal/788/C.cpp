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

const int N = 1e5;
int dis[N];
int has[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, k;
  cin>>n>>k;
  int is_sm = 0, is_eq = 0, is_gr = 0;
  VI neg, pos;
  VI moves;
  RE (i, k) {
    int a;
    cin>>a;
    has[a] = 1;
    //~ if (a < n) {
      //~ neg.PB(n - a);
    //~ } else if (a == n) {
      //~ cout<<"1"<<endl;
      //~ return 0;
    //~ } else {
      //~ pos.PB(a - n);
    //~ }
    //~ moves.PB(n - a);
  }
  REP (a, 1e3 + 2) {
    if (!has[a]) { continue; }
    if (a < n) {
      neg.PB(n - a);
    } else if (a == n) {
      cout<<"1"<<endl;
      return 0;
    } else {
      pos.PB(a - n);
    }
    moves.PB(n - a);
  }
  if (pos.empty() || neg.empty()) {
    cout<<"-1\n";
    return 0;
  }
  int M = 1e4;
  int L = M - 1e3;
  int R = M + 1e3;
  FOR (i, L, R) {
    dis[i] = 1e9;
  }
  dis[M] = 0;
  VI que{M};
  for (int ii = 0; ii < SZ(que); ii++) {
    int v = que[ii];
    debug(v);
    for (auto m : moves) {
      int nei = v + m;
      if (nei < L || nei > R) {
        continue;
      }
      if (nei == M) {
        cout<<dis[v]+1<<endl;
        return 0;
      }
      if (dis[nei] > 1e8) {
        dis[nei] = dis[v] + 1;
        que.PB(nei);
      }
    }
  }
    
    
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}