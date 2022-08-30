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
#define int long long
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::sort;
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
const int N = 1e5 + 5;
vector<int> cand[N];
int votes[N];
vector<PII> all;
bool cmp(int a, int b) {
  return cand[a].size() > cand[b].size();
}
vector<int> vec[N];
int per[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    make2(int, a, b);
    cand[a].PB(b);
    votes[a]++;
    /* if (a != 0) {
      all_votes.PB(MP(b, a));
    } */
  }
  FORD (i, N - 2, 0) {
    //votes[i] -= votes[0];
    sort(ALL(cand[i]), greater<int>());
  }
  //sort(ALL(all_votes), greater<int>());
//   int best = 1e18;
//   int bribed = 0;
//   set<int> valid;
//   for (int i = 1; i <= N - 2; i++) {
//     if (votes[i] >= votes[0]) {
//       valid.insert(i);
//     }
//     for (int j = 0; j < votes[0] - 1; j++) {
//       all_votes.PB(MP(votes[i][j], j));
//     }
//     for (int j = votes[0] - 1; j < votes[i].size(); i++) {
//       act_cost += votes[i][j];
//       bribed++;
//     } 
//   }
//   int best = act;
//   int my_votes = votes[0];
//   for (int their_votes = votes[0] - 1; their_votes <= N - 2; their_votes++) {
  for (int i = 1; i <= N - 2; i++) {
    per[i] = i;
  }
  int act_cost = 0;
  sort(per + 1, per + N - 3, cmp);
  for (int i = 1; i <= N - 2; i++) {
    for (int j = 0; j < cand[per[i]].size(); j++) {
      vec[i].PB(cand[per[i]][j]);
      act_cost += vec[i].back();
    }
    if (vec[i].size()) {
      debugv(vec[i]);
    }
  }
//   int how_many_over = 0;
  multiset<int> all_votes;
  int best = act_cost;
  int my_act_votes = n;
  
  for (int their_votes = 1; their_votes <= n - 1; their_votes++) {
    //cerr<<their_votes<<endl;
    for (int i = 1; vec[i].size() >= their_votes; i++) {
      all_votes.insert(vec[i][their_votes - 1]);
      my_act_votes--;
      act_cost -= vec[i][their_votes - 1];
    }
    while (their_votes >= my_act_votes) {
      auto it = all_votes.begin();
      my_act_votes++;
      act_cost += *it;
      all_votes.erase(it);
    }
    mini(best, act_cost);
  }
  cout<<best<<endl;
      
    
      
      
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}