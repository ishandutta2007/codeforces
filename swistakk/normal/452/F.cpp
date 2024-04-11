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
#define PB push_back
#define MP make_pair
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
ll inv_per[N];
bool ExistBrut(vector<int>& vec) {
  int n = vec.size();
  RE (i, n) {
    inv_per[vec[i - 1]] = i;
  }
  bool bad = false;
  RE (i, n) {
    for (int j = i + 2; j <= n; j += 2) {
      if ((inv_per[i] - inv_per[(i + j) / 2]) * (inv_per[(i + j) / 2] - inv_per[j]) > 0) {
        bad = true;
      }
    }
  }
  if (bad) {
    //cerr<<"Z bruta\n"<<endl;
  }
  return bad;
}

bool Exist(vector<int>& vec) {
  int n = vec.size();
  debugv(vec);
  if (n < 5) {
    return ExistBrut(vec);
  }
  vector<int> odd, even;
  ll inv = 0;
  ll max_inv = 1ll * (n / 2) * ((n + 1) / 2);
  vector<pair<int, int> > cands;
  int tol = n + 10;
  int odd_so_far = 0;
  int cnt = 0;
  for (auto a : vec) {
    inv_per[a] = cnt;
    cnt++;
    if (a % 2 == 1) {
      odd_so_far++;
    } else {
      inv += odd_so_far;
    }
  }
  if (inv > tol && inv < max_inv - tol) {
    //cerr<<"Za duzo inwersji\n";
    return true;
  }
  for (auto a : vec) {
    if (a % 2 == 1) {
      odd.PB(a);
      if (inv >= max_inv - tol) {
        for (int i = 0; i < even.size(); i++) {
          cands.PB(MP(even[i], a));
        }
      }
    } else {
      even.PB(a);
      if (inv <= tol) {
        for (int i = 0; i < odd.size(); i++) {
          cands.PB(MP(odd[i], a));
        }
      }
    }
  }
  debugv(cands);
  for (auto p : cands) {
    int left = 2 * p.first - p.second;
    if (left >= 1 && left <= n) {
      if (inv_per[left] < inv_per[p.first]) {
        //cerr<<"Znaleziona z kandydatow1"<<endl;
        return true;
      }
    }
    int right = 2 * p.second - p.first;
    if (right >= 1 && right <= n) {
      if (inv_per[right] > inv_per[p.second]) {
        //cerr<<"Znaleziona z kandydatow2 "<<p.first<<" "<<p.second<<" "<<right<<endl;
        return true;
      }
    }
  }
  
  vec.clear();
  for (auto& a : odd) {
    a = (a + 1) / 2;
  }
  for (auto& a : even) {
    a = a / 2;
  }
  return Exist(odd) || Exist(even);
}
      
      
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  vector<int> vec;
  RE (i, n) {
    make(int, a);
    vec.PB(a);
  }
  if (Exist(vec)) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}