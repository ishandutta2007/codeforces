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
#endif
#ifndef LOCAL
#define debug(x)
#define debugv(x)
#endif
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
int kan[1001 * 1001];
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  int n;
  cin>>n;
  RE (i, n) {
    cin>>kan[i];
  }
  sort(kan + 1, kan + 1 + n);
  int kl = 0, kp = n / 2, aktc, faj = 0;
  while (kl <= kp) {
    aktc = (kl + kp) / 2;
    bool ok = true;
    RE (i, aktc) {
      if (2 * kan[i] > kan[n - aktc + i]) {
        ok = false;
      }
    }
    if (ok) {
      faj = aktc;
      kl = aktc + 1;
    } else {
      kp = aktc - 1;
    }
  }
  cout<<n - faj<<endl;
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}