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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

const int N = 5e3 + 5;
ll a[N];
ll b[N];
const int M = 1e9;
vector<int> lp;
int sieve[int(1e6)];
ll pref[N];
void miel(int p, int n, int sign) {
  int exp = 1e6;
  RE (j, n) {
    int tmp = a[j];
    int act_exp = 0;
    while (tmp % p == 0) {
      act_exp++;
      tmp /= p;
    }
    mini(exp, act_exp);
    pref[j] += sign * exp;
    
    if (exp == 0) {
      break;
    }
    debug(pref[j]);
    debug(j);
    debug(p);
  } 
}

map<int, int> bad;
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  for (int i = 2; i * i <= M; i++) {
    if (sieve[i] != 0) {
      continue;
    }
    lp.PB(i);
    for (ll j = 2; i * j * i *j <= M; j++) {
      sieve[i * j] = 1;
    }
  }
      
  
  make2(int, n, m);
  ll beauty = 0;
  RE (i, n) {
    cin>>a[i];
  } 
  RE (i, m) {
    cin>>b[i];
    bad[b[i]] = 1;
    
    miel(b[i], n, 1);
  }
  for (int p : lp) {
    if (!bad[p]) {
      miel(p, n, -1);
    }
  }
  RE (i, n) {
    int tmp = a[i];
    for (int p : lp) {
      int sign = 1;
      if (bad[p]) {
        sign = -1;
      }
      while (tmp % p == 0) {
        beauty += sign;
        tmp /= p;
      }
      if (tmp == 1) {
        break;
      }
    }
    if (tmp == 1) {
      continue;
    }
    if (!bad[tmp]) {
      beauty += 1;
    } else {
      beauty--;
    }
  }
  
  RE (i, n) {
    debug(pref[i]);
  }
  debug(beauty);
  int gain = 0;
  int sum_gained = 0;
  for (int i = n; i >= 1; i--) {
    if (pref[i] >= sum_gained) {
      beauty += (pref[i] - sum_gained) * i;
      sum_gained = pref[i];
    }
  }
  
  
  
  cout<<beauty<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}