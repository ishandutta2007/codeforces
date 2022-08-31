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
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

const int N = 1e3 + 6;
LD dis[N];
int vis[N];
LD fail[N];
const LD kEps = 1e-8;
LD p[N][N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  if (n == 1) {
    cout<<"0\n";
    return 0;
  }
  RE (i, n) {
    RE (j, n) {
      make(int, pp);
      p[i][j] = .01 * pp;
    }
  }
//   set<pair<LD, int>> que;
//   que.insert({0, n});
  RE (i, n - 1) {
    dis[i] = 1e18;
    fail[i] = 1;
  }
  //while (!que.empty()) {
//     auto p = *que.begin();
//     que.erase(que.begin());
  vis[n] = 1;
  RE (i, n - 1) {
    fail[i] = 1 - p[i][n];
    if (p[i][n] > kEps) {
      dis[i] = 1 / p[i][n];
    }
    debug(i, dis[i], fail[i]);
  }
  while (1) {
    int best_v = 0;
    LD min_dis = 2e18;
    RE (i, n) {
      if (vis[i]) { continue; }
      if (min_dis > dis[i]) {
        best_v = i;
        min_dis = dis[i];
      }
    }
    auto v = best_v;
    LD D = min_dis;
    vis[v] = 1;
    if (v == 1) {
      cout<<dis[1]<<endl;
      return 0;
    }
    debug(v);
    RE (prev, n) {
      if (vis[prev]) { continue; }
      LD pr = p[prev][v];
      LD sum = dis[prev] * (1 - fail[prev]) - fail[prev];
      if (fail[prev] > 1 - kEps) {
        sum = 0;
      }
      sum += fail[prev] * pr * (D + 1);
      debug(prev, sum);
      fail[prev] *= (1 - pr);
      dis[prev] = (sum + fail[prev]) / (1 - fail[prev]);
      debug(prev, dis[prev]);
    }
  }
  
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}