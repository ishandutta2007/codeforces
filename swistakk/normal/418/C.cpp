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

const int N = 1e2 + 5;
int res[N][N];
ll row[N];
ll col[N];
int ok[N * N * N];
bool is_sqr(ll a) {
  int root = int(sqrt(a));
  return (a == root * root);
}
bool check(ll act1, ll act2) {
  return is_sqr(act1) && is_sqr(act2);
}
vector<int> hehe(int a) {
  vector<int> lol;
  for (int i = 1; i <= 200; i++) {
    if (is_sqr(i * i + a)) {
      lol.PB(i);
    }
  }
  return lol;
}

int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make2(int, n, m);
  int was_swap = 0;
  RE (i, int(1e3)) {
    ok[i * i] = 1;
  }
  /* RE (i, n - 1) {
      RE (j, m - 1) {
          res[i][j] = 3;
      }
  }
  if ((n - 1) % 2 < (m - 1) % 2) {
      swap(n, m);
      was_swap = 1;
      RE (i, m - 1) {
          res[1][i] = 4;
      }
  } else if ((n - 1) % 2 == 0) {
      FOR (i, 2, m - 1) {
          res[1][i] = 4;
      }
      FOR (i, 2, n - 2) {
          res[i][1] = 4;
      }
  }
  FOR (i, n - 1) {
      FOR (j, m - 1) { */

  vector<pair<int, VI> > poss;
  for (int i = 1; i <= 50; i++) {
    poss.PB(MP(i, hehe(i * i * (m - 1))));
    if (poss.back().second.size() == 0) {
      poss.pop_back();
    }
  }
  VPII act;
  ll act1 = 0, act2 = 0;
  RE (i, n) {
    act.PB(MP(poss[0].first, poss[0].second[0]));
    act1 += poss[0].first * poss[0].first;
    act2 += poss[0].second[0] * poss[0].second[0];
  }
  srand(time(NULL));
  while (!check(act1, act2)) {
    //debug('a');
    int to_change = rand() % n;
    int new_ind = rand() % poss.size();
    int p = rand() % poss[new_ind].second.size();
    act1 -= act[to_change].first * act[to_change].first;
    act2 -= act[to_change].second * act[to_change].second;
    act[to_change] = MP(poss[new_ind].first, poss[new_ind].second[p]);
    act1 += act[to_change].first * act[to_change].first;
    act2 += act[to_change].second * act[to_change].second;
  }
  
  
  
  
  
  
  
  
  
  
  
  RE (i, n) {
      RE (j, m - 1) {
//           if (was_swap) {
//               cout<<res[j][i]<<" ";
//           } else {
//               cout<<res[i][j]<<" ";
//           }
        cout<<act[i - 1].first<<" ";
      }
      cout<<act[i - 1].second;
      cout<<endl;
  }

  
  // nie zapomnij o ll
  return 0;
}