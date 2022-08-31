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

const int M = 1e9 + 7;
const int N = 1e5 + 7;
int view_num[N];
ll pot[N];
int where_ith[N];

struct FastNewton{
  long long P;
  long long range;
  vector<long long> inv;
  vector<long long> fact;
  vector<long long> fact_inv;
  vector<long long> v_p;
  
  FastNewton (long long _P, long long _range = 0) {
    init(_P, _range);
  }
  
  // Initialize structures to support computing n choose k mod _P, where n <= range
  void init(long long _P, long long _range = -1) {
    P = _P;
    if (_range == -1) {
      range = P;
    } else {
      range = _range;
    }
    inv.resize(range + 5);
    fact.resize(range + 5);
    fact_inv.resize(range + 5);
    v_p.resize(range + 5);
    fact[0] = 1;
    fact_inv[0] = 1;
    inv[0] = -1;
    inv[1] = 1;
    for (int i = 2; i < min(range, P); i++) {
      inv[i] = P - (P / i) * inv[P % i] % P;
    }
    for (int i = 1; i <= range; i++) {
      ll tmp = i;
      while (tmp % P == 0) {
        tmp /= P;
      }
      fact[i] = tmp * fact[i - 1] % P;
      fact_inv[i] = fact_inv[i - 1] * inv[tmp] % P;
    }
    for (int i = 1; i <= range; i++) {
      v_p[i] = i / P + v_p[i / P];
    }
  }
  
  long long get_inv(long long a) {
    if (a % P == 0) {
      cout<<"ERROR: 0 has not got its inverse\n";
      return -1;
    }
    return inv[a % P];
  }
  
  long long get_normal_fact(long long n) {
    if (n >= P) {
      return 0;
    }
    return fact[n];
  }
  
  long long get_better_fact(long long n) {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return fact[n];
  }
  
  long long get_v_p(long long n) {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return v_p[n];
  }
  
  long long choose(long long n, long long k) {
    if (k < 0 || k > n) {
      return 0;
    }
    if (v_p[n] == v_p[k] + v_p[n - k]) {
      return fact[n] * fact_inv[k] % P * fact_inv[n - k] % P;
    } else {
      return 0;
    }
  }
  
};


FastNewton Newt_mod_M(M, N);

ll calc(int n) {
  ll res = 1;
  int prev = 0;
  int prev_l = 0;
  int prev_r = 0;
  RE (i, n) {
    if (where_ith[i] == 0) {
      continue;
    }
    if (where_ith[i] >= prev_l && where_ith[i] <= prev_r) {
      return 0;
    }
    if (prev == 0) {
      res = pot[max(0, i - 2)];
      prev_r = where_ith[i];
      prev_l = prev_r - i + 1;
      prev = i;
      continue;
    }
    int act_l, act_r;
    if (where_ith[prev] < where_ith[i]) {
      act_r = where_ith[i];
      act_l = act_r - i + 1;
    } else {
      act_l = where_ith[i];
      act_r = act_l + i - 1;
    }
    
    
    if (act_l > prev_l || act_r < prev_r || act_r > n || act_l < 0) {
      return 0;
    }
    int left_len = prev_l - act_l;
    int right_len = act_r - prev_r;
    if (where_ith[i] == act_r) {
      right_len--;
    } else {
      left_len--;
    }
    res *= Newt_mod_M.choose(left_len + right_len, left_len);
    res %= M;
    prev_l = act_l;
    prev_r = act_r;
    prev = i;
  }
  return res;
}

  
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  make(int, n);
  view_num[1] = n + 1;
  RE (i, n) {
    cin>>view_num[i + 1];
  }
  n += 2;
  view_num[n] = n;
  pot[0] = 1;
  RE (i, N - 2) {
    pot[i] = 2 * pot[i - 1] % M;
  }
  ll res = 0;
  RE (i, n) {
    if (view_num[i] != 0) {
      where_ith[view_num[i]] = i;
    }
  }
  res += calc(n);
  if (where_ith[1] == 0) {
    RE (i, n) {
      if (where_ith[i] != 0) {
        where_ith[i] = n + 1 - where_ith[i];
      }
    }
    res += calc(n);
  }
  cout<<res % M<<endl;

  
  // nie zapomnij o ll
  return 0;
}