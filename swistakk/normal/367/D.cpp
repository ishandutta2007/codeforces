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
int m;
const int N = 1 << 20;
int elim[N + 1];
int bits[N + 1];
void eliminate(int mask) {
  elim[mask] = 1;
  REP (i, m) {
    if ((mask & (1 << i)) && !elim[mask - (1 << i)]) {
      eliminate(mask - (1 << i));
    }
  }
}

int gdzie[N];
int licz[N];
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  cin>>m;
  make(int, d);
  
  bits[1] = 1;
  for (int i = 1; i < (1 << 19); i++) {
    bits[2 * i] = bits[i];
    bits[2 * i + 1] = bits[i] + 1;
    /* if (i <= 8) {
      cout<<i<<" "<<bits[i]<<endl;
    } */
  }
  
  RE (i, m) {
    make(int, ile);
    RE (j, ile) {
      make(int, x);
      gdzie[x] = i;
    }
  }
  RE (i, n) {
    licz[gdzie[i]]++;
    if (i > d) {
      licz[gdzie[i - d]]--;
    }
    if (i >= d) {
      int to_elim = 0;
      RE (j, m) {
        if (licz[j] == 0) {
          to_elim += 1 << (j - 1);
        }
      }
      eliminate(to_elim);
    }
  }
  
  int res = m;
  REP (i, (1 << m)) {
    if (!elim[i]) {
      mini(res, bits[i]);
    }
  }
  cout<<res<<endl;
  // nie zapomnij o ll
  return 0;
}