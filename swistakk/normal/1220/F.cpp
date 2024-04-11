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
  int val, ma/*, to_push*/;
};

const int M = 1 << 18;
Node drz[2 * M + 5];
// void Touch(int v) {
//   if (v >= M) { return; }
//   FOR (son, 2 * v, 2 * v + 1) {
//     drz[son] 
void Add(int bl, int br, int l, int r, int node, int to_add) {
  if (br < l || bl > r) { return; }
  if (l <= bl && br <= r) {
    drz[node].val += to_add;
    drz[node].ma += to_add;
    return;
  }
  int m = (bl + br) / 2;
  Add(bl, m, l, r, 2 * node, to_add);
  Add(m + 1, br, l, r, 2 * node + 1, to_add);
  drz[node].ma = drz[node].val + max(drz[2 * node].ma, drz[2 * node + 1].ma);
}
int ReadPt(int a) {
  a += M - 1;
  int sum = 0;
  while (a) {
    sum += drz[a].val;
    a /= 2;
  }
  return sum;
}

VI Go(VI vals) {
  REP (i, 2 * M + 5) {
    drz[i].val = drz[i].ma = 0;
  }
  debug(vals);
  VI stos;
  stos.PB(0);
  VI res{0};
  RE (i, SZ(vals) - 1) {
    //int hei = vals[i];
    while (vals[stos.back()] > vals[i]) {
      stos.pop_back();
      debug(stos);
    }
    debug(stos.back() + 1, i - 1);
    Add(1, M, stos.back() + 1, i - 1, 1, 1);
    Add(1, M, i, i, 1, ReadPt(stos.back()) + 1);
    res.PB(drz[1].ma);
    stos.PB(i);
  }
  debug(res);
  return res;
}
  
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n;
  cin>>n;
  int wh1 = 0;
  VI per(2 * n + 5);
  RE (i, n) {
    cin>>per[i];
    per[i + n] = per[i];
    if (per[i] == 1) {
      wh1 = i;
    }
  }
  VI right, left;
  FOR (i, wh1, wh1 + n - 1) {
    right.PB(per[i]);
  }
  FORD (i, wh1 + n, wh1 + 1) {
    left.PB(per[i]);
  }
  VI reses_right = Go(right);
  VI reses_left = Go(left);
  int wh_min = -1, mind = n + 1;
  FOR (i, 0, n - 1) {
    int cand = 1 + max(reses_right[i], reses_left[n - 1 - i]);
    if (cand < mind) {
      mind = cand;
      wh_min = i;
    }
  }
  cout<<mind<<" "<<(n - (2 * n - wh_min - wh1) % n) % n<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}