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

pair<int, int> Solve(int x1, int x2, int a, int b) {
  if (x2 >= x1 + a && x2 <= x1 + b) {
    return MP(1, x2);
  }
  if (a <= 0) {
    return MP(0, 0);
  }
  int r = (x2 - x1) % (a + b);
  if (a <= r && r <= b) {
    return MP(1, x1 + r);
  } else if ((x2 - x1) % (a + b) == 0) {
    return MP(2, 0);
  } else {
    return MP(0, 0);
  }
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make4(int, x1, x2, a, b);
  if (x1 < x2) {
    auto p = Solve(x1, x2, a, b);
    if (p.st == 1) {
      cout<<"FIRST\n"<<p.nd<<"\n";
    } else if (p.st == 2) {
      cout<<"SECOND\n";
    } else {
      cout<<"DRAW\n";
    }
  } else {
    auto p = Solve(x2, x1, -b, -a);
    if (p.st == 1) {
      cout<<"FIRST\n"<<x1 + x2 - p.nd<<"\n";
    } else if (p.st == 2) {
      cout<<"SECOND\n";
    } else {
      cout<<"DRAW\n";
    }
  }
  
  
  
  
  
//   if ((x1 <= x2 && a + b <= 0) || (x1 >= x2 && a + b >= 0)) {
//     if (x2 >= x1 + a && x2 <= x1 + b) {
//       cout<<"FIRST\n"<<x2<<"\n";
//     } else {
//       cout<<"DRAW\n";
//     }
//     return 0;
//   }
//   if (abs(x2 - x1) % (a + b) == 0) {
//     cout<<"SECOND\n";
//     return 0;
//   }
//   cout<<"FIRST\n";
//   int S = a + b;
//   int st = x1 + a;
//   int res = st % S;
//   if (res < 0) {
//     res += S;
//   }
//   cout<<st + S - res<<endl;
//   assert(abs(x2 - (st + S - res)) % S == 0);
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}