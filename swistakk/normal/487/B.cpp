#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
using std::bitset;
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

const int N = 1e5;
const int M = 1 << 18;
int drz[2 * M + 5][3];

int ReadMin(int a, int b, int kt) {
  a += M ;
  b += M ;
  assert(kt == 0 || kt == 2);
  int res = min(drz[a][kt], drz[b][kt]);
  debug2(drz[a][kt], drz[b][kt]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(res, drz[a + 1][kt]);
    }
    if (b % 2 == 1) {
      mini(res, drz[b - 1][kt]);
    }
    a /= 2;
    b /= 2;
  }
  return res;
}
int ReadMax(int a, int b) {
  a += M ;
  b += M ;
  int res = max(drz[a][1], drz[b][1]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      maxi(res, drz[a + 1][1]);
    }
    if (b % 2 == 1) {
      maxi(res, drz[b - 1][1]);
    }
    a /= 2;
    b /= 2;
  }
  return res;
}
void Update(int a, int val) {
  a += M ;
  drz[a][2] = val;
  a /= 2;
  while (a) {
    drz[a][2] = min(drz[2 * a][2], drz[2 * a + 1][2]);
    a /= 2;
  }
}
int a[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
  make3(int, n, s, l);
  
  RE (i, n) {
    cin>>a[i];
    drz[M + i][0] = drz[M + i][1] = a[i];
    drz[M + i][2] = (int)1e9;
  }
  for (int i = M; i >= 1; i--) {
    drz[i][0] = min(drz[2 * i][0], drz[2 * i + 1][0]);
    drz[i][1] = max(drz[2 * i][1], drz[2 * i + 1][1]);
    drz[i][2] = min(drz[2 * i][2], drz[2 * i + 1][2]);
  }
  debug('a');
  int left = 1;
  Update(0, 0);
  RE (i, n) {
    while (ReadMax(left, i) - ReadMin(left, i, 0) > s) {
      debug2(left, i);
      debug2(ReadMax(left, i), ReadMin(left, i, 0));
      left++;
    }
    debug(i);
    int right = i - l + 1;
    if (left <= right) {
      int res = ReadMin(left - 1, right - 1, 2);
      Update(i, res + 1);
    }
  }
  RE (i, n) {
    debug(ReadMin(i, i, 2));
  }
  int res = ReadMin(n, n, 2);
  if (res > n) {
    cout<<"-1\n";
  } else {
    cout<<res<<"\n";
  }
  
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}