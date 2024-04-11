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
const int N = 1e5 + 5;
vector<int> slo[N];
int is_path[N];
int is_lite[N];
int vis1[N], vis2[N], dep[N];
void dfs1(int v) {
  vis1[v] = 1;
  for (auto nei : slo[v]) {
    if (vis1[nei]) { continue; }
    dep[nei] = dep[v] + 1;
    dfs1(nei);
  }
  if (SZ(slo[v]) == 1) {
    is_path[v] = 1;
    is_lite[v] = 1;
    return;
  }
  if (SZ(slo[v]) == 2 && (is_path[slo[v][0]] || is_path[slo[v][1]])) {
    is_path[v] = 1;
    is_lite[v] = 1;
  }
  int sum_path = 0;
  for (auto nei : slo[v]) {
    sum_path += is_path[nei];
  }
  if (SZ(slo[v]) == 3 && sum_path == 2) {
    is_lite[v] = 1;
  }
}
int dfs2(int v) {
//   cout<<"lol?"<<endl;
  vis2[v] = 1;
  int how_many = 0;
  for (auto nei : slo[v]) {
    if (vis2[nei]) { continue; }
    how_many += dfs2(nei);
  }
//   cout<<v<<" how "<<how_many<<endl;
  if (how_many >= 2) {
    cout<<"No"<<endl;
    cerr<<"In dfs "<<v<<endl;;
    exit(0);
  }
  return (how_many | !is_lite[v]);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n - 1) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  if (n <= 2) {
//     cout<<"Tu3";
    cout<<"Yes\n";
    return 0;
  }
  int root = -1;
  RE (i, n) {
    if (SZ(slo[i]) >= 3) {
      root = i;
    }
  }
  if (root == -1) {
//     cout<<"Tu2";
    cout<<"Yes\n";
    return 0;
  }
  dep[root] = 1;
  dfs1(root);
  int wh = 0;
  RE (i, n) {
    debug3(i, is_path[i], is_lite[i]);
    if (!is_lite[i] && dep[i] > dep[wh]) {
      wh = i;
    }
  }
  debug(wh);
  if (wh == 0) {
//     cout<<"Tu1";
    cout<<"Yes\n";
    return 0;
  }
  dfs2(wh);
//   cout<<wh<<endl;
//   RE (i, n) {
//     cout<<i<<" "<<is_lite[i]<<endl;
//   }
//   cout<<"Tu4";
   cout<<"Yes\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}