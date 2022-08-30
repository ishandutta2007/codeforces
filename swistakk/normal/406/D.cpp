#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#include <complex>
#define MP make_pair
#define PB push_back
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PII;
typedef pair<ll, ll> PLL;
typedef vector<ll> VI;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

struct LCA {
  LCA(const vector<vector<int> >& their_slo, int root = 1) {
    M = 1;
    while (M <= 2 * their_slo.size()) {
      M *= 2;
    }
    my_slo.resize(M);
    REP (i, their_slo.size()) {
      for (auto nei : their_slo[i]) {
        my_slo[i].PB(nei);
      }
    }
    drz.resize(2 * M + 5);
    pre.resize(M);
    inv.resize(M);
    vis.resize(M);
    ind.resize(M);
    dep.resize(M);
    d=1;
    akt=1;
    dfs(root);
    for(int i=M-1; i>=1; i--)
    {
        drz[i]=min(drz[2*i], drz[2*i+1]);
    }
  }
  int M;
  vector<int> drz;
  vector<int> pre;
  vector<int> inv;
  vector<int> vis;
  vector<int> ind;
  vector<int> dep;
  vector<vector<int> > my_slo;
  int d;
  int akt;
  
  int Lca(int a, int b) // pobiera a i b, a zwraca ich lca (przy ukorzenieniu w jedynce (ale to mozna zmienic zapuszczajac skad inad dfsa) )
  {
      a=pre[a];
      b=pre[b];
      int w;
      w=czyt(min(ind[a], ind[b]), max(ind[a], ind[b]) );
      return inv[w];
  }
  
  int Dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[Lca(a, b)];
  }
  
private:
  int czyt(int a, int b)
  {
      a+=M-1;
      b+=M-1;
      int mini=M;
      mini=min(mini, drz[a]);
      mini=min(mini, drz[b]);
      while(a/2 != b/2)
      {
          if(a%2==0)
          {
              mini=min(mini, drz[a+1]);
          }
          if(b%2==1)
          {
              mini=min(mini, drz[b-1]);
          }
          a/=2;
          b/=2;
      }
      return mini;
  }
  void dfs(int v)
  {
    vis[v]=1;
    pre[v]=d;
    inv[d]=v;
    d++;
    drz[akt+M-1]=pre[v];
    ind[pre[v]]=akt;
    akt++;
    for (int nei : my_slo[v]) {
      if (vis[nei]) {
        continue;
      }
      dep[nei] = dep[v] + 1;
      dfs(nei);
      drz[akt+M-1]=pre[v];
      ind[pre[v]]=akt;
      akt++;
    }
  }
}; 

vector<vector<int> > slo;

struct Point {
  int y, x, id;
  Point(int y_, int x_, int id_) : y(y_), x(x_), id(id_) {};
  Point() : Point(0, 0, 0) {}
};

vector<Point> pts;

bool cmp(Point a, Point b) {
  return a.x > b.x;
}

int CrossProd(Point orig, Point a, Point b) {
  return (a.x - orig.x) * (b.y - orig.y) - (a.y - orig.y) * (b.x - orig.x);
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  slo.resize(n + 5);
  RE (i, n) {
    make2(int, x, y);
    pts.PB(Point(y, x, i));
  }
  
  sort(ALL(pts), cmp);
  vector<Point> oto;
  oto.PB(pts[0]);
  for (int i = 1; i < pts.size(); i++) {
    while (oto.size() > 1 && CrossProd(pts[i], oto.back(), oto[oto.size() - 2]) > 0) {
      oto.pop_back();
    }
    slo[pts[i].id].PB(oto.back().id);
    slo[oto.back().id].PB(pts[i].id);
    oto.PB(pts[i]);
  }
  
  LCA lca(slo, n);
  make(int, m);
  RE (i, m) {
    make2(int, a, b);
    cout<<lca.Lca(a, b)<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}