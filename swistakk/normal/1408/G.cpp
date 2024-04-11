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

const int N = 1555;
typedef bitset<N> B;
int rep[N];
int cnt_e[N];
bitset<N> membs[N];
int Find(int x) {
  if (rep[x] == x) { return x; }
  return rep[x] = Find(rep[x]);
}
void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  cnt_e[a]++;
  if (a == b) { return; }
  membs[a] |= membs[b];
  rep[b] = a;
  cnt_e[a] += cnt_e[b];
}
const int P = 998244353;
VI Merge(VI a, VI b) {
  VI c;
  c.resize(SZ(a) + SZ(b) - 1);
  REP (i, SZ(a)){
    REP (j, SZ(b)) {
      c[i + j] = (c[i + j] + a[i] * b[j]) % P;
    }
  }
  debug(a, b, c);
  return c;
}
int a[N][N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  VVI es;
  
  RE (i, n) {
    rep[i] = i;
    RE (j, n) {
      cin>>a[i][j];
      if (i < j) {
        es.PB({a[i][j], i, j});
      }
    }
  }
  sort(ALL(es));
  vector<bitset<N>> cliques;
  cliques.PB(bitset<N>());
  vector<int> last_clique(n + 2);
  vector<VI> res;
  res.PB({});
  RE (i, n) {
    B nic;
    nic[i] = 1;
    res.PB(VI{0, 1});
    cliques.PB(nic);
    membs[i][i] = 1;
    last_clique[i] = i;
  }
    
  for (auto e : es) {
    int u = e[1];
    int v = e[2];
    debug(u, v);
    u = Find(u);
    v = Find(v);
    if (u > v) {
      swap(u, v);
    }
    Union(u, v);
    int sz = membs[u].count();
    debug(cnt_e[u], sz);
    if (cnt_e[u] == sz * (sz - 1) / 2) {
      debug(membs[u]);
      B cur = membs[u];
      VI dp{1};
      while (cur.count()) {
        int wh = cur._Find_first();
        dp = Merge(dp, res[last_clique[wh]]);
        //mul = mul * res[last_clique[wh]] % P;
        cur = cur & (~cliques[last_clique[wh]]);
      }
      last_clique[u] = SZ(cliques);
      cliques.PB(membs[u]);
      dp[1] = 1;
      res.PB(dp);
    }
  }
  RE (i, n) {
    cout<<res.back()[i]<<" ";
  }
  cout<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}