#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

const int R = 60;

void Join(VI& v1, VI& v2, VI& res) {
  REP (i, R) {
    res[i] = v1[i] + v2[(i + v1[i]) % R];
  }
}

const int M = (1 << 17);
vector<int> drz[2 * M + 5];
void AssignVec(int a, int per) {
  a += M - 1;
  REP (i, R) {
    drz[a][i] = 1 + (i % per == 0);
  }
}
void Change(int a, int per) {
  AssignVec(a, per);
  a += M - 1;
  a /= 2;
  while (a) {
    Join(drz[2 * a], drz[2 * a + 1], drz[a]);
    a /= 2;
  }
}

int Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  int act_t = drz[a][0];
  //vector<int> left = drz[a];
  if (a == b) {
    return act_t;
  }
//   vector<int> right = drz[b];
  vector<int> from_left_inds;
  vector<int> from_right_inds;
  from_right_inds.PB(b);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      from_left_inds.PB(a + 1);
      //left = Join(left, drz[a + 1]);
    }
    if (b % 2 == 1) {
      from_right_inds.PB(b - 1);
      //right = Join(drz[b - 1], right);
    }
    a /= 2;
    b /= 2;
  }
  for (auto x : from_left_inds) {
    act_t += drz[x][act_t % R];
  }
  reverse(ALL(from_right_inds));
  for (auto x : from_right_inds) {
    act_t += drz[x][act_t % R];
  }
  //left = Join(left, right);
  return act_t;
}


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  RE (i, 2 * M) {
    drz[i].resize(R);
  }
  make(int, n);
  RE (i, n) {
    make(int, per);
    AssignVec(i, per);
  }
  for (int i = M - 1; i; i--) {
    Join(drz[2 * i], drz[2 * i + 1], drz[i]);
  }
  make(int, q);
  RE (i, q) {
    make(char, c);
    make2(int, x, y);
    if (c == 'C') {
      Change(x, y);
    } else {
      cout<<Read(x, y - 1)<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}