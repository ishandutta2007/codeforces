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

map<int, int> mapka;
const int INF = 1e9 + 5;
const ll N = 2e6 + 5;
const ll M = (1 << 20);
ll act[N];
ll inv[N][2];
ll drz[2 * M + 5];
vector<ll> in;
void dod(int a, int v) {
  a += M;
  while (a) {
    drz[a] += v;
    a >>= 1;
  }
}
int czyt(int a, int b) {
  //assert(a >= 1 && a <= M - 2);
  //assert(b >= 1 && b <= M - 2);
  a += M;
  b += M;
  int sum = 0;
  sum = drz[a];
  if (a != b) {
    sum += drz[b];
  }
  while ((a >> 1) != (b >> 1)) {
    if (!(a & 1)) {
      sum += drz[a + 1];
    }
    if (b & 1) {
      sum += drz[b - 1];
    }
    a >>= 1;
    b >>= 1;
  }
  return sum;
}



void cnt_inv(vector<int>& to_fill, int l, int r, int ind) {
  if (l == r) {
    to_fill.PB(in[l]);
    return;
  }
  vector<int> left, right;
  int len = r - l + 1;
  int mid = (l + r) / 2;
  cnt_inv(left, mid + 1, r, ind);
  cnt_inv(right, l, (l + r) / 2, ind);
  int left_pos = 0, right_pos = 0;
  left.PB(INF);
  right.PB(INF);
  while (left_pos < left.size() && right_pos < right.size()) {
    int lv = left[left_pos];
    int rv = right[right_pos];
    to_fill.PB(min(lv, rv));
    if (lv < rv) {
      left_pos++;
    } else {
      right_pos++;
      if (rv < INF) {
        inv[len][ind] += left_pos;
      }
    }
  }
  while (to_fill.back() == INF) {
    to_fill.pop_back();
  }
}

int main() {
  // nie zapomnij o ll
  //ios_base::sync_with_stdio(0);
  //cout << fixed << setprecision(10);
  int n;
  scanf("%d", &n);
  //make(int, n)
  n = (1 << n);
  
  RE (i, n) {
    int a;
    scanf("%d", &a);
    //make(ll, a);
    in.PB(a);
  }
  vector<int> v;
  cnt_inv(v, 0, n - 1, 0);
  //cout<<"b"<<endl;
  reverse(ALL(in));
  cnt_inv(v, 0, n - 1, 1);
  //cout<<"c"<<endl;
  
  
  ll res = 0;
  RE (i, n) {
    res += inv[i][0];
  }
  int m;
  scanf("%d", &m);
  //make(ll, m)
  RE (i, m) {
    int qq;
    scanf("%d", &qq);
    //make(ll, q)
    RE (qqq, qq) {
      int q = qqq;
      q = (1 << q);
      res -= inv[q][act[q]];
      act[q] = 1 - act[q];
      res += inv[q][act[q]];
      //debug(q);
      //debug(act[q]);
      
    }
    printf("%I64d\n", res);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}