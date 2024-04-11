#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

const int M = 3e5 + 5;
int par[M];
VI sons[M];
int sz[M];
int cent[M];

class TreeSums {
  public:
//   VI L;
//   VI par;
//   VVI sons;
//   int res;
//   VI sz;
//   VI cent;
//   VI sum_deps;
//   VI dep_cent;
//   VI ans;
  void Dfs(int v) {
    sz[v] = 1;
    cent[v] = v;
    PII best_lol = {-1, -1};
    for (auto son : sons[v]) {
      Dfs(son);
      sz[v] += sz[son];
      maxi(best_lol, {sz[son], son});
    }
    if (best_lol == MP(-1, -1)) {
      return;
    }
    int big_son = best_lol.nd;
    cent[v] = cent[big_son];
    auto UpperTree = [&](int guy) {
      return sz[v] - sz[guy];
//       int upper_tree = sz[v] - 1;
//       
//       for (auto s : sons[guy]) {
//         upper_tree -= sz[s];
//       }
//       return upper_tree;
    };
    while (1) {
      int upper = UpperTree(cent[v]);
      if (upper <= sz[v] / 2) {
        break;
      }
      cent[v] = par[cent[v]];
    }
  }
    
    
  void findSums(int N) {
    int k;
    scanf("%d", &k);
    //cin>>k;
    int n = N;
//     par.resize(n + 2);
//     sons.resize(n + 2);
//     sz.resize(n + 2);
//     cent.resize(n + 2);
    FOR (i, 0, N - 2) {
      scanf("%d", &par[i + 1]);
      //cin>>par[i + 1];
      par[i + 1]--;
      sons[par[i + 1]].PB(i + 1);
    }
    Dfs(0);
    RE (i, k) {
      int v;
      scanf("%d", &v);
      //cin>>v;
      v--;
      printf("%d\n", cent[v] + 1);
    }
  }

};
    
int32_t main() {

//   ios_base::sync_with_stdio(0);
//   cout << fixed << setprecision(10);
//   cerr << fixed << setprecision(10);
//   cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  scanf("%d", &n);
  //cin>>n;
  TreeSums hehs;
  hehs.findSums(n);
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}