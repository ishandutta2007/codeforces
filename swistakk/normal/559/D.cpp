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
const int N = 3e5 + 5;
LD P[N];
ll A[N];
int G[N];
LD W[N];
#undef int
int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  vector<PII> pts;
  P[0] = 1;
  RE (i, n) {
    make2(int, x, y);
    pts.PB({x, y});
    P[i] = P[i - 1] / 2.;
  }
  RE (i, n) {
    W[i] = P[i] * (1 - P[n - i]);
  }
  REP (i, n) {
    pts.PB(pts[i]);
  }
  pts.PB(pts[0]);
  LD inint = 0;
  {
    LD area = 0;
    ll bord = 0;
    for (int i = 1; i <= n; i++) {
      int dx = (pts[i].st - pts[i - 1].st);
      int dy = (pts[i].nd - pts[i - 1].nd);
      area -= 1ll * dx * (pts[i].nd + pts[i - 1].nd) / 2.;
      bord += abs(__gcd(dx, dy));
    }
    debug2(area, bord);
    inint = area - bord / 2. + 1;
  }
  for (int j = 1; j <= 2 * n; j++) {
    int dx = (pts[j].st - pts[j - 1].st);
    int dy = (pts[j].nd - pts[j - 1].nd);
    A[j] -= 1ll * dx * (pts[j].nd + pts[j - 1].nd);
    G[j] = abs(__gcd(dx, dy));
  }
  LD rat = (1. - n * (n - 1) / pow(2, n + 1) - (n + 1) / pow(2, n));
  inint *= rat;
  cerr<<inint<<endl;
  RE (i, n) {
    LD area = 0;
    ll bord = 0;
    FOR (j, i + 1, min(i + 120, i + n - 2)) {
      int d = j - i;;
      area += A[j];
      bord += G[j];
      int dx = (pts[i].st - pts[j].st);
      int dy = (pts[i].nd - pts[j].nd);
      ll area_here = area - 1ll * dx * (pts[i].nd + pts[j].nd);
      int zonk = abs(__gcd(dx, dy));
      ll bord_here = bord + zonk;
      ll strata = ((area_here - bord_here) / 2 + zonk); 
      inint -= strata * W[d + 1];
      debug3(i, j, strata);
      //inint += (zonk - 1) * pow(2, -n);
    }
  }
//   if (n <= 1000) {
//     for (int i = 1; i <= n; i++) {
//       FOR (j, i + 2, i + n - 2) {
//         int dx = (pts[i].st - pts[j].st);
//         int dy = (pts[i].nd - pts[j].nd);
//         inint += (abs(__gcd(dx, dy)) - 1) * pow(2, -n - 1);
//       }
//     }
//   }
  
  debug(inint);
  inint /= rat;
  cout<<inint<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}