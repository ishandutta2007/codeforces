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

const int M = 1 << 18;
struct Node {
  LD pref, suf, sum, in;
};

Node JoinNodes(Node a, Node b) {
  Node n;
  n.pref = max(a.pref, a.sum + b.pref);
  n.suf = max(b.suf, b.sum + a.suf);
  n.sum = a.sum + b.sum;
  n.in = max(a.in, max(b.in, a.suf + b.pref));
  return n;
}

Node drz[2 * M + 5];
LD x[M];// p[M];

LD Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  Node l = drz[a];
  Node r = drz[b];
  if (a == b) {
    return l.in;
  }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      l = JoinNodes(l, drz[a + 1]);
    }
    if (b % 2 == 1) {
      r = JoinNodes(drz[b - 1], r);
    }
    a /= 2;
    b /= 2;
  }
  l = JoinNodes(l, r);
  return l.in;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, n, m, c);
  RE (i, n) {
    cin>>x[i];
  }
  RE (i, n - 1) {
    make(LD, p);
    p /= 100;
    //cin>>p[i];
    LD val = (x[i + 1] - x[i]) / 2 - p * c;// - p[i] * c;
    LD zero = 0;
    LD LOL = max(val, zero);
    drz[i + M - 1] = Node{LOL, LOL, val, LOL};
  }
  FORD (i, M - 1, 1) {
    drz[i] = JoinNodes(drz[2 * i], drz[2 * i + 1]);
  }
  LD res = 0;
  RE (i, m) {
    make2(int, a, b);
    b--;
    res += Read(a, b);
  }
  cout<<res<<"\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}