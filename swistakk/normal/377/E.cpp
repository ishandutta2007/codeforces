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
#define FORE(i, c) for(VAR(itt, (c).begin()), VAR(i,*itt); itt != (c).end(); itt++, i=*itt)
#define FOREIT(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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

const ll INF = 100000000000000001ll;

struct seg {
  ll x, dl, y, slope;
  seg(ll _x = 0, ll _dl = 0, ll _y = 0, ll _slope = 0) {
    x = _x;
    dl = _dl;
    y = _y;
    slope = _slope;
  }
};

vector<seg> ot;
VPLL building_old;
VPLL building;

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  ot.PB(seg(-1, INF, 0, 0));
  ll n, s;
  cin>>n>>s;
  
  REP (i, n) {
    pair<ll, ll> para;
    cin>>para.X>>para.Y;
    building_old.PB(para);
  }
  
  building_old.PB(MP(INF / 2, s));
  sort(ALL(building_old));
  ll min_c = INF;
  
  FORD (i, SZ(building_old) - 1, 0) {
    if (building_old[i].second < min_c) {
      building.PB(building_old[i]);
    }
    mini(min_c, building_old[i].second);
  }
  
  reverse(ALL(building));
  n = SZ(building);
  int act_b = 0;
  ll max_c = 0;
  
  REP (i, n) {
    auto& A = building[i];
    auto B = ot[act_b];
    
    while (act_b + 1 < SZ(ot) && B.y + B.slope * min(INF / max(1ll, B.slope), B.dl) < A.second) {
      act_b++;
      B = ot[act_b];
    }
    
    ll st_x = max(0ll, B.x) + max(0ll, (A.second - B.y + B.slope - 1) / max(1ll, B.slope));
    ll st_y = B.y + (st_x - B.x) * B.slope - A.second;
    if (A.second == s) {
      cout<<st_x<<endl;
      return 0;
    }
    
    B = ot.back();
    while (B.y <= st_y + A.first * min(INF / A.first, (B.x - st_x))) {
      if (B.x < st_x) {
        break;
      }
      ot.pop_back();
      ot.back().dl = INF;
      B = ot.back();
    }
    
    ll diff_slope = A.first - B.slope;
    if (A.first == B.slope) {
      continue;
    }
    ll int_x = B.x + (B.y - (st_y + A.first * (B.x - st_x)) + diff_slope - 1) / diff_slope;
    ot.back().dl = int_x - B.x - 1;
    if (ot.back().dl < 0) {
      ot.pop_back();
    }
    ot.PB(seg(int_x, INF, st_y + (int_x - st_x) * A.first, A.first));
    
  }
   
  return 0;
}