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

const ll INF = 2 * 1e14;
const int N = 101 * 101;
int first[N];
int res[N];
set<PLL> que;
ll dis[N];
vector<PLL> slo[N];
vector<pair<PLL, PLL> > wyb[N];

void upd_dis(int v, int nei, ll new_dis) {
  if (new_dis == dis[nei]) {
    first[nei] |= first[v];
  }
  if (new_dis < dis[nei]) {
    que.erase(MP(dis[nei], nei));
    dis[nei] = new_dis;
    first[nei] = first[v];
    que.insert(MP(dis[nei], nei));
  }
}
int per[5];
void dijkstra(int n, vector<int> s, int type) {
  if (type == 1) {
    per[1] = 1;
    per[2] = 0;
    per[3] = 0;
  } else {
    per[3] = 1;
  }
  RE (i, n) {
    dis[i] = INF;
    que.insert(MP(INF, i));
  }
  REP (i, 2) {
    que.insert(MP(0, s[i]));
    que.erase(MP(INF, s[i]));
    //cout<<s[i]<<" "<<i + 1<<endl;
    first[s[i]] = i + 1;
    //cout<<first[3]<<endl;
    dis[s[i]] = 0;
  }
  //cout<<first[3]<<endl;
  RE (i, n) {
    debug(i);
    debug(first[i]);
    debug(dis[i]);
  }
  while (!que.empty()) {
    PLL act = *que.begin();
    que.erase(que.begin());
    int v = act.second;
    ll act_dis = act.first;
    for (auto& x : slo[v]) {
      int nei = x.first;
      ll new_dis = act_dis + x.second;
      upd_dis(v, nei, new_dis);
    }
    for (auto& x : wyb[v]) {
      int nei = x.first.first;
      int ind = x.first.second;
      ll new_dis;
      if (per[first[v]]) {
        new_dis = act_dis + x.second.first;
        res[ind] = x.second.first;
      } else {
        new_dis = act_dis + x.second.second;
        res[ind] = x.second.second;
      }
      upd_dis(v, nei, new_dis);
    }
  }
}  

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  //cout<<INF<<endl;
  make3(int, n, m, k);
  make3(int, s1, s2, f);
  
  RE (i, m) {
    make3(ll, a, b, c);
    slo[a].PB(MP(b, c));
  }
  
  RE (i, k) {
    make2(int, a, b);
    make2(ll, l, r);
    wyb[a].PB(MP(MP(b, i), MP(l, r)));
    res[i] = l;
  }
  if (s1 == s2) {
    cout<<"DRAW\n";
    goto A;
  }
  //first[0] = 3;
  //slo[0].PB(MP(0, 0));
  dijkstra(n, vector<int>{s1, s2}, 1);
  RE (i, n) {
    debug(i);
    debug(first[i]);
    debug(dis[i]);
  }
  if (first[f] == 1) {
    cout<<"WIN\n";
    goto A;
  }
  dijkstra(n, vector<int>{s1, s2}, 2);
  if (first[f] != 2) {
    cout<<"DRAW\n";
    goto A;
  }
  cout<<"LOSE\n";
  return 0;
  A: ;
  RE (i, k) {
    cout<<res[i]<<" ";
  }
  cout<<"\n";
  
  // nie zapomnij o ll
  return 0;
}