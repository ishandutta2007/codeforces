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

struct Sol {
  struct Node {
    int sum, cov, wid;
  };
  vector<Node> drz;
  int M;
  void Touch(int v) {
    if (drz[v].cov == -1) { return; }
    FOR (son, 2 * v, 2 * v + 1) {
      drz[son].cov = drz[v].cov;
      drz[son].sum = drz[son].wid * drz[v].cov;
    }
    drz[v].cov = -1;
  }
  int Read(int bl, int br, int l, int r, int node) {
    if (bl > r || br < l) { return 0; }
    if (l <= bl && br <= r) {
      return drz[node].sum;
    }
    int m = (bl + br) / 2;
    Touch(node);
    return Read(bl, m, l, r, 2 * node) + Read(m + 1, br, l, r, 2 * node + 1);
  }
  int Sum(int l, int r) {
    return Read(1, M, l, r, 1);
  }
  void Write(int bl, int br, int l, int r, int node, int val) {
    if (bl > r || br < l) { return; }
    if (l <= bl && br <= r) {
      drz[node].sum = drz[node].wid * val;
      drz[node].cov = val;
      return;
    }
    int m = (bl + br) / 2;
    Touch(node);
    Write(bl, m, l, r, 2 * node, val);
    Write(m + 1, br, l, r, 2 * node + 1, val);
    drz[node].sum = drz[2 * node].sum + drz[2 * node + 1].sum;
    drz[node].cov = -1;
  }
  void Assign(int l, int r, int val) {
    Write(1, M, l, r, 1, val);
  }
  void Test() {
    int n, q;
    cin>>n>>q;
    M = 1;
    while (M <= n + 2) {
      M *= 2;
    }
    drz.resize(2 * M + 5);
    string s;
    string f;
    cin>>s>>f;
    
    REP (i, n) {
      drz[M + i] = {f[i] - '0', -1, 1};
    }
    FORD (i, M - 1, 1) {
      drz[i].sum = drz[2 * i].sum + drz[2 * i + 1].sum;
      drz[i].cov = -1;
      drz[i].wid = drz[2 * i].wid + drz[2 * i + 1].wid;
    }
    VPII segs;
    RE (i, q) {
      int l, r;
      cin>>l>>r;
      segs.PB({l, r});
    }
    int fail = 0;
    reverse(ALL(segs));
    for (auto p : segs) {
      int l = p.st;
      int r = p.nd;
      int wid = (r - l + 1);
      int c1 = Sum(l, r);
      int c0 = wid - c1;
      debug(l, r, c0, c1);
      if (c0 == c1) { fail = 1; break; }
      if (c0 > c1) {
        Assign(l, r, 0);
      } else {
        Assign(l, r, 1);
      }
    }
    REP (i, n) {
      if (s[i] - '0' != Sum(i + 1, i + 1)) { fail = 1; break; }
    }
    if (!fail) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
    
    
    
    
  }
};




int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}