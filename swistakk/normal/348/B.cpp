#include <bits/stdc++.h>
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
using std::bitset;
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

const int INF = 1e9;
const int N = 1e5 + 5;
int sum, hehson;
vector<int> slo[N];
int prod_down[N];
int sum_app;
int nwd(int a, int b) {
  if (b == 0) return a;
  return nwd(b, a % b);
}
int nww(int a, int b) {
  return a * b / nwd(a, b);
}
int a[N];
void Exit() {
  cout<<sum_app<<endl;
  exit(0);
}
void dfs1(int v, int p) {
  prod_down[v] = 1;
  int ch = 0;
  for (auto nei : slo[v]) {
    ch += (nei != p);
  }
  for (auto nei : slo[v]) {
    if (nei == p) {
      continue;
    }
    dfs1(nei, v);
    prod_down[v] = nww(prod_down[v], prod_down[nei]);
    if (prod_down[v] > INF) {
      Exit();
    }
  }
  prod_down[v] *= max(1ll, ch);
}
void dfs2(int v, int p, int prod) {
  int ch = 0;
  for (auto nei : slo[v]) {
    ch += (nei != p);
  }
  if (ch == 0) {
    mini(hehson, a[v] / prod);
    sum += prod;
    //TODO 
    
  }
  for (auto nei : slo[v]) {
    if (nei == p) {
      continue;
    }
    dfs2(nei, v, prod / ch);
  }
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  sum_app = 0;
  RE (i, n) {
    cin>>a[i];
    sum_app += a[i];
  }
  RE (i, n - 1) {
    make2(int, x, y);
    slo[x].PB(y);
    slo[y].PB(x);
  }
  hehson = INF;
  dfs1(1, -1);
  dfs2(1, -1, prod_down[1]);
  cout<<sum_app - hehson * sum<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}