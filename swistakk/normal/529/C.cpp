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

const int N = 2e5 + 5;
const int M = 1 << 18;
int res[N];
int xx[N];
int yy[N];
int x1[N], x2[N], yy1[N], y2[N];
VI drz;
struct Ev {
  int type, nr;
};
bool Cmp1(Ev a, Ev b) {
  int ay, by;
  if (a.type == 0) {
    ay = yy[a.nr];
  } else {
    ay = y2[a.nr];
  }
  if (b.type == 0) {
    by = yy[b.nr];
  } else {
    by = y2[b.nr];
  }
  if (ay != by) return ay < by;
  return a.type < b.type;
}
// bool Cmp2(Ev a, Ev b) {
//   int ax, bx;
//   if (a.type == 0) {
//     ax = xx[a.nr];
//   } else {
//     ax = x2[a.nr];
//   }
//   if (b.type == 0) {
//     bx = xx[b.nr];
//   } else {
//     bx = x2[b.nr];
//   }
//   if (ax != bx) return ax < bx;
//   return a.type < b.type;
// }
void Update(int a, int val) {
  a += M - 1;
  drz[a] = val;
  a /= 2;
  while (a) {
    drz[a] = min(drz[2 * a], drz[2 * a + 1]);
    a /= 2;
  }
}
int Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  int m = min(drz[a], drz[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(m, drz[a + 1]);
    }
    if (b % 2 == 1) {
      mini(m, drz[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return m;
}
void Test(vector<Ev> vec) {
  drz.clear();
  drz.resize(2 * M + 5);;
  for (auto e : vec) {
    if (e.type == 0) {
      Update(xx[e.nr], yy[e.nr]);
    } else {
      int lowest = Read(x1[e.nr], x2[e.nr]);
      if (lowest >= yy1[e.nr]) {
        res[e.nr] = 1;
      }
    }
  }
}
      
  
  
  
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make4(int, n, m, k, q);
  vector<Ev> evs;
  RE (i, k) {
    cin>>xx[i]>>yy[i];
    evs.PB({0, i});
  }
  RE (i, q) {
    evs.PB({1, i});
    cin>>x1[i]>>yy1[i]>>x2[i]>>y2[i];
  }
  sort(ALL(evs), Cmp1);
  Test(evs);
  RE (i, k) {
    swap(xx[i], yy[i]);
  }
  RE (i, q) {
    swap(x1[i], yy1[i]);
    swap(x2[i], y2[i]);
  }
  sort(ALL(evs), Cmp1);
  Test(evs);
  RE (i, q) {
    if (res[i]) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}