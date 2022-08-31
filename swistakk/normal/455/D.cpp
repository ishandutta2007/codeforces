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
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#else
#define debug(x)
#define debugv(x)
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
using std::endl;
using std::cout;
using std::cin;
using std::cerr;
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
using std::swap;
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

const int kBlock = 1e3;
const int N = 2e5 + 5;
int shift[N];
vector<int> bl[N];
map<int, int> bl_occ[N];
int a[N];
int n;
int block_num;

void Distribute() {
  int act_block = 1;
  RE (i, n) {
    bl[act_block].PB(a[i]);
    bl_occ[act_block][a[i]]++;
    if (i % kBlock == 0) {
      act_block++;
    }
  }
  block_num = act_block;
}

void Balance() {
  int got = 0;
  for (int i = 1; got < n; i++) {
    for (int j = 0; j < bl[i].size(); j++) {
      got++;
      a[got] = bl[i][j];
    }
    bl[i].clear();
    bl_occ[i].clear();
  }
  Distribute();
}

void Print() {
  int got = 0;
  cerr<<endl;
  for (int i = 1; got < n; i++) {
    for (int j = 0; j < bl[i].size(); j++) {
      got++;
      cerr<<bl[i][j]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
}
  

int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n;
  RE (i, n) {
    cin>>a[i];
  }
  Distribute();
  int last = 0;
  make(int, q);
  RE (qq, q) {
    if (qq % kBlock == 0) {
      Balance();
    }
    //Print();
    make(int, t);
    make2(int, l, r);
    l = ((l + last - 1) % n) + 1;
    r = ((r + last - 1) % n) + 1;
    if (l > r) {
      swap(l, r);
    }
    if (t == 1) {
      int bl_l, ind_l, bl_r, ind_r;
      int got_so_far = 0;
      RE (i, block_num) {
        if (got_so_far + 1 <= l && got_so_far + bl[i].size() >= l) {
          bl_l = i;
          ind_l = l - got_so_far - 1;
        }
        if (got_so_far + 1 <= r && got_so_far + bl[i].size() >= r) {
          bl_r = i;
          ind_r = r - got_so_far - 1;
        }
        got_so_far += bl[i].size();
      }
//       if (ind_r >= bl[bl_r].size()) {
//         cerr<<"ERROR"<<endl;;
//         debug(bl_r);
//         debug(ind_r);
//         debug(SZ(bl[bl_r]));
//       }
      int ar = bl[bl_r][ind_r];
      bl_occ[bl_r][ar]--;
      bl_occ[bl_l][ar]++;
      for (int j = ind_r + 1; j < bl[bl_r].size(); j++) {
        bl[bl_r][j - 1] = bl[bl_r][j];
      }
      bl[bl_r].pop_back();
      bl[bl_l].push_back(0);
      for (int j = SZ(bl[bl_l]) - 2; j >= ind_l; j--) {
        bl[bl_l][j + 1] = bl[bl_l][j];
      }
      bl[bl_l][ind_l] = ar;
    } else {
      make(int, k);
      k = ((k + last - 1) % n) + 1;
      //cerr<<l<<" "<<r<<" "<<k<<"\n";
      int ans = 0;
      int got_so_far = 0;
      RE (i, block_num) {
        if (got_so_far + bl[i].size() < l) {
          //cerr<<"x"<<endl;
          goto A;
        } else if (got_so_far >= r) {
          //cerr<<"y"<<endl;
          break;
        } else if (got_so_far + 1 >= l && got_so_far + bl[i].size() <= r) {
          //cerr<<"z"<<endl;
          ans += bl_occ[i][k];
        } else {
          //cerr<<"Badam blok nr "<<i<<endl;
          REP (j, bl[i].size()) {
            int act_ind = got_so_far + j + 1;
            if (bl[i][j] == k && act_ind >= l && act_ind <= r) {
              ans++;
            }
          } 
        }
        A: ;
        got_so_far += bl[i].size();
      }
      cout<<ans<<"\n";
      last = ans;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}