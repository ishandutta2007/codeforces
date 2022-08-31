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

const int N = 1e5 + 5;
vector<int> slo[N];
int cnt[N];
int vis[N];
void dfs(int v, int dep) {
  vis[v] = 1;
  cnt[dep]++;
  for (auto nei : slo[v]) {
    if (vis[nei]) {
      continue;
    }
    dfs(nei, dep + 1);
  }
}

int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make3(ll, m, k, p);
  for (int i = 1; i <= m - 1; i++) {
    make2(int, a, b);
    slo[a].PB(b);
    slo[b].PB(a);
  }
  dfs(1, 0);
  ll coins_used = 0;
  ll res = 0;
  int left_pos = 1;
  ll res_best = 0;
  for (int i = 1; i <= m; i++) {
    debug(cnt[i]);
    coins_used += res;
    res += cnt[i];
    while (coins_used > p) {
      if (cnt[left_pos]) {
        cnt[left_pos]--;
        res--;
        coins_used -= i - left_pos;
        //debug('a');
      } else {
        left_pos++;
      }
    }
    maxi(res_best, res);
  }
  
  
  
  
  cout<<min(k, res_best)<<endl;
  return 0;
}