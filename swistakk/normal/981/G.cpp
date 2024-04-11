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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

struct Node {
  int push_add, push_mul, cur_sz;
  Node() {
    push_add = 0;
    push_mul = 1;
    cur_sz = 0;
  }
};

const int P = 998244353;
const int M = 1 << 18;
Node drz[2 * M + 5];
int wid[2 * M + 5];
void Apply(int add, int mul, int v) {
  //debug(add, mul, v);
  drz[v].cur_sz = (drz[v].cur_sz * mul + add * wid[v]) % P;
  drz[v].push_mul = drz[v].push_mul * mul % P;
  drz[v].push_add = (drz[v].push_add * mul + add) % P;
}
void UpdSz(int node) {
  drz[node].cur_sz = (drz[2 * node].cur_sz + drz[2 * node + 1].cur_sz) % P;
}
void Touch(int v) {
  if (v >= M) {
    return;
  }
  FOR (son, 2 * v, 2 * v + 1) {
    Apply(drz[v].push_add, drz[v].push_mul, son);
  }
  drz[v].push_add = 0;
  drz[v].push_mul = 1;
  UpdSz(v);
}
    
void GoRec(int l, int r, int bl, int br, int node, bool is_mul) {
  if (node == 1) {
    debug(l, r, is_mul);
  }
  if (l > r) { return; }
  if (l > br || r < bl) { return; }
  if (l <= bl && br <= r) {
    if (is_mul) {
      Apply(0, 2, node);
    } else {
      Apply(1, 1, node);
    }
    return;
  }
  int m = (bl + br) / 2;
  Touch(node);
  GoRec(l, r, bl, m, 2 * node, is_mul);
  GoRec(l, r, m + 1, br, 2 * node + 1, is_mul);
  UpdSz(node);
}

int ReadSum(int l, int r, int bl, int br, int node) {
  if (l > br || r < bl) { return 0; }
  if (l <= bl && br <= r) {
    return drz[node].cur_sz;
  }
  int m = (bl + br) / 2;
  Touch(node);
  return (ReadSum(l, r, bl, m, 2 * node) + ReadSum(l, r, m + 1, br, 2 * node + 1)) % P;
}

set<PII> wh_is[M];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  FOR (i, M, 2 * M) {
    wid[i] = 1;
  }
  FORD (i, M - 1, 1) {
    wid[i] = 2 * wid[2 * i];
  }
  
  int n, q;
  cin>>n>>q;
  RE (_, q) {
    int t, l, r;
    cin>>t>>l>>r;
    if (t == 1) {
      int x;
      cin>>x;
      debug(l, r, x);
      wh_is[x].insert({n + 2, 1});
      wh_is[x].insert({0, 0});
      VPII wh_it_is;
      
      int add_l = (wh_is[x].upper_bound({l, 2})->nd == 1);
      int add_r = r <= n && (wh_is[x].upper_bound({r + 1, 0})->nd == 1);
      
      int cur_in = !add_l;
      debug(add_l, add_r, cur_in, *wh_is[x].upper_bound({l, 2}));
      debug(wh_is[x]);
      int cur = l;
      while (1) {
        auto it = wh_is[x].upper_bound({cur, 2});
        assert(cur_in == !it->nd);
        if (cur_in) {
          GoRec(cur, min(it->st - 1, r), 1, M, 1, true);
        } else {
          GoRec(cur, min(it->st - 1, r), 1, M, 1, false);
        }
        cur_in ^= 1;
        cur = it->st;
        if (it->st > r) {
          break;
        } else {
          wh_is[x].erase(it);
        }
      } 
      
      if (add_l) {
        if (wh_is[x].count({l, 0})) {
          wh_is[x].erase({l, 0});
        } else {
          wh_is[x].insert({l, 1});
        }
      }
      if (add_r) {
        if (wh_is[x].count({r + 1, 1})) {
          wh_is[x].erase({r + 1, 1});
        } else {
          wh_is[x].insert({r + 1, 0});
        }
      }
// #ifdef LOCAL
//       RE (i, 2 * M) {
//         if (drz[i].cur_sz) {
//           debug(i, drz[i].cur_sz);
//         }
//       }
// #endif
//       for (auto p : wh_it_is) {
//         GoRec(p.st, p.nd, 1, M, 1, true);
//       }
//       if (wh_it_is.empty()) {
//         GoRec(l, r, 1, M, 1, false);
//       }
      
    } else {
      cout<<ReadSum(l, r, 1, M, 1)<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}