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
#include <cstring>
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

const int N = 1e6 + 20;
const int M = 1 << 20;
int drz[2 * M + 5];
string input;
int pref[N];
int czyt(int a, int b) {
  a += M;
  b += M;
  int wyn = min(drz[a], drz[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(wyn, drz[a + 1]);
    }
    if (b % 2 == 1) {
      mini(wyn, drz[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return wyn;
}
int main()
{
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  getline(cin, input);
  int n = input.length();
  int ind = M + 1;
  RE (i, n) {
    if (input[i - 1] == '(') {
      drz[ind] = drz[ind - 1] + 1;
      pref[i] = pref[i - 1];
    } else {
      drz[ind] = drz[ind - 1] - 1;
      pref[i] = pref[i - 1] + 1;
    }
    ind++;
    debug(drz[ind]);
  }
  FORD (i, M - 1, 1) {
    drz[i] = min(drz[2 * i], drz[2 * i + 1]);
  }
  make(int, m);
  RE (i, m) {
    make2(int, l, r);
    /* debug(l);
    debug(r);
    debug(pref[r]);
    debug(pref[l - 1]);
    debug(drz[l + M - 1]);
    debug(czyt(l, r)); */
    cout<<2 * (pref[r] - pref[l - 1] - drz[l + M - 1] + czyt(l - 1, r)) << "\n";
  }
  
  
  // nie zapomnij o ll
  return 0;
}