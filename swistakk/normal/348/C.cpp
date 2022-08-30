#include <bits/stdc++.h>
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
using namespace std;
const int B = 313;
const int N = 1e5 + 5;
vector<int> to_sets[N];
vector<int> elts[N];
vector<int> small_elts[N];
vector<int> big_elts[N];
vector<PII> qs;
ll to_add[N];
ll a[N];
ll act[N];
ll big_new[N];
bool is_big[N];
void Restore(int n, int m) {
  RE (i, m) {
    for (auto j : elts[i]) {
      a[j] += to_add[i];
    }
    to_add[i] = 0;
  }
  RE (i, m) {
    act[i] = 0;
    for (auto j : elts[i]) {
      act[i] += a[j];
    }
  }
  RE (i, n) {
    big_new[i] = 0;
  }
  
  qs.clear();
}
unordered_map<int, int> corr[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, n, m, q);
  RE (i, n) {
    cin>>a[i];
  }
  
  RE (i, m) {
    make(int, k);
    RE (j, k) {
      make(int, s);
      elts[i].PB(s);
      to_sets[s].PB(i);
    }
  }
  
  RE (i, n) {
    if (SZ(to_sets[i]) > B) {
      is_big[i] = 1;
    } else {
      for (auto c : to_sets[i]) {
        for (auto b : to_sets[i]) {
          corr[c][b]++;
        }
      }
    }
  }
  
  RE (i, m) {
    for (auto j : elts[i]) {
      if (is_big[j]) {
        big_elts[i].PB(j);
      }
    }
  }
  
  REP (i, q) {
    if (i % B == 0) {
      Restore(n, m);
    }
    make(char, c);
    make(int, k);
    if (c == '?') {
      ll res = act[k];
      for (auto p : qs) {
        res += 1ll * p.second * corr[k][p.first];
      }
      for (auto j : big_elts[k]) {
        res += big_new[j];
      }
      cout<<res<<"\n";
    } else {
      make(int, x);
      for (auto j : big_elts[k]) {
        big_new[j] += x;
      }
      qs.PB(MP(k, x));
      to_add[k] += x;
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}