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
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PII;
typedef pair<ll, ll> PLL;
typedef vector<ll> VI;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

struct Node {
  int val, whole; 
  Node() : val(0), whole(0) {};
};

const int M = 1 << 17;
Node drz[2 * M + 5];

void AddRec(int node, int lb, int rb, int l, int r, int val) {
  int mid = (lb + rb) / 2;
  if (r < lb || l > rb) {
    return;
  }
  if (lb == l && rb == r) {
    drz[node].val += val;
    drz[node].whole += (r - l + 1) * val;
    return;
  }
  AddRec(2 * node, lb, mid, l, min(r, mid), val);
  AddRec(2 * node + 1, mid + 1, rb, max(mid + 1, l), r, val);
  drz[node].whole = drz[2 * node].whole + drz[2 * node + 1].whole + drz[node].val * (rb - lb + 1);
  return;
}

void Add(int l, int r, int val) {
  //debug3(l, r, val);
  AddRec(1, 1, M, l, r, val);
}

int GetSumRec(int node, int lb, int rb, int l, int r) {
  int res = 0;
  int mid = (lb + rb) / 2;
  if (r < lb || l > rb) {
    return 0;
  }
  if (lb == l && rb == r) {
    return drz[node].whole;
  }
  res += GetSumRec(2 * node, lb, mid, l, min(r, mid));
  res += GetSumRec(2 * node + 1, mid + 1, rb, max(mid + 1, l), r);
  return res + (r - l + 1) * drz[node].val;
}

int GetSum(int l, int r) {
  return GetSumRec(1, 1, M, l, r);
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  set<pair<PII, int> > cols;
  RE (i, n) {
    Add(i, i, i);
    cols.insert(MP(MP(i, i), i));
  }
  RE (i, m) {
    make(int, type);
    if (type == 2) {
      make2(int, l, r);
      cout<<GetSum(l, r) - r * (r + 1) / 2 + l * (l - 1) / 2<<"\n";
    } else {
      make3(int, l, r, x);
      auto it_st = cols.upper_bound(MP(MP(l, n + 1), 1));
      auto it_end = cols.upper_bound(MP(MP(r, n + 1), 1));
      it_st--;
      it_end--;
      auto l_int = *it_st;
      auto r_int = *it_end;
      //debug2(l_int, r_int);
      vector<__typeof(it_st)> to_erase;
      for (auto it = it_st; ; it++) {
        Add(max(l, it->first.first), min(r, it->first.second), abs(x - it->second));
        //cerr<<"Erasuje "<<*it<<endl;
        to_erase.PB(it);
        if (*it == r_int) {
          break;
        }
      }
      for (auto it : to_erase) {
        cols.erase(it);
      }
      if (l_int.first.first < l) {
        cols.insert(MP(MP(l_int.first.first, l - 1), l_int.second));
      }
      if (r_int.first.second > r) {
        cols.insert(MP(MP(r + 1, r_int.first.second), r_int.second));
      }
      cols.insert(MP(MP(l, r), x));
      //debugv(cols);
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}