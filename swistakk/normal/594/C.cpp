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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
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
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
struct Magnet {
  int x, y;//, x2, y2;
};
const int N = 1e5 + 5;
Magnet mag[N];
bool Left(int a, int b) {
  return mag[a].x < mag[b].x;
}
bool Right(int a, int b) {
  return mag[a].x > mag[b].x;
}
bool Up(int a, int b) {
  return mag[a].y > mag[b].y;
}
bool Down(int a, int b) {
  return mag[a].y < mag[b].y;
}
int got[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, k);
  VI down, left, right, up;
  RE (i, n) {
    make4(int, x1, y1, x2, y2);
    mag[i] = {x1 + x2, y1 + y2};
    down.PB(i);
    left.PB(i);
    right.PB(i);
    up.PB(i);
  }
  sort(ALL(left), Left);
  sort(ALL(up), Up);
  sort(ALL(right), Right);
  sort(ALL(down), Down);
  debugv(left);
  debugv(up);
  debugv(right);
  debugv(down);
  
  
  
  int res = 1e18;
  FOR (l, 0, k) {
    FOR (r, 0, k) {
      FOR (u, 0, k) {
        FOR (d, 0, k) {
          int maxx, maxy, minx, miny;
          VI zaj;
          int h = 0, pall = 0;
          REP (h, l) {
            if (!got[left[h]]) {
              zaj.PB(left[h]);
              got[left[h]] = 1; 
            }
          }
          REP (h, r) {
            if (!got[right[h]]) {
              zaj.PB(right[h]);
              
              got[right[h]] = 1; 
            }
          }REP (h, u) {
            if (!got[up[h]]) {
              zaj.PB(up[h]);
              
              got[up[h]] = 1; 
            }
          }REP (h, d) {
            if (!got[down[h]]) {
              zaj.PB(down[h]);
              got[down[h]] = 1; 
            }
          }
          maxx = mag[right[r]].x;
          minx = mag[left[l]].x;
          maxy = mag[up[u]].y;
          miny = mag[down[d]].y;
          int dx = maxx - minx;
          dx += dx % 2;
          if (dx == 0) {
            dx = 2;
          }
          int dy = maxy - miny;
          dy += dy % 2;
          if (dy == 0) {
            dy = 2;
          }
          debug(minx, maxx, miny, maxy, dx, dy);
          if (SZ(zaj) <= k) {
            mini(res, dx * dy / 4);
          }
          for (auto x : zaj) {
            got[x] = 0;
          }
          debug(l, r, u, d);
          debugv(zaj);
        }
      }
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}