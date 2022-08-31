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
int pre[N];
int sz[N];
int par[N];
int d;
VI slo[N];
void Dfs(int v) {
  d++;
  pre[v] = d;
  sz[v] = 1;
  for (auto nei : slo[v]) {
    if (pre[nei]) { continue; }
    par[nei] = v;
    Dfs(nei);
    sz[v] += sz[nei];
  }
}

bool IsAncOf(int a, int b) {
  return pre[a] <= pre[b] && pre[b] + sz[b] <= pre[a] + sz[a];
}
set<PII> in, out;
VI GetPath(int a, int b) {
  VI from_a, from_b;
  REP (tr, 2) {
    VI here;
    here.PB(a);
    while (!IsAncOf(a, b)) {
      a = par[a];
      here.PB(a);
    }
    swap(a, b);
    if (tr == 0) {
      from_a = here;
    } else {
      from_b = here;
    }
  }
  
  from_b.pop_back();
  reverse(ALL(from_b));
  from_a.insert(from_a.end(), ALL(from_b));
  return from_a;
}
  
  
const int P = 1e9 + 7;
int Fac(int n) {
  if (n <= 1) { return 1; }
  return n * Fac(n - 1) % P;
}
void Exit() {
  cout<<"0\n";
  exit(0);
}
int deg[N];
struct Ziomeg {
  void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) { Exit(); }
    rep[a] = b;
  }
  map<int, int> rep;
  map<int, int> sz;
  int& GetRep(int x) {
    if (rep.count(x) == 0) { rep[x] = x; }
    return rep[x];
  }
  int Find(int x) {
    if (GetRep(x) == x) { return x; }
    return GetRep(x) = Find(GetRep(x));
  }
};
Ziomeg FU[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  //13:55
  int n;
  cin>>n;
  RE (i, n - 1) {
    int a, b;
    cin>>a>>b;
    slo[a].PB(b);
    slo[b].PB(a);
    deg[a]++;
    deg[b]++;
  }
  Dfs(1);
  RE (i, n) {
    int a;
    cin>>a;
    if (a) { // from a to i
      if (a == i) { Exit(); }
      VI path = GetPath(a, i);
      for (auto v : path) {
        deg[v]--;
      }
      FU[path[0]].Union(path[1], n + 1);
      FU[path.back()].Union(path[SZ(path) - 2], n + 2);
      RE (j, SZ(path) - 2) {
        FU[path[j]].Union(path[j - 1], path[j + 1]);
      }
      REP (j, SZ(path) - 1) {
        if (in.count({path[j], path[j + 1]})) { Exit(); }
        in.insert({path[j], path[j + 1]});
      }
    }
  }
  int res = 1;
  RE (i, n) {
    if (FU[i].Find(n + 1) && FU[i].Find(n + 1) == FU[i].Find(n + 2)) {
      if (SZ(FU[i].rep) != SZ(slo[i]) + 2) { Exit(); }
      for (auto p : FU[i].rep) {
        if (FU[i].Find(p.st) != FU[i].Find(n + 1)) { Exit(); }
      }
    }
    res = (res * Fac(deg[i])) % P;
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}