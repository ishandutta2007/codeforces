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

struct Node {
  int suf, pref, inner, wid;
  Node() : suf(0), pref(0), inner(0), wid(0) {}
  Node(const Node& a) : suf(a.suf), pref(a.pref), inner(a.inner), wid(a.wid) {}
};
const int N = 2e5 + 10;
const int M = 1 << 18;
Node drz[2 * M + 5];
void Join(Node l, Node r, Node& p) {
  p.suf = max(r.suf, r.wid + l.suf);
  p.pref = max(l.pref, l.wid + r.pref);
  p.inner = max(max(l.inner, r.inner), l.suf + r.pref);
  p.wid = l.wid + r.wid;
}
int Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  Node left(drz[a]);
  Node right(drz[b]);
  debug2(left.wid, right.wid);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      Join(left, drz[a + 1], left);
    }
    if (b % 2 == 1) {
      Join(drz[b - 1], right, right);
    }
    a /= 2;
    b /= 2;
  }
  debug4(left.suf, left.pref, left.inner, left.wid);
  debug4(right.suf, right.pref, right.inner, right.wid);
  Join(left, right, left);
  debug4(left.suf, left.pref, left.inner, left.wid);
  return left.inner;
}
int d[N], h[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, nn, m);
  RE (i, nn) {
    cin>>d[i];
  }
  RE (i, nn) {
    cin>>h[i];
    h[i] *= 2;
  }
  FOR (i, nn + 1, 2 * nn) {
    d[i] = d[i - nn];
    h[i] = h[i - nn];
    debug2(d[i], h[i]);
  }

  nn = 2 * nn;
  int half_n = nn / 2;
  RE (ii, nn) {
    int i = ii + M - 1;
    drz[i].wid = d[ii];
    drz[i].suf = drz[i].wid + h[ii];
    drz[i].pref = h[ii];
    drz[i].inner = 0;
  }
  for (int i = M - 1; i >= 1; i--) {
    Join(drz[2 * i], drz[2 * i + 1], drz[i]);
  }
  RE (i, m) {
    make2(int, a, b);
    if (b < a) {
      b += half_n;
    }
    a += half_n - 1;
    b++;
    debug2(b, a);
    cout<<Read(b, a)<<"\n";
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}