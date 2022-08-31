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
  int x, y, ind;
  static bool LexCmp(const Point& a, const Point& b) {
    if (a.x != b.x) {
      return a.x < b.x;
    }
    return a.y < b.y;
  }
  Point() {}
  Point(int a, int b, int c) : x(a), y(b), ind(c) {}
  Point(const Point& a) : x(a.x), y(a.y), ind(a.ind) {}
  void operator=(const Point& a) { x = a.x; y = a.y; ind = a.ind;}
  Point operator+(const Point& a) const { Point p(x + a.x, y + a.y, 0); return p; }
  Point operator-(const Point& a) const { Point p(x - a.x, y - a.y, 0); return p; }
  Point& operator+=(const Point& a) { x += a.x; y += a.y; return *this; }
  Point& operator-=(const Point& a) { x -= a.x; y -= a.y; return *this; }
  int CrossProd(const Point& a) const {
    return x * a.y - y * a.x;
  }
  int CrossProd(Point a, Point b) const {
    a -= *this;
    b -= *this;
    return a.CrossProd(b);
  }
  bool IsZero() {
    return x == 0 && y == 0;
  }friend ostream& operator<<(ostream& out, Point m);
};
ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.x << ", " << p.y << ", "<<p.ind<<")";
  return out;
}
// for square 34 
//            12 holds one_way_hull = {{1,3,4},{1,2,4}}
// resulting polygon is counterclockwise {1, 2, 4, 3}
vector<Point> MakeConvexHull(vector<Point> pts) { // tested everywhere http://codeforces.com/contest/333/submission/11058065
  vector<vector<Point>> one_way_hull(2);
  sort(pts.begin(), pts.end(), Point::LexCmp);
  for (int dir = -1; dir <= 1; dir += 2) {
    int hull_num = (dir + 1) / 2;
    auto& H = one_way_hull[hull_num];
    one_way_hull[hull_num].push_back(pts[0]);
    if (SZ(pts) > 1) {
      H.push_back(pts[1]);
    }
    for (int i = 2; i < SZ(pts); i++) {
      while (SZ(H) >= 2 &&
        dir * (pts[i] - H[SZ(H) - 2]).CrossProd(H.back() - H[SZ(H) - 2]) >= 0) {
        H.pop_back();
        }
        H.push_back(pts[i]);
    }
    if (SZ(H) > 1 && (H[0] - H.back()).IsZero()) { H.pop_back(); }
  }
  pts.clear();
  for (auto p : one_way_hull[1]) {
    pts.push_back(p);
  }
  for (int i = SZ(one_way_hull[0]) - 2; i >= 1; i--) {
    pts.push_back(one_way_hull[0][i]);
  }
  return pts;
  //return one_way_hull;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  

  int n;
  cin>>n;
  vector<Point> pts;
  RE (i, n) {
    int x, y;
    cin>>x>>y;
    pts.PB({x, y, i});
    debug(pts.back());
  }
  debug(pts);
  sort(ALL(pts), Point::LexCmp);
  debug(pts);
  vector<bool> alive(n + 1, 1);
  string s;
  cin>>s;
  Point cur = pts[0];
  vector<int> ans{cur.ind};
  alive[cur.ind] = 0;
  REP (i, n - 1) {
    vector<Point> to_hull;
    REP (j, n) {
      if (alive[pts[j].ind]) {
        debug(j);
        to_hull.PB(pts[j]);
      }
    }
    debug(to_hull);
    vector<Point> hull = MakeConvexHull(to_hull);
    Point nxt = hull[0];
    if (i == n - 2) {
      ans.PB(nxt.ind);
      break;
    }
    for (auto p : hull) {
      if (cur.CrossProd(p, nxt) > 0 && s[i] == 'L') {
        nxt = p;
      } else if (cur.CrossProd(nxt, p) > 0 && s[i] == 'R') {
        nxt = p;
      }
    }
    ans.PB(nxt.ind);
    alive[nxt.ind] = 0;
    cur = nxt;
  }
  for (auto x : ans) {
    cout<<x<<" ";
  }
  cout<<endl;
  
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}