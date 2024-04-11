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

// struct Low {
//   VI low, vis1, vis2, pre, ojc, art, wejdwu, most;
//   vector<VI> slo, dwu;
//   int aktdwu, d;
//   int n;
//   Low(int n_) {
//     n = n_;
//     low.resize(n + 2); vis1.resize(n + 2); vis2.resize(n + 2); pre.resize(n + 2);
//     ojc.resize(n + 2); art.resize(n + 2); wejdwu.resize(n + 2); most.resize(n + 2);
//     slo.resize(n + 2); dwu.resize(n + 2);
//     aktdwu = d = 0;
//   }
//   /* Mosty to krawedzie od v do ojc[v] takie, e most[v]=1
//   Punkty artykulacji to te, dla ktorych art[v]=1
//   Numer dwuspojnej krawedzi v->slo[v][i] to dwu[v][i] */
  
// 
//   void dfs2(int v) { // tylko do wyliczania dwuspojnych!
//     vis2[v] = 1;
//     REP (i, SZ(slo[v])) {
//       int nei = slo[v][i];
//       if (ojc[v] == nei) { dwu[v][i] = wejdwu[v]; debug(v, nei); continue; }
//       if (vis2[nei] == 0) {
//         if (low[nei] >= pre[v]) {
//           aktdwu++; wejdwu[nei] = aktdwu;
//         } else {
//           wejdwu[nei] = wejdwu[v];
//         }
//         dwu[v][i] = wejdwu[nei];
//         dfs2(nei);
//       } else {
//         if (pre[v] < pre[nei]) {
//           dwu[v][i] = wejdwu[nei];
//         } else {
//           dwu[v][i] = wejdwu[v];
//         }
//       }
//     }
//   }
//   void AddEdge(int a, int b) {
//     assert(a && b);
//     slo[a].PB(b); slo[b].PB(a);
//     dwu[a].PB(0); dwu[b].PB(0);
//   }
//   void LowGo() {
//     int st = 1;
//     d = 0; aktdwu = 0; wejdwu[st] = 0;
//     dfs1(st);
//     int licz = 0;
//     RE (i, n) { if(ojc[i] == st) { licz++; } }
//     art[st] = (licz > 1);
//     dfs2(st);
//   }
// };
const int N = 3e4 + 5;
vector<TIII> slo[N];
int pre[N], low[N], ojc[N], vis1[N];
TIII es[N];
VI path;
int s, t;
void DfsRoad(int v) {
  if (v == t) { throw 1; }
  vis1[v] = 1;
  for (auto e : slo[v]) {
    int nei = e.st;
    if (vis1[nei]) { continue; }
    path.PB(e.rd);
    DfsRoad(nei);
    path.pop_back();
  }
}
int forb_e;
int d;
int best_cost;
int cc, i1, i2;
const int V = 1e3 + 5;
int cnt[V][V];
bool Dfs1(int v) {
  bool tt = false;
  d++;
  vis1[v] = 1; pre[v] = d; low[v] = pre[v];
  REP (i, SZ(slo[v])) {
    if (slo[v][i].rd == forb_e) { continue; }
    int nei = slo[v][i].st;
    if (ojc[v] == nei) { continue; }
    if (vis1[nei] == 0) { // drzewowa w dol
      ojc[nei] = v;
      bool was_t = Dfs1(nei);
      tt |= was_t;
      mini(low[v], low[nei]);
      //if (low[nei] >= pre[v]) { art[v] = 1; }
      if (low[nei] > pre[v]) {
        //most[nei] = 1;
        if (was_t && cnt[v][nei] == 1) {
          debug(v, nei);
          if (best_cost > es[forb_e].rd + slo[v][i].nd) {
            best_cost = es[forb_e].rd + slo[v][i].nd;
            i1 = forb_e;
            i2 = slo[v][i].rd;
            cc = 2;
          }
        }
        //if (best_cost < es[forb_e]
      }
    } else { // niedrzewowa w gore
      mini(low[v], pre[nei]);
    }
  }
  tt |= (v == t);
  return tt;
} 

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  cin>>s>>t;
  
  //cerr<<"c"<<endl;
  RE (i, m) {
    int a, b, c;
    cin>>a>>b>>c;
    //debug(a, b, c);
    if (a == b) { continue; }
    slo[a].PB({b, c, i});
    slo[b].PB({a, c, i});
    cnt[a][b]++;
    cnt[b][a]++;
    es[i] = {a, b, c};
  }
  //cerr<<"a"<<endl;
  try {
    DfsRoad(s);
  } catch(...) {}
  if (path.empty()) {
    cout<<"0\n0\n\n";
    return 0;
  }
  debug(path);
  //cerr<<"b"<<endl;
  best_cost = 5e9;
  for (auto f : path) {
    forb_e = f;
    cnt[es[f].st][es[f].nd]--;
    cnt[es[f].nd][es[f].st]--;
    d = 0;
    RE (i, n) {
      vis1[i] = 0;
      pre[i] = 0;
      low[i] = 0;
      ojc[i] = 0;
    }
    bool b = Dfs1(s);
    if (!b) {
      if (best_cost > es[forb_e].rd) {
        cc = 1;
        best_cost = es[forb_e].rd;
        i1 = forb_e;
      }
    }
    cnt[es[f].st][es[f].nd]++;
    cnt[es[f].nd][es[f].st]++;
  }
  
  
  if (best_cost > 4e9) {
    cout<<"-1\n";
    return 0;
  }
  cout<<best_cost<<endl<<cc<<endl<<i1;
  if (cc == 2) {
    cout<<" "<<i2;
  }
  cout<<endl;
    
    
  
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}