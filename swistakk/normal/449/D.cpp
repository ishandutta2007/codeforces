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
const ll M = 1e9 + 7;
const int N = 1 << 21;
ll pows[N];
ll kub[N];
ll cnt[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    make(int, a);
    kub[a]++;
  }
  pows[0] = 1;
  RE (i, n) {
    pows[i] = (2 * pows[i - 1]) % M;
  }
  
  
  /*FOR (i, 0, 1e6) {
    if (kub[i] == 0) {
      continue;
    }
    vector<int> nic;
    nic.PB(0);
    for (int p = 1; p <= i; p *= 2) {
      if (i & p) {
        int cop = nic.size();
        for (int j = 0; j < cop; j++) {
          nic.PB(nic[j] + p);
        }
      }
    }
    //cerr<<"subsets of "<<i<<": \n";
    for (auto a : nic) {
      //cerr<<a<<" ";
      cnt[a] += kub[i];
    }
    //cerr<<endl;
   
  } */
  
  for (int p = 1; p < (1 << 20); p *= 2) {
    for (int i = 0; i < (1 << 20); i++) {
      if (!(i & p) && (i + p) < (1 << 20)) {
        kub[i] += kub[i + p];
      }
    }
  }
  
  ll res = 0;
  FOR (i, 0, (1 << 20) - 1) {
//     if (cnt[i]) {
//       cerr<<i<<" "<<cnt[i]<<" "<<kub[i]<<endl;
//     }
    //assert(cnt[i] == kub[i]);
    if (__builtin_popcount(i) % 2 == 0) {
      res = (res + pows[kub[i]]) % M;
    } else {
      res = (res + M - pows[kub[i]]) % M;
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}