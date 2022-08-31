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

const int N = 1e5 + 13;
ll seq[N];
ll input[5 * N];
ll que[N];
int pos;
void pob() {
  pos++;
  cin>>input[pos];
}
int pos_read;
int czyt() {
  pos_read++;
  return input[pos_read];
}
ll dl;
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, m);
  RE (i, m) {
    pob();
    if (input[pos] == 1) {
      pob();
    } else {
      pob();
      pob();
    }
  }
  make(int, n);
  RE (i, n) {
    cin>>que[i];
  }
  que[n + 1] = 1e18;
  int pos_que = 1;
  RE (i, m) {
    int type = czyt();
    if (type == 1) {
      int nowa = czyt();
      dl++;
      if (dl < N - 2) {
        seq[dl] = nowa;
      }
      if (que[pos_que] == dl) {
        cout<<nowa<<" ";
        pos_que++;
      }
    } else {
      ll c = czyt();
      ll l = czyt();
      while (que[pos_que] <= dl + l * c) {
        ll kt = que[pos_que] - dl;
        cout<<seq[(kt - 1) % c + 1]<<" ";
        pos_que++;
      }
      int tmp = 0;
      while (dl + tmp < N - 2) {
        tmp++;
        seq[dl + tmp] = seq[(tmp - 1) % c + 1];
      }
      dl += l * c;
    }
  }
  cout<<"\n";
      
  
  
  // nie zapomnij o ll
  return 0;
}