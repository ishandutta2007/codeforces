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

const int N = 3e3 + 5;
int dist[N][N];
vector<int> slo[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  RE (i, m) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  make3(int, s1, t1, l1);
  make3(int, s2, t2, l2);
  
  RE (i, n) {
    RE (j, n) {
      dist[i][j] = N;
    }
    VI que{i};
    dist[i][i] = 0;
    for (int ii = 0; ii < SZ(que); ii++) {
      int v = que[ii];
      for (auto nei : slo[v]) {
        if (dist[i][nei] == N) {
          dist[i][nei] = dist[i][v] + 1;
          que.PB(nei);
        }
      }
    }
//     RE (j, n) {
//       cerr<<dist[i][j]<<" ";
//     }
//     cerr<<"\n";
  }
  
  if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
    cout<<"-1\n";
    return 0;
  }
   
  int best = dist[s1][t1] + dist[s2][t2];
  RE (u, n) {
    RE (v, n) {
      if (dist[s1][u] + dist[u][v] + dist[v][t1] <= l1 &&
          dist[s2][u] + dist[u][v] + dist[v][t2] <= l2) {
//         int cand = dist[s1][u] + dist[u][v] + dist[v][t1] + dist[s2][u] + dist[v][t2];
//         if (cand < best) {
//           debug3(u, v, cand);
//         }
        mini(best, dist[s1][u] + dist[u][v] + dist[v][t1] + dist[s2][u] + dist[v][t2]);
      }
      if (dist[s1][u] + dist[u][v] + dist[v][t1] <= l1 &&
          dist[s2][v] + dist[u][v] + dist[u][t2] <= l2) {
        mini(best, dist[s1][u] + dist[u][v] + dist[v][t1] + dist[s2][v] + dist[u][t2]);
      }
    }
  }
  cout<<m - best<<"\n";
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}