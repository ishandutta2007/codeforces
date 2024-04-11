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

struct Node {
  int sum, extendable_pref, nonextendable_pref, extendable_suf, nonextendable_suf, best_res, whole;
  Node() {
    sum = extendable_pref = nonextendable_pref = extendable_suf = nonextendable_suf = best_res = whole = 0;
  }
};

Node Merge(Node L, Node R) {
  Node n;
  n.sum = L.sum + R.sum;
  n.extendable_pref = max(L.extendable_pref, L.sum + R.extendable_pref);
  n.extendable_suf = max(R.extendable_suf, -R.sum + L.extendable_suf);
  n.nonextendable_pref = max(L.nonextendable_pref, max(L.whole + R.extendable_pref, -L.sum + R.nonextendable_pref));
  n.nonextendable_suf  = max(R.nonextendable_suf , max(R.whole + L.extendable_suf,  L.nonextendable_suf + R.sum));
  n.whole = max(L.whole + R.sum, max(R.whole - L.sum, -L.sum + R.sum));
  n.best_res = max(L.best_res, max(R.best_res, max(L.extendable_suf + R.nonextendable_pref, L.nonextendable_suf + R.extendable_pref)));
  maxi(n.best_res, max(n.extendable_pref, max(n.extendable_suf, max(n.nonextendable_pref, n.nonextendable_suf)))); 
  return n;
}

const int M = 1 << 18;
Node drz[2 * M + 5];

Node From(int val) {
  Node n;
  if (val == 1) {
    n.sum = 1;
    n.extendable_pref = 1;
    n.nonextendable_pref = 1;
    n.extendable_suf = 0;
    n.nonextendable_suf = 0;
    n.best_res = 1;
    n.whole = 1;
  } else {
    n.sum = -1;
    n.extendable_pref = 0;
    n.nonextendable_pref = 0;
    n.extendable_suf = 1;
    n.nonextendable_suf = 1;
    n.best_res = 1;
    n.whole = 1;
  }
  return n;
}

void Upd(int p, int val) {
  p += M;
  drz[p] = From(val);
  p /= 2;
  while (p) {
    drz[p] = Merge(drz[2 * p], drz[2 * p + 1]);
    p /= 2;
  }
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<int> digs;
  REP (i, SZ(s)) {
    if (s[i] == ')') {
      digs.PB(-1);
    } else {
      digs.PB(1);
    }
  }
  REP (i, SZ(digs)) {
    drz[i + M] = From(digs[i]);
  }
  FORD (i, M - 1, 1) {
    drz[i] = Merge(drz[2 * i], drz[2 * i + 1]);
  }
  cout<<drz[1].best_res<<"\n";
  RE (i, q) {
    int a, b;
    cin>>a>>b;
    a--;
    b--;
    digs[a] = -digs[a];
    digs[b] = -digs[b];
    Upd(a, digs[a]);
    Upd(b, digs[b]);
    cout<<drz[1].best_res<<"\n";
  }
  
  debug(drz[M / 8].nonextendable_suf, drz[M / 8 + 1].extendable_pref);
  debug(drz[M / 4].nonextendable_suf, drz[M / 4].sum);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}