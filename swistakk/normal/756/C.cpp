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

struct Node {
  int tot_bil, min_bil;
  int tot_push;
  int num;
};

Node Merge(Node a, Node b) {
  Node n;
  n.tot_bil = a.tot_bil + b.tot_bil;
  n.tot_push = a.tot_push + b.tot_push;
  n.num = 0;
  n.min_bil = min(a.min_bil, a.tot_bil + b.min_bil);
  return n;
}

const int M = 1 << 18;
Node drz[2 * M + 5];
int GetRes(int v, int czapa) {
  if (drz[v].num) {
    assert(czapa == 0);
    return drz[v].num;
  }
  int delta = drz[2 * v + 1].tot_bil - drz[2 * v + 1].min_bil;
  if (delta > czapa) {
    return GetRes(2 * v + 1, czapa);
  }
  return GetRes(2 * v, czapa - drz[2 * v + 1].tot_bil);
}
//~ int GetKth(int v, int k) {
  //~ Node& n = drz[v];
  //~ if (n.num) {
    //~ assert(k == 1);
    //~ return n.num;
  //~ }
  //~ if (drz[2 * v].tot_push <= k) {
    //~ return GetKth(2 * v, k);
  //~ }
  //~ return GetKth(2 * v + 1, k - drz[2 * v].tot_push;
//~ }



int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (_, n) {
    int ind, t;
    cin>>ind>>t;
    if (t == 1) {
      int x;
      cin>>x;
      int v = ind + M;
      drz[v].tot_bil = 1;
      drz[v].min_bil = 0;
      drz[v].num = x;
      v /= 2;
      while (v) {
        drz[v] = Merge(drz[2 * v], drz[2 * v + 1]);
        v /= 2;
      }
    } else {
      int v = ind + M;
      drz[v].tot_bil = -1;
      drz[v].min_bil = -1;
      v /= 2;
      while (v) {
        drz[v] = Merge(drz[2 * v], drz[2 * v + 1]);
        v /= 2;
      }
    }
    int from_min = drz[1].tot_bil - drz[1].min_bil;
    if (from_min == 0) {
      cout<<"-1\n";
    } else {
      cout<<GetRes(1, 0)<<"\n";
    }
      // tot_push + 
  }
  

  return 0;
}