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
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

struct Edge {
  int v, c, inv;
  Edge(int v_, int c_, int inv_) {
    v = v_;
    c = c_;
    inv = inv_;
  }
};
 
struct Dinic {
 
public:
  
  Dinic() {
    n = -1;
  }  
  
  void AddEdge(int a, int b, int cap, int bi_dir = 0) {
    if (n < max(a, b)) {
      n = max(n, max(a, b));
      ResizeVectors();
    }
    e_orig[a].push_back(Edge(b, cap, SZ(e_orig[b])));
    e_orig[b].push_back(Edge(a, bi_dir * cap, SZ(e_orig[a]) - 1));
  }
  
  int MaxFlow(int s, int t) {
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
  
private:
  int n;
  vector<vector<Edge> > e_orig;
  vector<vector<Edge> > e;
  vector<int> beg;
  vector<int> dis;
  
  bool Bfs(int s, int t) {
    for (int i = 0; i <= n; i++) {
      dis[i] = n + 1;
    }
    dis[s] = 0;
    vector<int> que;
    que.push_back(s);
    for (int i = 0; i < SZ(que); i++) {
      int v = que[i];
      for (int j = 0; j < SZ(e[v]); j++) {
        int nei = e[v][j].v;
        if (e[v][j].c && dis[nei] > dis[v] + 1) {
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
    //cerr<<"v: "<<v<<endl;
    int result = 0;
    if (v == t || min_cap == 0) {
      //cerr<<"min_cap: "<<min_cap<<endl;
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
const int N = 222;
int val[N];//[2];
const int R = 1e6 + 5;
int sieve[R];
int adj[N][2];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  RE (i, n) {
    cin>>val[i];
    //cin>>val[(i + 1) / 2][(i - 1) % 2];
  }
  RE (i, m) {
    REP (tr, 2) {
      cin>>adj[i][tr];
      //adj[i][tr] = (adj[i][tr] + 1) / 2;
    }
    if (adj[i][0] % 2 == 0) {
      swap(adj[i][0], adj[i][1]);
    }
  }
  set<int> pr;
  RE (i, n) {
    int tmp = val[i];
    for (int j = 2; j * j <= tmp; j++) {
      while (tmp % j == 0) {
        tmp /= j;
        pr.insert(j);
      }
    }
    if (tmp > 1) {
      pr.insert(tmp);
    }
  }
  int res = 0;
  for (auto p : pr) {
    debug(p);
    Dinic gr;
    int s = 0;
    int t = n + 1;
    RE (i, n) {
      int ex = 0;
      while (val[i] % p == 0) {
        val[i] /= p;
        ex++;
      }
      if (ex) {
        if (i % 2 == 1) {
          gr.AddEdge(s, i, ex);
        } else {
          gr.AddEdge(i, t, ex);
        }
      }
    }
    RE (i, m) {
      gr.AddEdge(adj[i][0], adj[i][1], 30);
    }
    res += gr.MaxFlow(s, t);
  }
  cout<<res<<endl;
    
    
//   for (int i = 2; i < R; i++) {
//     if (sieve[i] == 0) {
//       for (int j
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}