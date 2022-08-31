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

const int L = 23;
const int N = 1e6 + 5;
int dp[N][L];
vector<int> slo[N];
void dfs(int v) {
  int mins[L][2];
  //mins.resize(L);
  for (int l = 0; l < L; l++) {
    dp[v][l] = N;
    //mins[l].resize(2);
    mins[l][0] = N;
    mins[l][1] = N;
  }
  dp[v][1] = v - 1;
  if (slo[v].size() == 0) {
    return;
  }
  for (auto nei : slo[v]) {
    dfs(nei);
    for (int l = 0; l < L; l++) {
      if (dp[nei][l] < mins[l][0]) {
        mins[l][1] = mins[l][0];
        mins[l][0] = dp[nei][l];
      } else if (dp[nei][l] < mins[l][1]) {
        mins[l][1] = dp[nei][l];
      }
    }
  }
  //dp[v][1] = mins[0][0];
  for (int l = 2; l < L; l++) {
    dp[v][l] = min(mins[l][0], mins[l - 1][1]);
  }
}
    

int main() {
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  scanf("%d", &n);
  //make(int, n);
  n++;
  RE (i, n - 1) {
    int a;
    scanf("%d", &a);
    //make(int, a);
    slo[a].PB(i + 1);
  }
  dfs(1);
  int act_res = 1;
  vector<int> to_res;
  for (int l = 0; l <= L; l++) {
    to_res.PB(N);
  }
  for (auto nei : slo[1]) {
    for (int l = 0; l < L; l++) {
      mini(to_res[l], dp[nei][l]);
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    if (to_res[act_res + 1] == i) {
      act_res++;
    }
    printf("%d ", act_res);
    //cout<<act_res<<" ";
  }
  printf("\n");
  //cout<<endl;

  
  // nie zapomnij o ll
  return 0;
}