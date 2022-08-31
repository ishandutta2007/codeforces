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

const int P = 1e9 + 7;
struct Node {
  int dep, par_dig, rem;
  VPII children; // (ind, dig)
  VI jumps;
};
vector<Node> nodes;
void CreateNode(int par_node, int dig) {
  nodes.PB({});
  auto& node = nodes.back();
  auto& par = nodes[par_node];
  node.dep = par.dep + 1;
  node.par_dig = dig;
  node.rem = (10 * par.rem + dig) % P;
  par.children.PB({SZ(nodes) - 1, dig});
  node.jumps.PB(par_node);
  REP (bit, 22) {
    auto& par_jump = nodes[node.jumps[bit]].jumps;
    if (SZ(par_jump) <= bit) {
      break;
    }
    node.jumps.PB(par_jump[bit]);
  }
}
int GetNodeMove(int node, int dig) {
  REP (i, SZ(nodes[node].children)) {
    if (nodes[node].children[i].nd == dig) { return nodes[node].children[i].st; }
  }
  CreateNode(node, dig);
  return nodes[node].children.back().st;
}
int GetNodeByPath(int node, int ind) {
  string s = to_string(ind);
  REP (i, SZ(s)) {
    node = GetNodeMove(node, s[i] - '0');
  }
  return node;
}
bool CompareNodes(int L, int R) {
  if (R == -1) { return true; }
  //if (L == 9 && R == 6) { debug(nodes[L].dep, nodes[R].dep); }
  if (nodes[L].dep != nodes[R].dep) { return nodes[L].dep < nodes[R].dep; }
  //int db = (L == 9 && R == 6);
  FORD (bit, SZ(nodes[L].jumps) - 1, 0) {
    if (SZ(nodes[L].jumps) <= bit) { continue; }
    //debug(bit, nodes
    if (nodes[L].jumps[bit] != nodes[R].jumps[bit]) {
      L = nodes[L].jumps[bit];
      R = nodes[R].jumps[bit];
    }
  }
//   if (db) {
//     debug(L, R, nodes[L].par_dig, nodes[R].par_dig, nodes[L].dep);
//   }
  return nodes[L].par_dig < nodes[R].par_dig;
}
const int N = 1e6 + 5;
int ind_node[N];
struct CompareInts {
  bool operator() (int L, int R) {
    if (ind_node[L] == ind_node[R]) { return L < R; }
    return CompareNodes(ind_node[L], ind_node[R]);
  }
};
VPII slo[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    slo[a].PB({b, i});
    slo[b].PB({a, i});
  }
  RE (i, n) {
    ind_node[i] = -1;
  }
  ind_node[1] = 0;
  nodes.PB({0, -1, 0, {}, {}});
  set<int, CompareInts> que;
  que.insert(1);
  while (!que.empty()) {
    int guy = *que.begin();
    debug(guy);
    que.erase(que.begin());
    for (auto e : slo[guy]) {
      int nei = e.st;
      int e_ind = e.nd;
      int cand = GetNodeByPath(ind_node[guy], e_ind);
      debug(guy, nei, cand);
      int cmp = CompareNodes(cand, ind_node[nei]);
//       if (ind_node[nei] != -1) {
//         debug(nodes[cand].rem, nodes[ind_node[nei]].rem, cmp, cand, ind_node[nei]);
//       }
      if (cmp) {
        que.erase(nei);
        ind_node[nei] = cand;
        que.insert(nei);
      }
    }
  }
  RE (i, n) {
    debug(i, ind_node[i]);
  }
  FOR (i, 2, n) {
    if (ind_node[i] == -1) { cout<<"-1\n"; continue; }
    cout<<nodes[ind_node[i]].rem<<"\n";
  }
    

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}