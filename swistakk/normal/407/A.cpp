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

const int N = 2e3 + 2;

vector<pair<int, int> > h[N * N * 2];

int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  RE (i, N - 1) {
    RE (j, N - 1) {
      h[i * i + j * j].PB(MP(i, j));
    }
  }
  
  make2(int, a, b);
  int sqa = a * a, sqb = b * b;
  int G = __gcd(sqa, sqb);
    //
  for (auto p : h[G]) {
    //
    int i = p.first;
    int j = p.second;
    int g = __gcd(a, b);
    int rata = a / g;
    int ratb = b / g;
    if (i * rata != j * ratb) {
      cout<<"YES\n";
      cout<<"0 0\n";
      cout<<i * rata<<" "<<-j * rata<<"\n";
      cout<<j * ratb<<" "<<i * ratb<<"\n";
      return 0;
    }
  }
  cout<<"NO\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}