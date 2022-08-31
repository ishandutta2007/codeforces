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

struct Edge {
  int to, id;
};
const int N = 1e6 + 5;
vector<Edge> slo[N];
int ktory;
int vis[N];
//int sz[N];
int pre[N][3];
int sz[N][3];
int dep[N][3];
const int M = 1 << 20;
int d;
void Dfs(int v, int id) {
  vis[v] = id;
  sz[v][id] = 1;
  d++;
  pre[v][id] = d;
  for (auto e : slo[v]) {
    int nei = e.to;
    if (vis[nei] == id) { continue; }
    dep[nei][id] = 1 + dep[v][id];
    Dfs(nei, id);
    sz[v][id] += sz[nei][id];
  }
}
struct Node {
  int ma0, ma1, to_push;
  Node() {
    ma0 = -N, ma1 = -N;
    to_push = 0;
  }
};
struct Drz {
  vector<Node> drz;
  Drz() {
    drz.resize(2 * M + 5);
  }
  Node& operator[](int a) {
    return drz[a];
  }
  void Touch(int v) {
    if (drz[v].to_push) {
      FOR (son, 2 * v, 2 * v + 1) {
        drz[son].to_push ^= 1;
        swap(drz[son].ma0, drz[son].ma1);
      }
    }
    drz[v].to_push = 0;
  }
  void Flip(int bl, int br, int l, int r, int v) {
    if (l > br || r < bl) { return; }
    if (l <= bl && br <= r) {
      drz[v].to_push ^= 1;
      swap(drz[v].ma0, drz[v].ma1);
      return;
    }
    Touch(v);
    int m = (bl + br) / 2;
    Flip(bl, m, l, r, 2 * v);
    Flip(m + 1, br, l, r, 2 * v + 1);
    drz[v].ma0 = max(drz[2 * v].ma0, drz[2 * v + 1].ma0);
    drz[v].ma1 = max(drz[2 * v].ma1, drz[2 * v + 1].ma1);
  }
};
Drz drz[3];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n;
  cin>>n;
  VPII to_change;
  VPII es;
  RE (i, n - 1) {
    int a, b, c;
    cin>>a>>b>>c;
    es.PB({a, b});
    slo[a].PB({b, i});
    slo[b].PB({a, i});
    if (c) {
      to_change.PB({a, b});
    }
  }
  RE (i, n) {
    vis[i] = -1;
  }
  d = 0;
  Dfs(1, 0);
  int sr1 = 1;
  RE (i, n) {
    if (dep[i][0] > dep[sr1][0]) {
      sr1 = i;
    }
  }
  d = 0;
  Dfs(sr1, 1);
  int sr2 = 1;
  RE (i, n) {
    if (dep[i][1] > dep[sr2][1]) {
      sr2 = i;
    }
  }
  d = 0;
  Dfs(sr2, 2);
  debug(sr1, sr2);
  RE (wh, 2) {
    RE (v, n) {
      drz[wh][M - 1 + pre[v][wh]].ma0 = dep[v][wh];
      //cerr<<dep[v][wh]<<" ";
    }
    //cerr<<endl;
    FORD (i, M - 1, 1) {
      drz[wh][i].ma0 = max(drz[wh][2 * i].ma0, drz[wh][2 * i + 1].ma0);
    }
  }
  function<void(int, int)> Change = [&](int a, int b) {
    RE (wh, 2) {
      if (dep[b][wh] > dep[a][wh]) {
        swap(a, b);
      }
      drz[wh].Flip(1, M, pre[a][wh], pre[a][wh] + sz[a][wh] - 1, 1);
    }
  };
  for (auto ch : to_change) {
    Change(ch.st, ch.nd);
  }
  int m;
  cin>>m;
  RE (i, m) {
    int id;
    cin>>id;
    int a = es[id - 1].st;
    int b = es[id - 1].nd;
    Change(a, b);
    debug(a, b);
    debug(drz[1][1].ma0, drz[2][1].ma0);
    cout<<max(drz[1][1].ma0, drz[2][1].ma0)<<"\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}