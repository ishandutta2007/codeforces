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
const int M = 1e4 + 2;
PII pr[77];
LD AtMost(int wh, int val) {
  auto p = pr[wh];
  mini(val, p.nd);
  int len = p.nd - p.st + 1;
  maxi(val, p.st - 1);
  return 1. * (val - p.st + 1) / len;
}
LD AtLeast(int wh, int val) {
  return 1 - AtMost(wh, val - 1);
}
int Len(int wh) {
  return pr[wh].nd - pr[wh].st + 1;
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    make2(int, l, r);
    pr[i] = (MP(l, r));
  }
  LD ev = 0;
  
  FOR (sec, 1, M) {
    LD prob = 1;
    RE (who_sec, n) {
      auto& g2 = pr[who_sec];
      if (sec < g2.st || sec > g2.nd) { continue; }
      RE (who_win, n) {
        prob = 1. / Len(who_sec);
        if (who_sec == who_win) { continue; }
        prob *= AtLeast(who_win, sec + (who_win > who_sec));
        RE (oth, n) {
          if (oth == who_sec || oth == who_win) { continue; }
          prob *= AtMost(oth, sec - (oth < who_sec));
        }
        ev += prob * sec;
      }
    }
  }
  cout<<ev<<"\n";
          
          
          
//   RE (ii, n) {
//     auto p = prices[ii];
//     FOR (pric, p.st, p.nd) {
//       LD prob = 1. / (p.nd - p.st + 1);
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}