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

const int N = 1001 * 101;
char slo[N];
int sumpref[N][4];
int main()
{
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  scanf("%s", slo + 1);
  int n = strlen(slo + 1);
  RE (i, n) {
    RE (j, 3) {
      sumpref[i][j] = sumpref[i - 1][j];
    }
    sumpref[i][slo[i] - 'x' + 1]++;
  }
  int m;
  scanf("%d", &m);
  RE (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b - a <= 1) {
      printf("YES\n");
      continue;
    }
    bool ok = true;
    int sum = 0;
    RE (j, 3) {
      int lit_num = sumpref[b][j] - sumpref[a - 1][j];
      sum += lit_num;
      int hehe = lit_num - (b - a + 1) / 3;
      debug(hehe);
      ok &= (hehe >= 0 && hehe <= 1);
    }
    debug(sum);
    debug(b - a + 1);
    if (ok) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  
  
  
  // nie zapomnij o ll
  return 0;
}