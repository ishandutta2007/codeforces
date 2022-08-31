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

struct Dinic {
  struct Edge {
    int v, c, inv;
  };
  
public:
  Dinic() {
    n = -1;
  }  
  
  void AddEdge(int a, int b, int cap, int bi_dir) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e_orig[a].PB(Edge{b, cap, SZ(e_orig[b])});
    e_orig[b].PB(Edge{a, bi_dir * cap, SZ(e_orig[a]) - 1});
  }
  
  int MaxFlow(int s, int t) {
    if (t > n || s > n) {
      n = max(s, t);
      ResizeVectors();
    }
    e = e_orig;
    int result = 0;
    while (Bfs(s, t)) {
      for (int i = 0; i <= n; i++) {
        beg[i] = 0;
      }
      result += Dfs(s, t, kInf);
    }
    return result;
  }
  
  vector<bool> MinCut(int s, int t) {
    assert(!Bfs(s, t));
    vector<bool> res(n + 1);
    for (int i = 0; i <= n; i++) { res[i] = (dis[i] <= n); }
    return res;
  }
  
  vector<PII> EdgeCut(int s, int t) {
    vector<bool> left_part = MinCut(s, t);
    vector<PII> cut;
    for (int v = 0; v <= n; v++) {
      for (auto edge : e_orig[v]) {
        if (edge.c != 0 && left_part[v] && !left_part[edge.v]) {
          cut.PB({v, edge.v});
        }
      }
    }
    return cut;
  }
  
  int n;
  vector<vector<Edge>> e_orig, e;
  VI dis, beg;
  
  bool Bfs(int s, int t) {
    for (int i = 0; i <= n; i++) {
      dis[i] = n + 1;
    }
    dis[s] = 0;
    VI que;
    que.push_back(s);
    for (int i = 0; i < SZ(que); i++) {
      int v = que[i];
      for (auto edge : e[v]) {
        int nei = edge.v;
        if (edge.c && dis[nei] > dis[v] + 1) {
          dis[nei] = dis[v] + 1;
          que.push_back(nei);
          if (nei == t) {
            return true;
          }
        }
      }
    }
    return false;
  }
  
  int Dfs(int v, int t, int min_cap) {
    int result = 0;
    if (v == t || min_cap == 0) {
      return min_cap;
    }
    for (int& i = beg[v]; i < SZ(e[v]); i++) {
      int nei = e[v][i].v;
      int c = e[v][i].c;
      if (dis[nei] == dis[v] + 1 && c > 0) {
        int flow_here = Dfs(nei, t, min(min_cap, c));
        result += flow_here;
        min_cap -= flow_here;
        e[v][i].c -= flow_here;
        e[nei][e[v][i].inv].c += flow_here;
      }
      if (min_cap == 0) {
        break;
      }
    }
    return result;
  }
  
  void ResizeVectors() {
    e_orig.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }
  
  #ifdef int
  static const int kInf = 1e18;
  #else
  static const int kInf = 1e9;
  #endif
  
};

struct Sol {
  void Test() {
    int n, m;
    cin>>n>>m;
    VI big;
    VI small;
    RE (i, n) {
      int x;
      cin>>x;
      if (3 * x <= m) {
        small.PB(x);
      } else {
        big.PB(x);
      }
    }
    Dinic gr;
    int s = n + 1, t = n + 2;
    REP (i, SZ(big)) {
      gr.AddEdge(s, i + 1, 1, 0);
      REP (j, SZ(small)) {
        if (big[i] % small[j] == 0 && 2 * big[i] + small[j] <= m) {
          gr.AddEdge(i + 1, SZ(big) + j + 1, 1, 0);
        }
      }
    }
    REP (j, SZ(small)) {
      gr.AddEdge(SZ(big) + j + 1, t, 1, 0);
    }
    int f = gr.MaxFlow(s, t);
    if (f != SZ(big)) {
      cout<<"-1\n";
      return;
    }
    cerr<<"SUCC"<<endl;
    VI used(SZ(small));
    VPII ans;
    REP (i, SZ(big)) {
      for (auto e : gr.e[i + 1]) {
        if (e.v > SZ(big) && e.c == 0) {
          ans.PB({2 * big[i] + small[e.v - SZ(big) - 1], big[i] + small[e.v - SZ(big) - 1]});
          used[e.v - SZ(big) - 1] = 1;
        }
      }
    }
    REP (j, SZ(small)) {
      if (!used[j]) {
        ans.PB({3 * small[j], 2 * small[j]});
      }
    }
    cout<<SZ(ans)<<"\n";
    for (auto a : ans) {
      cout<<a.st<<" "<<a.nd<<"\n";
    }
    
  }
  
  
};


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
    Sol sol;
    sol.Test();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}