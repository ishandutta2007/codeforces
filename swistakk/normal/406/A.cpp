#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#include <complex>
#define MP make_pair
#define PB push_back
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

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 1e3 + 5;
int row[N];
int col[N];
int mat[N][N];
int ch[N];
int main() {

  //ios_base::sync_with_stdio(0);
  //cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  scanf("%d", &n);
  int ans = 0;
  RE (i, n) {
    RE (j, n) {
      int a;
      scanf("%d", &mat[i][j]);
      a = mat[i][j];
      row[i] ^= a;
      col[j] ^= a;
      if (i == j) {
        ans ^= a;
      }
      //cerr<<a<<" ";
    }
    //cerr<<endl;
  }
  
  
  int all = 0;
  
  
//   RE (i, n) {
//     all ^= row[i];
//     ans ^= (row[i] & col[i]);
//   }
  
  
  int m;
  scanf("%d", &m);
  vector<int> q;
  q.resize(5);

//   RE (i, m) {
//     int t;
//     scanf("%d", &t);
//     if (t == 3) {
//       printf("%d", ans);
//     } else {
//       int r;
//       scanf("%d", &r);
//       ans ^= all;
//       if (t == 1) {
//         ans ^= (row[r] ^ q[2]);
//         ans ^= (row[r] ^ q[2]) & (col[r] ^ q[1]);
//         row[r] ^= n % 2;
//         q[t] ^= 1;
//         ans ^= (row[r] ^ q[2]) & (col[r] ^ q[1]);
//       } else {
//         ans ^= (col[r] ^ q[1]);
//         ans ^= (row[r] ^ q[2]) & (col[r] ^ q[1]);
//         col[r] ^= n % 2;
//         q[t] ^= 1;
//         ans ^= (row[r] ^ q[2]) & (col[r] ^ q[1]);
//       }
//       if (n % 2) {
//         all ^= 1;
//       }
//     }
//   }
//   printf("\n");
  
  RE (i, m) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      printf("%d", ans);
    } else {
      int x;
      scanf("%d", &x);
      ans ^= 1;
    }
  }
  printf("\n");
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}