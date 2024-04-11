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

struct Euler {
  struct Edge {
    int nei, nr;
  };
  vector<vector<Edge>> slo;
  vector<int> ans, used, deg, beg;
  int e_num, n;
  Euler() : e_num(0), n(0) {}
  void AddEdge(int a, int b) {
    e_num++;
    if (a > n || b > n) {
      n = max(a, b);
      slo.resize(n + 2);
      deg.resize(n + 2);
      beg.resize(n + 2);
    }
    used.PB(0);
    slo[a].PB({b, e_num});
    slo[b].PB({a, e_num});
    deg[a]++;
    deg[b]++;
  }
  vector<int> FindEuler() { // if used many times, please clear ans, beg, used
    used.PB(0);
    assert(SZ(used) > e_num);
    RE (i, n) {
      if (deg[i] % 2 == 1) {
        return vector<int>();
      }
    }
    Go(1);
    return ans;
  }
private:
  void Go(int v) {
    debug(v);
    while (beg[v] < SZ(slo[v])) {
      Edge& e = slo[v][beg[v]];
      beg[v]++;
      int nei = e.nei;
      if (used[e.nr]) { continue; }
      used[e.nr] = 1;
      Go(nei);
      ans.PB(nei);
    }
  }
};
const int N = 1e5 + 5;
int deg[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  Euler eu;
  make2(int, n, m);
  RE (i, m) {
    make2(int, a, b);
    deg[a]++;
    deg[b]++;
    eu.AddEdge(a, b);
  }
  int prev = 0;
  RE (i, n) {
    if (deg[i] % 2 == 1) {
      if (prev) {
        eu.AddEdge(i, prev);
        prev = 0;
        m++;
      } else {
        prev = i;
      }
    }
  }
  if (m % 2 == 1) {
    eu.AddEdge(1, 1);
  }
  VI ans = eu.FindEuler();
  cout<<SZ(ans)<<"\n";
  ans.PB(ans[0]);
  for (int i = 0; i < SZ(ans) - 1; i++) {
    cout<<ans[i + (i + 1) % 2]<<" "<<ans[i + i % 2]<<"\n";
  }
  return 0;
}