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

const int N = 2e5;
const int R = 1e5 + 5;
int y[N];
int x[N];
vector<int> on_hor[N], on_ver[N];
bool cmp_hor(int a, int b) {
  return x[a] < x[b];
}
bool cmp_ver(int a, int b) {
  return y[a] < y[b];
}
int last_hor[N], last_ver[N];
VPII hor_q[N], ver_q[N];
int pos_hor[N], pos_ver[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  RE (i, n) {
    cin>>y[i];
    cin>>x[i];
    y[i]++;
    x[i]++;
    on_hor[y[i]].PB(i);
    on_ver[x[i]].PB(i);
  }
  RE (i, R) {
    sort(ALL(on_hor[i]), cmp_hor);
    sort(ALL(on_ver[i]), cmp_ver);
  }
  RE (i, R) {
    for (int j = 0; j < on_hor[i].size(); j++) {
      pos_hor[on_hor[i][j]] = j;
    }
    for (int j = 0; j < on_ver[i].size(); j++) {
      pos_ver[on_ver[i][j]] = j;
    }
  }
  long long res = 0;
  RE (i, n) {
    if (pos_hor[i] < pos_ver[i]) {
      //cerr<<"Punkt " << y[i] << " "<< x[i] << " ma mniej na lewo niz na dol"<<endl;  
      for (int j = 0; j < pos_hor[i]; j++) {
        int diff = x[i] - x[on_hor[y[i]][j]];
        assert(on_hor[y[i]][pos_hor[i]] == i);
        assert(diff > 0);
        if (y[i] >= diff) {
          hor_q[y[i] - diff].PB(MP(x[on_hor[y[i]][j]], x[i]));
        }
      }
    } else {
      for (int j = 0; j < pos_ver[i]; j++) {
        int diff = y[i] - y[on_ver[x[i]][j]];
        assert(diff > 0);
        assert(on_ver[x[i]][pos_ver[i]] == i);
        if (x[i] >= diff) {
          ver_q[x[i] - diff].PB(MP(y[on_ver[x[i]][j]], y[i]));
        }
      }
    }
  }
  RE (i, R) {
    for (auto xx : on_hor[i]) {
      last_hor[x[xx]] = i;
    }
    for (auto yy : on_ver[i]) {
      last_ver[y[yy]] = i;
    }
    for (auto p : hor_q[i]) {
      debug(p);
      if (last_hor[p.first] == i && last_hor[p.second] == i) {
        res++;
        debug("hor");
        debug(i);
        debug(p.first);
        debug(p.second);
      }
    }
    for (auto p : ver_q[i]) {
      debug(p);
      if (last_ver[p.first] == i && last_ver[p.second] == i) {
        res++;
        
        debug("ver");
        debug(i);
        debug(p.first);
        debug(p.second);
      }
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}