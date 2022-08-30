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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;

//#define TEST  
  int n, m;
#ifdef TEST
  n = 600;
  m = n * (n - 1) / 2;
#else
  cin>>n>>m;
#endif
  const int kInf = 1e18;
  VVI dis(n + 2, VI(n + 2, kInf));
  vector<vector<PII>> es(n + 2);
  int na = 1;
  int nb = 0;
  RE (i, m) {
    int a, b, w;
#ifdef TEST
    if (na == nb + 1) {
      na++;
      nb = 1;
    } else {
      nb++;
    }
    a = na;
    b = nb;
    w = 100;
#else
    cin>>a>>b>>w;
#endif
    if (a > b) {
      swap(a, b);
    }
    mini(dis[a][b], w);
    mini(dis[b][a], w);
    es[a].PB({b, w});
  }
  RE (i, n) {
    dis[i][i] = 0;
  }
  RE (k, n) {
    RE (i, n) {
      RE (j, n) {
        mini(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  int qc;
#ifdef TEST
  qc = n * (n - 1) / 2;
#else
  cin>>qc;
#endif
  VVI qs;
  na = 1;
  nb = 0;
  RE (i, qc) {
    int u, v, l;
    #ifdef TEST
    if (na == nb + 1) {
      na++;
      nb = 1;
    } else {
      nb++;
    }
    u = na;
    v = nb;
    l = 1;
    #else
    cin>>u>>v>>l;
    #endif
    qs.PB({u, v, l});
  }
  int res = 0;
  VI satisfying(n + 2);
  RE (a, n) {
    RE (b, n) {
      satisfying[b] = -1;
    }
    for (auto& q : qs) {
//       int u = q[0];
//       int v = q[1];
//       int l = q[2];
      maxi(satisfying[q[1]], q[2] - dis[a][q[0]]);
      maxi(satisfying[q[0]], q[2] - dis[a][q[1]]);
    }
    if (a == 2) {
      debug(satisfying);
    }
    for (auto e : es[a]) {
      int b = e.st;
      int w = e.nd;
      RE (v, n) {
        if (w + dis[b][v] <= satisfying[v]) {
          res++;
          debug(a, b);
          break;
        }
      }
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}