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
const int N = 3e5 + 5;
int sus[N][2];
int deg[N];
set<pair<int, int> > bad;
bool cmp(PII a, PII b) {
  return a.first > b.first;
}
map<PII, int> degs;
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, p);
  RE (i, n) {
    cin>>sus[i][0]>>sus[i][1];
    if (sus[i][0] > sus[i][1]) {
      swap(sus[i][0], sus[i][1]);
    }
    deg[sus[i][0]]++;
    deg[sus[i][1]]++;
  }
  VPII vec;
  RE (i, n) {
    vec.PB(MP(deg[i], i));
  }
  sort(ALL(vec), cmp);
  int pos = vec.size() - 1;
  long long res = 0;
  for (int i = 0; i < vec.size(); i++) {
    while (vec[i].first + vec[pos].first < p && pos) {
      pos--;
    }
    res += max(0, pos - i);
    debug(i);
    debug(pos);
  }
  //cerr<<res<<endl;
  RE (i, n) {
    PII para = MP(sus[i][0], sus[i][1]);
    if (degs[para] == 0) {
      degs[para] = deg[sus[i][0]] + deg[sus[i][1]];
    }
    degs[para]--;
    if (degs[para] == p - 1) {
      res--;
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}