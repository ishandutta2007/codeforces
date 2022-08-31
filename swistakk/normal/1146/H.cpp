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
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

struct Point {
  int x, y;
  Point operator-(Point p) { return {x - p.x, y - p.y}; }
};

int CrossProd(Point A, Point B, Point C) {
  B = B - A;
  C = C - A;
  return B.x * C.y - B.y * C.x;
}

const int N = 313;
Point pt[N];
bool IsUnder(Point A, Point B, Point C) {
  if (A.x > B.x) { swap(A, B); }
  return C.x >= A.x && C.x < B.x && CrossProd(A, C, B) > 0;
}
int cnt[N][N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  RE (i, n) {
    int x, y;
    cin>>x>>y;
    pt[i] = {x, y};
  }
  
  RE (i, n) {
    RE (j, n) {
      if (i == j) { continue; }
      Point A = pt[i];
      Point B = pt[j];
      int sign = 1;
      if (A.x > B.x) {
        swap(A, B);
        sign = -1;
      }
      int under = 0;
      RE (k, n) {
        if (k == i || k == j) { continue; }
        under += IsUnder(A, B, pt[k]);
      }
      cnt[i][j] = sign * under;
    }
  }
  int T1 = 0, T2 = 0;
  RE (i, n) {
    RE (j, i - 1) {
      RE (k, j - 1) {
        int hehs = cnt[i][j] + cnt[j][k] + cnt[k][i];
        if (hehs < 0) {
          assert(CrossProd(pt[i], pt[j], pt[k]) > 0);
        }
        hehs = abs(hehs);
        hehs -= IsUnder(pt[i], pt[j], pt[k]);
        hehs -= IsUnder(pt[j], pt[k], pt[i]);
        hehs -= IsUnder(pt[k], pt[i], pt[j]);
        T1 += hehs;
        T2 += hehs * (hehs - 1) / 2;
      }
    }
  }
  int C = ((n - 4) * T1 - 4 * T2) / 2;
  debug(T1, T2, C);
  cout<<n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120 - T2 - C<<endl;
  
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}