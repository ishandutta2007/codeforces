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

const int N = 1e6 + 5;
int fib[N];
VI slo[N];
int fibp1[N];
int forb[N];
int is_fib[N];
int par[N];
int sz[N];
int t[N];
int Ok(int root, int n) {
  if (n <= 3) {
    return 1;
  }
  int pr1 = fibp1[n];
  int pr2 = fibp1[pr1];
  VPII here;
  function<void(int)> Dfs = [&](int v) {
    sz[v] = 1;
    for (auto nei : slo[v]) {
      if (nei == par[v] || forb[nei]) { continue; }
      Dfs(nei);
      sz[v] += sz[nei];
    }
    if (sz[v] == pr1 || sz[v] == pr2) {
      here.PB({v, sz[v]});
      //szs.PB(sz[v]);
    }
  };
  Dfs(root);
  assert(SZ(here) <= 2);
  random_shuffle(ALL(here));
  for (auto hh : here) {
    int h = hh.st;
    forb[h] = 1;
    int c = Ok(h, hh.nd) && Ok(root, n - hh.nd);
    forb[h] = 0;
    if (c) { return 1; }
  }
  return 0;
  //if (SZ(here) < 2) { return 0; }
//   forb[here[0]] = 1;
//   int c1 = Ok(here[0], sz[here[0]]) && Ok(root, n - sz[here[0]]);
//   forb[here[0]] = 0;
//   if (c1) { return 1; }
//   forb[here[1]] = 1;
//   c1 = Ok(here[1], sz[here[1]]) && Ok(root, n - sz[here[1]]);
//   forb[here[1]] = 0;
//   return c1;
}

void Dfs(int v, int p) {
  //vis[v] = 1;
  for (auto nei : slo[v]) {
    if (nei == p) { continue; }
    par[nei] = v;
    Dfs(nei, v);
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n - 1) {
    int u, v;
    cin>>u>>v;
    slo[u].PB(v);
    slo[v].PB(u);
  }
  Dfs(1, -1);
  fib[0] = 0;
  fib[1] = 1;
  t[1] = 1;
  FOR (i, 2, 30) {
    fib[i] = fib[i - 1] + fib[i - 2];
    t[i] = 2 * (t[i - 1] + t[i - 2]);
    is_fib[fib[i]] = 1;
    fibp1[fib[i]] = fib[i - 1];
  }
  debug(fib[27], fib[30], log(t[27]) / log(10));
  if (!is_fib[n]) {
    cout<<"no\n";
    return 0;
  }
  if (Ok(1, n)) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}