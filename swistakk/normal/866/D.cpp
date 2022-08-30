/* Zadanie GIE
 * Rozwiazanie wzorcowe O(n log n)
 * Autor: Wojtek Nadara
 * Data: 05.01.2015
 */

#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
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
const int INF = 1e9 + 5;
int res[N];
int MinSet(set<PII>& secik) {
  if (secik.empty()) { return INF; }
  return secik.begin()->first;
}

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  
  set<PII> zero_set, sold_set;
  make(int, n);
  int profit = 0;
  RE (i, n) {
    make(int, c);
    if (MinSet(sold_set) < c || MinSet(zero_set) < c) {
      profit += c;
      res[i] = -1;
      if (MinSet(sold_set) < MinSet(zero_set)) {
        PII sold = *(sold_set.begin());
        sold_set.erase(sold_set.begin());
        profit -= sold.st;
        res[sold.nd] = 0;
        zero_set.insert(sold);
      } else {
        PII zero = *(zero_set.begin());
        zero_set.erase(zero_set.begin());
        profit -= zero.st;
        res[zero.nd] = 1;
      }
      sold_set.insert(MP(c, i));
    } else {
      zero_set.insert(MP(c, i));
    }
  }
  cout<<profit<<"\n";
//   RE (i, n) {
//     cout<<res[i]<<" ";
//   }
//   cout<<"\n";

  return 0;
}