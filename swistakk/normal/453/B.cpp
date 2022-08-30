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
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
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
using std::reverse;
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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int large[] = {31, 37, 41, 43, 47, 53};
const int N = 1e2 + 5;
const int PR = 10;
const int LAR = 6;
const int INF = 1e9;
const int R = 60;
int bad[2 * R];
int best[N][1 << PR][LAR + 1];
int move[N][1 << PR][LAR + 1];
int divs[N];
int a[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  REP (i, LAR) {
    bad[large[i]] = 1;
  }
  REP (k, n + 1) {
    REP (i, (1 << PR)) {
      FOR (j, 0, LAR) {
        best[k][i][j] = INF;
      }
    }
  }
  best[0][0][0] = 0;
  RE (i, R) {
    REP (j, PR) {
      if (i % primes[j] == 0) {
        divs[i] += (1 << j);
      }
    }
    //debug(i);
    //debug(divs[i]);
  }
  RE (i, n) {
    cin>>a[i];
    REP (mask, 1 << PR) {
      FOR (lar, 0, LAR) {
        for (int new_n = 1; new_n <= R; new_n++) {
          if (bad[new_n]) {
            continue;
          }
          if ((divs[new_n] & mask) != divs[new_n]) {
            continue;
          }
          int cand = best[i - 1][mask - divs[new_n]][lar] + abs(a[i] - new_n);
          if (cand < best[i][mask][lar]) {
            best[i][mask][lar] = cand;
            move[i][mask][lar] = new_n;
          }
        }
      }
      REP (lar, LAR) {
        int lar_cand = best[i - 1][mask][lar] + large[lar] - a[i];
        if (lar_cand < best[i][mask][lar + 1]) {
          best[i][mask][lar + 1] = lar_cand;
          move[i][mask][lar + 1] = large[lar];
        }
      }
    }
  }
  int best_val = INF;
  int best_mask = 0;
  int best_lar = 0;
  REP (mask, 1 << PR) {
    FOR (lar, 0, LAR) {
      if (best[n][mask][lar] < best_val) {
        best_mask = mask;
        best_lar = lar;
        best_val = best[n][mask][lar];
      }
    }
  }
  int act_pos = n;
  int act_mask = best_mask;
  int act_lar = best_lar;
  vector<int> to_print;
  debug(best_val);
  while (act_pos) {
    int m = move[act_pos][act_mask][act_lar];
    to_print.PB(m);
    if (bad[m]) {
      act_lar--;
    } else {
      act_mask -= divs[m];
    }
    act_pos--;
  }
  //assert(act_mask == 0);
  //assert(act_lar == 0);
  
  
  
  
  reverse(ALL(to_print));
  for (auto nic : to_print) {
    cout<<nic<<" ";
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  return 0;
}