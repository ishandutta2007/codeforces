#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
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
using std::abs;
using std::__gcd;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
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

const int N = 1e6 + 5;
int was[N];
set<int> counted;
map<int, int> nimber;

int res_for_stack[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14, };

int Rec(int mask) {
  if (counted.count(mask)) {
    return nimber[mask];
  }
  //cerr<<"In "<<mask<<"\n";
  set<int> here;
  here.insert(0);
  for (int i = 1; (1 << i) <= mask; i++) {
    int pot = (1 << i);
    if (pot & mask) {
      int new_mask = mask;
      int tmp_pot = pot;
      while (tmp_pot < mask) {
        if (mask & tmp_pot) {
          new_mask -= tmp_pot;
        }
        tmp_pot *= 2 * pot;
      }
      //cerr<<"From "<<mask<<" looking to "<<new_mask<<"\n";
      here.insert(Rec(new_mask));
    }
  }
  int res = 0;
  while (here.count(res)) {
    res++;
  }
  counted.insert(mask);
  nimber[mask] = res;
  return res;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   int H = 30;
//   counted.insert(0);
//   RE (i, H) {
//     res_for_stack[i] = Rec((1 << i) - 1);
//     //debug2(i, res_for_stack[i]);
//     cerr<<res_for_stack[i]<<", ";
//   }
//   cerr<<endl;
//   RE (i, 1 << H) {
//     debug2(i, nimber[i]);
//   }
  
  make(int, n);
  int sq = min((int)sqrt(n) + 2, n);
  int all_xor = 0;
  int used = 0;
  for (int i = 2; i <= sq; i++) {
    if (was[i]) { continue; }
    int pot = i;
    int log = 1;
    while (pot * i <= n) {
      log++;
      pot = pot * i;
      if (pot <= sq) {
        was[pot] = 1;
      }
    }
    used += log;
    all_xor ^= res_for_stack[log];
    debug(log);
  }
  debug(used);
  int rest = n - used;
  all_xor ^= (rest & 1);
  if (all_xor == 0) {
    cout<<"Petya\n";
  } else {
    cout<<"Vasya\n";
  }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}