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
//int forb;
struct Dinic {
  struct Edge {
    int v, c, inv;
  };
  
public:
  Dinic() {
    n = -1;
  }  
  
  void AddEdge(int a, int b, int cap, int bi_dir = 0) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e[a].PB(Edge{b, cap, SZ(e[b])});
    e[b].PB(Edge{a, bi_dir * cap, SZ(e[a]) - 1});
  }
  
  int MaxFlow(int s, int t) {
    if (t > n || s > n) {
      n = max(s, t);
      ResizeVectors();
    }
    //e = e_orig;
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
      for (auto edge : e[v]) {
        if (edge.c != 0 && left_part[v] && !left_part[edge.v]) {
          cut.PB({v, edge.v});
        }
      }
    }
    return cut;
  }
  
  int n;
  vector<vector<Edge>> e;
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
    e.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }
  
#ifdef int
  static const int kInf = 1e18;
#else
  static const int kInf = 1e9;
#endif
  
};
    
const int N = 5e5 + 5;
const int kInf = 1e12;
int x_deg[N], y_deg[N];
int min_d_x[N], min_d_y[N];
int x[N], y[N];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  int R, B;
  cin>>R>>B;
  map<int, int> vals;
  RE (i, n) {
    cin>>x[i]>>y[i];
    vals[x[i]]++;
    vals[y[i]]++;
  }
  int cnt = 0;
  for (auto& p : vals) {
    cnt++;
    p.nd = cnt;
  }
  RE (i, n) {
    x[i] = vals[x[i]];
    x_deg[x[i]]++;
    min_d_x[x[i]] = x_deg[x[i]];
    y[i] = vals[y[i]];
    y_deg[y[i]]++;
    min_d_y[y[i]] = y_deg[y[i]];
  }
  RE (i, m) {
    int t, l, d;
    cin>>t>>l>>d;
    l = vals[l];
    if (t == 1) {
      mini(min_d_x[l], d);
    } else {
      mini(min_d_y[l], d);
    }
  }
  Dinic gr;
  int s1 = 4 * n + 2;
  int t1 = s1 + 1;
  int s2 = t1 + 1;
  int t2 = s2 + 1;
  int D = 0;
  RE (i, 2 * n) {
    int a = (x_deg[i] - min_d_x[i] + 1) / 2;
    int b = (x_deg[i] + min_d_x[i]) / 2;
    if (a > b) {
      cout<<"-1\n";
      return 0;
    }
    if (a) {
      gr.AddEdge(s2, i, a);
      gr.AddEdge(s1, t2, a);
      debug(i, a, b);
      D += a;
    }
    if (b - a) {
      gr.AddEdge(s1, i, b - a);
    }
  }
  RE (i, 2 * n) {
    int a = (y_deg[i] - min_d_y[i] + 1) / 2;
    int b = (y_deg[i] + min_d_y[i]) / 2;
    if (a > b) {
      cout<<"-1\n";
      return 0;
    }
    if (a) {
      gr.AddEdge(2 * n + i, t2, a);
      gr.AddEdge(s2, t1, a);
      D += a;
    }
    if (b - a) {
      gr.AddEdge(2 * n + i, t1, b - a);
    }
  }
  RE (i, n) {
    gr.AddEdge(x[i], 2 * n + y[i], 1);
  }
  gr.AddEdge(t1, s1, kInf);
  debug(gr.e[t1].back().c);
  int flow1 = gr.MaxFlow(s2, t2);
  assert(flow1 == D);
  int res = kInf - gr.e[t1].back().c;
  debug(gr.e[t1].back().c);
  debug(res);
  //forb = t1;
  res = gr.MaxFlow(s1, t1);
  debug(res);
  assert(res <= n);
  cout<<min(R, B) * res + max(R, B) * (n - res)<<endl;
  map<PII, VI> anses;
  RE (i, 2 * n) {
    for (auto edge : gr.e[i]) {
      if (edge.v >= 2 * n + 1 && edge.v <= 4 * n) {
        anses[{i, edge.v - 2 * n}].PB(edge.c);
      }
    }
  }
  vector<char> ch;
  ch.PB('r');
  ch.PB('b');
  if (R > B) {
    swap(ch[0], ch[1]);
  }
  RE (i, n) {
    auto& v = anses[{x[i], y[i]}];
    int c = v.back();
    cout<<ch[c];
    v.pop_back();
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}