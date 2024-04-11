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
const int N = 1e6 + 5;
vector<int> slo[N];
int vis[N];
int init[N];
int goal[N];
int res[N];
/* int dp[N][4];
int Corr(int a) {
  if (a >= 1 && a <= 2) {
    return 3 - a;
  } else {
    return a;
  }
} */
int to_change;
void dfs(int v, bool dep_odd, bool odd_evendep, bool odd_odddep) {
  vis[v] = 1;
  int odd[2] = {odd_evendep, odd_odddep};
  if (goal[v] != odd[dep_odd]) {
    to_change++;
    res[v] = 1;
    odd[dep_odd] ^= 1;
  }
    
    
  for (int nei : slo[v]) {
    if (vis[nei]) {
      continue;
    }
    dfs(nei, !dep_odd, odd[0], odd[1]);
  }
//   REP (i, 4) {
//     int root_match = i / 2;
//     int root_flip = (goal[v] ^ root_match);
//     dp[v][i] += root_flip;
//   }
}
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  RE (i, n - 1) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  RE (i, n) {
    cin>>init[i];
  }
  RE (i, n) {
    cin>>goal[i];
    goal[i] = (goal[i] ^ init[i]);
  }
  dfs(1, false, false, false);
  cout<<to_change<<endl;
  RE (i, n) {
    if (res[i]) {
      cout<<i<<" ";
    }
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}