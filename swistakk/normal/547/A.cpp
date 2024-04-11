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

int h[2], a[2], x[2], y[2];
int m;
const int M = 4e6 + 5;
void Apply(int tr) {
  h[tr] = (h[tr] * x[tr] + y[tr]) % m;
}
int cnt_occ[2];
int wh_occ[2][2];
int per[2];
int Bel(int tr, int v) {
  if (cnt_occ[tr] == 0) {
    return 0;
  }
  if (cnt_occ[tr] == 1) {
    return wh_occ[tr][0] == v;
  }
  if (v < wh_occ[tr][0]) {
    return 0;
  }
  return v % per[tr] == wh_occ[tr][0] % per[tr];
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>m;
  REP (tr, 2) {
    cin>>h[tr]>>a[tr]>>x[tr]>>y[tr];
  }
  REP (tr, 2) {
    for (int t = 0; t < M && cnt_occ[tr] != 2 ; t++) {
      if (h[tr] == a[tr]) {
        wh_occ[tr][cnt_occ[tr]] = t;
        cnt_occ[tr]++;
      }
      Apply(tr);
    }
  }
  if (cnt_occ[1] < cnt_occ[0]) {
    swap(cnt_occ[1], cnt_occ[0]);
    swap(wh_occ[0][0], wh_occ[1][0]);
    swap(wh_occ[0][1], wh_occ[1][1]);
  }
  if (cnt_occ[0] == 0) {
    cout<<"-1\n";
    return 0;
  }
  REP (tr, 2) {
    per[tr] = wh_occ[tr][1] - wh_occ[tr][0];
  }
  if (cnt_occ[0] == 1) {
    if (Bel(1, wh_occ[0][0])) {
      cout<<wh_occ[0][0]<<"\n";
      return 0;
    }
    cout<<"-1\n";
    return 0;
  }
  for (int i = 0; i < M; i++) {
    int t = wh_occ[0][0] + i * per[0];
    if (Bel(1, t)) {
      cout<<t<<"\n";
      return 0;
    }
  }
  cout<<"-1\n";
  return 0;
}