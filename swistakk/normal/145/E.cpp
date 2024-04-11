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

struct Node {
  int c4, c7, b47, b74, neg;
};

const int N = 1e6 + 5;
#ifdef LOCAL
const int M = 4;
#else
const int M = 1 << 20;
#endif
Node drz[2 * M + 5];

void NegNode(int a) {
  Node& n = drz[a];
  swap(n.c4, n.c7);
  swap(n.b47, n.b74);
}
void Update(int a) {
  Node& l = drz[2 * a];
  Node& r = drz[2 * a + 1];
  Node& n = drz[a];
  if (a < M) {
    n.c4 = l.c4 + r.c4;
    n.c7 = l.c7 + r.c7;
    n.b47 = max(l.c4 + r.b47, l.b47 + r.c7);
    n.b74 = max(l.c7 + r.b74, l.b74 + r.c4);
    if (n.neg) {
      NegNode(a);
    }
  }
}

void Neg(int a, int b) {
  a += M - 1;
  b += M - 1;
  drz[a].neg ^= 1;
  NegNode(a);
  if (a != b) {
    drz[b].neg ^= 1;
    NegNode(b);
  }
  while (a) { 
    if (a / 2 != b / 2) {
      if (a % 2 == 0) {
        drz[a + 1].neg ^= 1;
        NegNode(a + 1);
        Update(a + 1);
      }
      if (b % 2 == 1) {
        drz[b - 1].neg ^= 1;
        NegNode(b - 1);
        Update(b - 1);
      }
    }
    Update(a);
    Update(b);
    a /= 2;
    b /= 2;
  }
}
    


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  
  make(string, s);
  s = ' ' + s;
  RE (i, n) {
    Node& no = drz[i + M - 1];
    if (s[i] == '4') {
      no.c4 = 1;
      no.b47 = 1;
      no.b74 = 1;
    } else {
      no.c7 = 1;
      no.b47 = 1;
      no.b74 = 1;
    }
  }
  FORD (i, M - 1, 1) {
    Update(i);
  }
  RE (ii, m) {
    make(string, q);
    if (q[0] == 'c') {
      cout<<drz[1].b47<<"\n";
    } else {
      make2(int, l, r);
      Neg(l, r);
//       FOR (i, 1, 2 * M) {
//         Node& no = drz[i];
//         debug4(no.c4, no.c7, no.b47, no.b74);
//       }
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}