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
vector<int> leafs;
vector<int> non_leafs;
bool rec(vector<int> subtrees, vector<int> non_used) {
  int sum = 0;
  for (int a : non_used) {
    sum += a;
  }
  if (sum == 0) {
    if (subtrees.size() == 1) {
      return true;
    } else {
      return false;
    }
  }
  if (subtrees.size() == 0) {
    return false;
  }
  for (int j = 0; j < non_used.size(); j++) {
    int sub_size = non_used[j];
    int sub_size_copy = sub_size;
    if (sub_size == 0) {
      continue;
    }
    non_used[j] = 0;
    vector<int> new_vec;
    sub_size--;
    int subtracts = 0;
    for (auto i = 0; i < subtrees.size(); i++) {
      int child_size = subtrees[i];
      if (child_size > sub_size) {
        new_vec.PB(child_size);
        continue;
      } else {
        subtracts++;
        sub_size -= child_size;
      }
    }
    if (sub_size == 0 && subtracts > 1) {
      new_vec.PB(sub_size_copy);
      sort(ALL(new_vec), greater<int>());
      if (rec(new_vec, non_used)) {
        return true;
      }
    } 
    non_used[j] = sub_size_copy;
  }
  return false;
}

int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  RE (i, n) {
    make(int, c);
    if (c == 1) {
      leafs.PB(1);
    } else {
      non_leafs.PB(c);
    }
  }
  
  random_shuffle(ALL(non_leafs));
  if (rec(leafs, non_leafs)) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}