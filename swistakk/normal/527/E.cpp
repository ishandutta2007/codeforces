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
typedef vector<VI> VVI;
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

// struct Edge {
//   int v, c, inv;
//   Edge(int v_, int c_, int inv_) {
//     v = v_;
//     c = c_;
//     inv = inv_;
//   }
// };
//  
// struct Dinic {
//  
// public:
//   
//   Dinic() {
//     n = -1;
//   }  
//   
//   void AddEdge(int a, int b, int cap, int bi_dir = 0) {
//     if (n < max(a, b)) {
//       n = max(n, max(a, b));
//       ResizeVectors();
//     }
//     e_orig[a].push_back(Edge(b, cap, SZ(e_orig[b])));
//     e_orig[b].push_back(Edge(a, bi_dir * cap, SZ(e_orig[a]) - 1));
//   }
//   
//   int MaxFlow(int s, int t) {
//     e = e_orig;
//     int result = 0;
//     while (Bfs(s, t)) {
//       for (int i = 0; i <= n; i++) {
//         beg[i] = 0;
//       }
//       result += Dfs(s, t, kInf);
//     }
//     return result;
//   }
//   
// private:
//   int n;
//   vector<vector<Edge> > e_orig;
//   vector<vector<Edge> > e;
//   vector<int> beg;
//   vector<int> dis;
//   
//   bool Bfs(int s, int t) {
//     for (int i = 0; i <= n; i++) {
//       dis[i] = n + 1;
//     }
//     dis[s] = 0;
//     vector<int> que;
//     que.push_back(s);
//     for (int i = 0; i < SZ(que); i++) {
//       int v = que[i];
//       for (int j = 0; j < SZ(e[v]); j++) {
//         int nei = e[v][j].v;
//         if (e[v][j].c && dis[nei] > dis[v] + 1) {
//           dis[nei] = dis[v] + 1;
//           que.push_back(nei);
//           if (nei == t) {
//             return true;
//           }
//         }
//       }
//     }
//     return false;
//   }
//   
//   int Dfs(int v, int t, int min_cap) {
//     //cerr<<"v: "<<v<<endl;
//     int result = 0;
//     if (v == t || min_cap == 0) {
//       //cerr<<"min_cap: "<<min_cap<<endl;
//       return min_cap;
//     }
//     for (int& i = beg[v]; i < SZ(e[v]); i++) {
//       int nei = e[v][i].v;
//       int c = e[v][i].c;
//       if (dis[nei] == dis[v] + 1 && c > 0) {
//         int flow_here = Dfs(nei, t, min(min_cap, c));
//         result += flow_here;
//         min_cap -= flow_here;
//         e[v][i].c -= flow_here;
//         e[nei][e[v][i].inv].c += flow_here;
//       }
//       if (min_cap == 0) {
//         break;
//       }
//     }
//     return result;
//   }
//   
//   void ResizeVectors() {
//     e_orig.resize(n + 2);
//     beg.resize(n + 2);
//     dis.resize(n + 2);
//   }
//   
// #ifdef int
//   static const int kInf = 1e18;
// #else
//   static const int kInf = 1e9;
// #endif
//   
// };
// Dinic gr;
// void AddEdge(int a, int b) {
//   out[a]++;
//   gr.AddEdge(a, b);
// }
struct Edge {
  int a, inv, used;
};
const int N = 1e5 + 5;
vector<Edge> slo[N];
void AddEdge(int a, int b) {
  debug2(a, b);
  int inv1 = SZ(slo[b]);
  int inv2 = SZ(slo[a]);
  if (a == b) {
    inv1++;
  }
  slo[a].PB(Edge{b, inv1, 0});
  slo[b].PB(Edge{a, inv2, 0});
}
VI ans;
int deg[N];
int beg[N];
void Euler(int v) {
  debug(v);
  for (int& ii = beg[v]; ii < SZ(slo[v]); ) {
    Edge& e = slo[v][ii];
    int nei = e.a;
    ii++;
    if (e.used) { continue; }
    assert(slo[nei][e.inv].used == 0);
    slo[nei][e.inv].used = 1;
    Euler(nei);
    ans.PB(nei);
  }
    
//   while(!slo[v].empty())
//   {
//     aktv=*slo[v].begin();
//     slo[v].erase(aktv);
//     slo[aktv].erase(v);
//     Euler(aktv);
//     wynik[licz].push_back(v);
//   }
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  RE (i, m) {
    make2(int, a, b);
    deg[a]++;
    deg[b]++;
    AddEdge(a, b);
    
  }
  int prev = 0;
  RE (i, n) {
    if (deg[i] % 2 == 1) {
      if (prev) {
        AddEdge(i, prev);
        prev = 0;
        m++;
      } else {
        prev = i;
      }
    }
  }
  if (m % 2 == 1) {
    AddEdge(1, 1);
  }
  Euler(1);
  RE (i, n) {
    REP (j, SZ(slo[i])) {
      cerr<<slo[i][j].used<<" ";
    }
    cerr<<"\n";
  }
  cout<<SZ(ans)<<"\n";
  ans.PB(ans[0]);

  for (int i = 0; i < SZ(ans) - 1; i++) {
    if (i % 2) {
      cout<<ans[i]<<" "<<ans[i + 1]<<"\n";
    } else {
      cout<<ans[i + 1]<<" "<<ans[i]<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}