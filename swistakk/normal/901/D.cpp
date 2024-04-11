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
const int N = 1e6 + 5;
int dep[N];
int par_v[N];
int par_e[N];
int c[N];
int vis[N];
vector<PII> slo[N];
int to_push[N];
int res[N];
int Dfs(int v) {
  vis[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (vis[nei]) { continue; }
    par_v[nei] = v;
    par_e[nei] = e.nd;
    dep[nei] = dep[v] + 1;
    int got = Dfs(nei);
    c[v] -= got;
    res[e.nd] = got;
  }
  return c[v];
}
int n, m;
void Print() {
  cout<<"YES\n";
  RE (i, m) {
    cout<<res[i]<<"\n";
  }
  exit(0);
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n>>m;
  RE (i, n) {
    cin>>c[i];
  }
  VPII es;
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    es.PB({a, b});
    slo[a].PB({b, i});
    slo[b].PB({a, i});
  }
  int heh = Dfs(1);
  assert(heh % 2 == 0);
  if (heh == 0) {
    debug("fast");
    Print();
  }
  REP (ii, SZ(es)) {
    auto e = es[ii];
    if (dep[e.st] % 2 == dep[e.nd] % 2) {
      int pchaj = heh / 2;
      if (dep[e.st] % 2) {
        res[ii + 1] -= pchaj;
      } else {
        res[ii + 1] += pchaj;
      }
      VI guys{e.st, e.nd};
      for (auto guy : guys) {
        int sign = 1;
        if (dep[e.st] % 2 == 0) {
          sign = -1;
        }
        while (guy != 1) {
          res[par_e[guy]] += sign * pchaj;
          sign *= -1;
          guy = par_v[guy];
        }
      }
      // od parzystego  
      Print();
    }
  }
  cout<<"NO\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}