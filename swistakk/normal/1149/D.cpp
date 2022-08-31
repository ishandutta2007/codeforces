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

const int N = 72;
VI sloa[N];
VI slob[N];
int vis[N];
int dis[N][1 << 17];
const int kInf = 2e9;
int cc[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, a, b;
  cin>>n>>m>>a>>b;
  RE (i, m) {
    int u, v, c;
    cin>>u>>v>>c;
    if (c == a) {
      sloa[u].PB(v);
      sloa[v].PB(u);
    } else {
      slob[u].PB(v);
      slob[v].PB(u);
    }
  }
  REP (i, N) {
    REP (j, 1 << 17) {
      dis[i][j] = kInf;
    }
  }
  int nxt_cc = 0;
  int nxt_small_cc = 0;
  int big1 = 0;
  RE (v, n) {
    if (vis[v]) { continue; }
    VI que{v};
    vis[v] = 1;
    for (int ii = 0; ii < SZ(que); ii++) {
      int u = que[ii];
      for (auto nei : sloa[u]) {
        if (vis[nei]) { continue; }
        vis[nei] = 1;
        que.PB(nei);
      }
    }
    for (auto u : que) {
      if (SZ(que) >= 4) {
        cc[u] = nxt_cc;
      } else {
        cc[u] = -nxt_small_cc - 1;
      }
    }
    if (v == 1) {
      if (SZ(que) >= 4) {
        big1 = 1;
      }
    }
    if (SZ(que) >= 4) {
      nxt_cc++;
    } else {
      nxt_small_cc++;
    }
  }
  set<pair<int, PII>> que;
  dis[1][big1] = 0;
  que.insert({0, {1, big1}});
  while (SZ(que)) {
    auto it = que.begin();
    int cost = it->st;
    auto pr = it->nd;
    int v = pr.st;
    int mask = pr.nd;
    que.erase(que.begin());
    for (auto nei : sloa[v]) {
      int cand = cost + a;
      if (dis[nei][mask] > cand) {
        que.erase({dis[nei][mask], {nei, mask}});
        dis[nei][mask] = cand;
        que.insert({dis[nei][mask], {nei, mask}});
      }
    }
    for (auto nei : slob[v]) {
      int cand = cost + b;
      if (cc[nei] == cc[v]) { continue; }
      if (cc[nei] >= 0 && mask & (1 << cc[nei])) { continue; }
      int nmask = mask;
      if (cc[nei] >= 0) {
        nmask += (1 << cc[nei]);
      }
      if (dis[nei][nmask] > cand) {
        que.erase({dis[nei][nmask], {nei, nmask}});
        dis[nei][nmask] = cand;
        que.insert({dis[nei][nmask], {nei, nmask}});
      }
    }
  }
  RE (i, n) {
    int best = kInf;
    REP (j, 1 << 17) {
      mini(best, dis[i][j]);
    }
    cout<<best<<" ";
  }
  cout<<endl;
        
    
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}