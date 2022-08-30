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
const int N = 2e5 + 5;
const int M = 1 << 18;

int Read(vector<int>& drz, int a, int b) {
  if (a > b) { return 0; }
  a += M;
  b += M;
  int sum = drz[a];
  if (a != b) { sum += drz[b]; }
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      sum += drz[a + 1];
    }
    if (b % 2 == 1) {
      sum += drz[b - 1];
    }
    a /= 2;
    b /= 2;
  }
  return sum;
}
void Add(vector<int>& drz, int a) {
  a += M;
  while (a) {
    drz[a]++;
    a /= 2;
  }
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  vector<int> repr[2];
  vector<int> drz[3];
  REP (tr, 2) {
    drz[tr].resize(2 * M + 5);
    RE (i, n) {
      make(int, a);
      int w = a - Read(drz[tr], 0, a);
      repr[tr].PB(w);
      Add(drz[tr], a);
    }
  }
  debugv(repr[0]);
  debugv(repr[1]);
  vector<int> new_repr;
  new_repr.resize(n);
  int carry = 0;
  for (int i = n - 1; i >= 0; i--) {
    new_repr[i] = repr[0][i] + repr[1][i] + carry;
    int mod = n - i;
    if (new_repr[i] >= mod) {
      carry = 1;
      new_repr[i] -= mod;
    } else {
      carry = 0;
    }
  }
  debugv(new_repr);
//   n = 6;
//   new_repr = {1, 2, 3, 2, 0, 0};
  drz[2].resize(2 * M + 5);
  REP (i, n) {
    int kl = 0, kp = n, faj = -1;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      int got = aktc - Read(drz[2], 0, aktc);
      if (got >= new_repr[i]) {
        faj = aktc;
        kp = aktc - 1;
      } else {
        kl = aktc + 1;
      }
    }
    cout<<faj<<" ";
    Add(drz[2], faj);
  }
  cout<<"\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}