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

const int N = 3e4 + 5;
VI slo[N];
int vis[N];
VI stos;
int on_cyc[N];
VI cyc;
void Dfs1(int v, int par) {
  vis[v] = 1;
  stos.PB(v);
  for (auto nei : slo[v]) {
    if (nei == par) { continue; }
    if (vis[nei]) {
      FORD (ind, SZ(stos) - 1, 0) {
        cyc.PB(stos[ind]);
        on_cyc[stos[ind]] = 1;
        if (stos[ind] == nei) {
          throw 1;
        }
      }
    }
    Dfs1(nei, v);
  }
  stos.pop_back();
}
int sz[N];
int sum_szs[N];
void Dfs2(int v) {
  sz[v] = 1;
  for (auto nei : slo[v]) {
    if (on_cyc[nei]) { continue; }
    if (sz[nei]) { continue; }
    Dfs2(nei);
    sum_szs[v] += sum_szs[nei];
    sz[v] += sz[nei];
  }
  sum_szs[v] += sz[v];
}
int res[N];
int n;
void Dfs3(int v) {
  for (auto nei : slo[v]) {
    if (on_cyc[nei]) { continue; }
    if (res[nei]) { continue; }
    res[nei] = res[v] + n - 2 * sz[nei];
    Dfs3(nei);
  }
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    int a, b;
    cin>>a>>b;
    a++;
    b++;
    slo[a].PB(b);
    slo[b].PB(a);
  }
  try {
    Dfs1(n, 0);
  } catch (...) {
  }
  RE (i, n) {
    debug(i, on_cyc[i]);
  }
  
  VI szs;
  int bonus = 0;
  for (auto v : cyc) {
    Dfs2(v);
    bonus += sum_szs[v] - sz[v];
    szs.PB(sz[v]);
  }
  for (auto v : cyc) {
    szs.PB(sz[v]);
  }
  VI dp(SZ(szs));
  for (auto v : cyc) {
    szs.PB(sz[v]);
  }
  debug(cyc);
  debug(szs);
  dp.insert(dp.begin(), 0);
  VI pref_sum = szs;
  RE (i, SZ(pref_sum) - 1) {
    pref_sum[i] += pref_sum[i - 1];
  }
  FOR (len, 1, SZ(cyc) - 1) {
    debug(dp);
    VI ndp(SZ(dp) - 1);
    REP (i, SZ(dp) - 1) {
      ndp[i] = pref_sum[i + len] - pref_sum[i] + max(dp[i], dp[i + 1]);
    }
    dp = ndp;
  }
  debug(dp);
  REP (i, SZ(cyc)) {
    int v = cyc[i];
    res[v] = dp[i] + bonus + n;
    Dfs3(v);
    debug(v, res[v]);
  }
  int best = 0;
  RE (i, n) {
    maxi(best, res[i]);
    debug(i, res[i]);
  }
  cout<<best<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}