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
int vis[N];
int w[N];
set<int> slo1[N];
set<int> slo2[N];
int res;
int deepest[N];
int cleared[N];
int s;
void Check(int v) {
  if (v == s) { return; }
  if (SZ(slo1[v]) == 1) {
    cleared[v] = 1;
    int par = *slo1[v].begin();
    maxi(deepest[par], deepest[v] + w[v]);
    slo1[par].erase(v);
    Check(par);
  }
}
int oth_deepest;
int to_non_cleared;
int first_non_cleared;
void Dfs(int v, int cur_score) {
  vis[v] = 1;
  if (first_non_cleared == -1 && !cleared[v]) {
    first_non_cleared = v;
    debug("here");
    to_non_cleared = cur_score - w[v];
  }
//   if (v != first_non_cleared && !cleared[v]) {
//     maxi(oth_deepest, deepest[v]);
//   }
  
  maxi(res, cur_score);
  for (auto nei : slo2[v]) {
    if (vis[nei]) { continue; }
    Dfs(nei, cur_score + w[nei]);
  }
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, n) {
    cin>>w[i];
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo1[a].insert(b);
    slo1[b].insert(a);
    slo2[a].insert(b);
    slo2[b].insert(a);
  }
  cin>>s;
  RE (i, n) {
    Check(i);
  }
  to_non_cleared = -1;
  first_non_cleared = -1;
  int sum_non_cleared = 0;
  RE (i, n) {
    if (!cleared[i]) {
      sum_non_cleared += w[i];
    }
    debug(i, cleared[i]);
  }
  Dfs(s, w[s]);
  debug(to_non_cleared, sum_non_cleared, first_non_cleared);
  RE (i, n) {
    debug(i, deepest[i]);
    maxi(oth_deepest, deepest[i]);
  }
//   if (s == first_non_cleared) {
//     maxi(oth_deepest, deepest[s]);
//   }
  cout<<max(sum_non_cleared + to_non_cleared + oth_deepest, res)<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}