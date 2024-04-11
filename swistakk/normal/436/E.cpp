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
const int N = 1e6;
ll dp1[N];
ll dp2[N];
ll how_many[N];
const ll INF = 1e18;
ll to_remove[N];
ll to_add[N];
ll low[N];
ll to_add2[N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(ll, n, w);
  vector<pair<ll, ll> > alone;
  vector<pair<pair<ll, ll>, ll> > both;
  RE (i, n) {
    make2(ll, a, b);
    b -= a;
    if (a <= b) {
      alone.PB(MP(a, i));
      alone.PB(MP(b, i));
    } else {
      both.PB(MP(MP(a + b, a), i));
    }
  }
  sort(ALL(alone));
  sort(ALL(both));
  dp1[0] = 0;
  RE (i, alone.size()) {
    dp1[i] = dp1[i - 1] + alone[i - 1].first;
  }
  FOR (i, alone.size() + 1, w) {
    dp1[i] = INF;
  }
  dp2[0] = 0;
  set<pair<ll, ll> > tops;
  /* for (in i = 1; i <= w; i++) {
    if (i % 2 == 0) {
      dp2[i] = dp2[i - 2] + both[i / 2 - 1].first.first;
      from_tops.insert(MP(both[i / 2
    } else {
      
    }
  } */
  int lowest_bottom = 1e9 + 5;
  int where = (int)(both.size() - 1);
  low[both.size()] = lowest_bottom;
  for (int i = int(both.size()) - 1; i >= 0; i--) {
    if (both[i].first.second < lowest_bottom) {
      lowest_bottom = both[i].first.second;
      where = both[i].second;
    }
    low[i] = lowest_bottom;
    to_add[i] = where;
  }
  /* set<pair<ll, ll> > bottoms;
  for (auto b : both) {
    bottoms.insert(MP(b.first.second, b.second));
  } */
  ll highest_top = 0;
  int highest_top_ind = 0;;
  for (int i = 0; i < both.size(); i++) {
    dp2[2 * i + 2] = both[i].first.first + dp2[2 * i];
    if (both[i].first.first - both[i].first.second > highest_top) {
      highest_top = both[i].first.first - both[i].first.second;
      highest_top_ind = both[i].second;
    }
    dp2[2 * i + 1] = dp2[2 * i + 2] - highest_top;
    to_remove[2 * i + 1] = highest_top_ind;
    ll cand = dp2[2 * i] + low[i + 1];
    if (cand < dp2[2 * i + 1]) {
      to_remove[2 * i + 1] = 0;
      dp2[2 * i + 1] = cand;
      to_add2[2 * i + 1] = to_add[i + 1];
    }
  }
  FOR (i, 2 * both.size() + 1, w) {
    dp2[i] = INF;
  }
    
    //from_tops.insert(MP(both[i].first.first - bottoms, both[i].second));
    //from
    
    
  
  int from_alone = 0;
  ll best = INF;
  for (int i = 0; i <= w; i++) {
    if (dp1[i] + dp2[w - i] < best) {
      from_alone = i;
      best = dp1[i] + dp2[w - i];
    }
  }
  
  for (int i = 0; i < from_alone; i++) {
    how_many[alone[i].second]++;
  }
  
  
  int from_both = w - from_alone;
  if (from_both % 2 == 0) {
    for (int i = 0; i < from_both / 2; i++) {
      how_many[both[i].second] = 2;
    }
  } else {
    if (to_remove[from_both]) {
      for (int i = 0; i < from_both / 2 + 1; i++) {
        how_many[both[i].second] = 2;
      }
      how_many[to_remove[from_both]]--;
    } else {
      for (int i = 0; i < from_both / 2; i++) {
        how_many[both[i].second] = 2;
      }
      how_many[to_add2[from_both]] = 1;
    }
  }
  
  cout<<best<<endl;
  RE (i, n) {
    cout<<how_many[i];
  }
  cout<<endl;
  
  
  // nie zapomnij o ll
  return 0;
}