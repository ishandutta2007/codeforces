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
  bool operator<(const Point& oth) {
    if (y != oth.y) { return y < oth.y; }
    return x < oth.x;
  }
  Point operator-(Point p) {
    return {x - p.x, y - p.y, -1};
  }
  int CrossProd(Point A) {
    return x * A.y - y * A.x;
  }
  friend ostream& operator<<(ostream& out, Point p) {
    return out<<"("<<p.x<<", "<<p.y<<", "<<p.ind<<")";
  }
};
const int N = 2e3 + 5;
Point pts[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, S;
  cin>>n>>S;
  S *= 2;
  RE (i, n) {
    int x, y;
    cin>>x>>y;
    pts[i] = {x, y, i};
  }
  sort(pts + 1, pts + n + 1);
  vector<pair<Point, PII>> dirs;
  RE (i, n) {
    FOR (j, i + 1, n) {
      Point dir = pts[j] - pts[i];
      dirs.PB({dir, {pts[i].ind, pts[j].ind}});
    }
  }    
  sort(ALL(dirs), [&](pair<Point, PII> A, pair<Point, PII> B) {
    return A.st.CrossProd(B.st) > 0;
  });
  VI wh(n + 2);
  RE (i, n) {
    wh[pts[i].ind] = i;
  }
  debug(dirs);
  RE (i, n) {
    debug(pts[i], wh[i]);
  }
  for (auto L : dirs) {
    int sm = L.nd.st;
    int gr = L.nd.nd;
    int kl = 1, kp = n;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      int cr = (pts[wh[gr]] - pts[wh[sm]]).CrossProd(pts[aktc] - pts[wh[sm]]);
      if (cr == S) {
        cout<<"Yes\n";
        vector<Point> inds{pts[wh[sm]], pts[wh[gr]], pts[aktc]};
        for (auto p : inds) {
          cout<<p.x<<" "<<p.y<<endl;
        }
        //cout<<sm<<" "<<gr<<" "<<pts[aktc].ind<<endl;
        return 0;
      }
      if (cr < S) {
        kl = aktc + 1;
      } else {
        kp = aktc - 1;
      }
    }
    
    swap(pts[wh[sm]], pts[wh[gr]]);
    assert(wh[sm] + 1 == wh[gr]);
    swap(wh[sm], wh[gr]);
  }
  cout<<"No\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}