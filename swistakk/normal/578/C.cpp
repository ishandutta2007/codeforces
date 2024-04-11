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

const int kInf = 2e9 + 5;
const int N = 2e5 + 5;
const LD kEps = 1e-7;
int a[N];
int n;
LD Get(LD x) {
  LD mi = 0, ma = 0;
  LD sum = 0;
  LD res = 0;
  RE (i, n) {
    sum += a[i] - x;
    //debug2(sum - mi, ma - sum);
    maxi(res, max(sum - mi, ma - sum));
    maxi(ma, sum);
    mini(mi, sum);
  }
  debug(res);
  return res;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    cin>>a[i];
    //make(int, a);
    //pref[i] = pref[i - 1] + a;
  }
  Get(2);
  double kl = -kInf, kp = kInf, faj = kInf;
  REP (tr, 120) {
    LD a1 = (2 * kl + kp) / 3;
    LD a2 = (kl + 2 * kp) / 3;
    LD b1 = Get(a1), b2 = Get(a2);
    if (b1 > b2) {
      kl = a1;
    } else {
      kp = a2;
    }
  }
  debug2(kl, kp);
  cout<<Get(kl)<<endl;
//   double kl = 0, kp = kInf, faj = kp;
//   REP (tr, 70) {
//     LD aktc = (kl + kp) / 2;
//     LD min_x = -kInf, max_x = kInf;
//     RE (i, n) {
//       LD ang1 = (pref[i] - aktc) / i;
//       LD ang2 = (pref[i] + aktc) / i;
//       maxi(min_x, ang1);
//       mini(max_x, ang2);
//     }
//     if (min_x < max_x + kEps) {
//       faj = aktc;
//       kp = aktc;
//     } else {
//       kl = aktc;
//     }
//   }
//   cout<<faj<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}