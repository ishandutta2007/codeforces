#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define int long long
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
};

struct Dinic {

public:
  
  Dinic(int n_) {
    n = n_;
    e_orig.resize(n + 2);
    beg.resize(n + 2);
    dis.resize(n + 2);
  }  
  
  void AddEdge(int a, int b, int cap, int bi_dir = 0) {
    e_orig[a].push_back(Edge{b, cap, SZ(e_orig[b])});
    e_orig[b].push_back(Edge{a, bi_dir * cap, SZ(e_orig[a]) - 1});
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
    vector<vector<Edge> > e_orig;
  vector<vector<Edge> > e;
  vector<int> beg;
  vector<int> dis;
private:
  int n;

  
  bool Bfs(int s, int t) {
    for (int i = 0; i <= n; i++) {
      dis[i] = n + 1;
    }
    dis[s] = 0;
    vector<int> que;
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
    if (v == t) {
      return min_cap;
    }
    for (int& i = beg[v]; i < SZ(e[v]); i++) {
      Edge& edge = e[v][i];
      int nei = edge.v;
      int c = edge.c;
      if (dis[nei] == dis[v] + 1 && c > 0) {
        int flow_here = Dfs(nei, t, min(min_cap, c));
        result += flow_here;
        min_cap -= flow_here;
        edge.c -= flow_here;
        e[nei][edge.inv].c += flow_here;
      }
      if (min_cap == 0) {
        break;
      }
    }
    return result;
  }
  
#ifdef int
  static const int kInf = 1e18;
#else
  static const int kInf = 1e9;
#endif
  
};

const int R = 1e5 + 5;
int sieve[R];
int fox[R];
int nxt[R];
int vis[R];
vector<int> slo[R];
void Dfs(int v, vector<int>& vec) {
  vec.PB(v);
  vis[v] = 1;
  for (int nei : slo[v]) {
    if (!vis[nei]) {
      Dfs(nei, vec);
    }
  }
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  for (int i = 2; i < R; i++) {
    if (sieve[i] == 0) {
      for (int j = 2; i * j < R; j++) {
        sieve[i * j] = 1;
      }
    }
  }
  vector<PII> vers[2];
  make(int, nn);
  RE (i, nn) {
    cin>>fox[i];
    vers[fox[i] % 2].PB(MP(i, fox[i]));
  }
  Dinic gr(500);
  int s = 0;
  int t = nn + 1;
  int n1 = SZ(vers[0]), n2 = SZ(vers[1]);
  REP (i, n1) {
    REP (j, n2) {
      if (sieve[vers[0][i].nd + vers[1][j].nd] == 0) {
        gr.AddEdge(vers[0][i].st, vers[1][j].st, 1);
        cerr<<fox[vers[0][i].st]<<" "<< fox[vers[1][j].st]<<endl;
      }
    }
  }
  REP (i, n1) {
    gr.AddEdge(s, vers[0][i].st, 2);
  }
  REP (j, n2) {
    gr.AddEdge(vers[1][j].st, t, 2);
  }
  int f = gr.MaxFlow(s, t);
  if (f == nn) {
    debug(f);
    cerr<<"YES\n";
    vector<vector<int>> res;
    RE (i, nn) {
      for (auto e : gr.e[i]) {
        if (e.c == 0 && e.v != t && fox[i] % 2 == 0) {
          slo[i].PB(e.v);
          slo[e.v].PB(i);
          cerr<<fox[i]<<" "<<fox[e.v]<<" from flow\n";
        }
      }
      cerr<<"\n";
    }
    RE (i, nn) {
      if (vis[i]) { continue; }
      vector<int> heh;
      Dfs(i, heh);
      res.PB(heh);
    }
    
    
    cout<<SZ(res)<<"\n";
    for (auto v : res) {
      cout<<SZ(v)<<" ";
      for (auto x : v) {
        cout<<x<<" ";
      }
      cout<<"\n";
      for (auto x : v) {
        cerr<<fox[x]<<" ";
      }
      cerr<<"\n";
    }
    
  } else {
    cout<<"Impossible\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}