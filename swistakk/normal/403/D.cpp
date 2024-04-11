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

struct FastNewton {
 private:
  long long P;
  long long range;
  vector<long long> inv;
  vector<long long> fact;
  vector<long long> fact_inv;
  vector<long long> v_p;
 
 public:
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
  
  long long get_inv(long long a) const {
    if (a % P == 0) {
      cout<<"ERROR: 0 has not got its inverse\n";
      return -1;
    }
    return inv[a % P];
  }
  
  // Computes n! mod P
  long long get_normal_fact(long long n) const {
    if (n >= P) {
      return 0;
    }
    return fact[n];
  }
  
  // Computes n!/p^(v_p(n!)) mod P
  long long get_better_fact(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return fact[n];
  }
  
  // Computes largest k such that p^k | n!
  long long get_v_p(long long n) const {
    if (n > range) {
      cout<<"ERROR: n too large\n";
      return -1;
    }
    return v_p[n];
  }
  
  // Computes (n choose k) mod p
  long long choose(long long n, long long k) const {
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
const int M = 1e9 + 7;
#ifndef LOCAL
const int H = 46;
const int N = 1e3 + 50;
#else
const int N = 6;
const int H = 3;
#endif


int dp[N + 2][H + 2][N + 2];
int was[N][N];
int main() {
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  FastNewton newt(M, N);
  
  REP (last, N) {
    dp[0][0][last] = 1;
  }
  
  // sum_pref[0][0][0] = 1;
  RE (cnt, H) {
//     REP (i, N) {
//       REP (j, N) {
//         sum_pref[i][cnt & 1][j] = 0;
//       }
//     }
    
    RE (last, N) {
      RE (s, N) {
        /* if (s == 5 && cnt == 2 && last == 4) {
          cerr<<dp[s][cnt][last - 1]<<" XXX "<<dp[s - last][cnt - 1][last - 1]<<endl;
        } */
        dp[s][cnt][last] = dp[s][cnt][last - 1];
        if (s - last < 0) {
          continue;
        }
        dp[s][cnt][last] += dp[s - last][cnt - 1][last - 1];
        dp[s][cnt][last] %= M;
//         debug(s);
//         debug(cnt);
//         debug(last);
//         debug(dp[s][cnt][last]);
//         dp[s][cnt][last] += sum_pref[s - last][(cnt - 1) & 1][last - 1];
//         dp[s][cnt][last] %= M;
//         sum_pref[s][cnt & 1][last] = (dp[s][cnt][last] + sum_pref[s][cnt & 1][last - 1]) % M;
      }
    }
  }
  
  
  
  
  
  
  make(int, t);
  RE (i, t) {
    make2(int, n, k);
    if (k * (k + 1) / 2 > n) {
      cout<<"0\n";
      continue;
    }
    if (was[n][k]) {
      cout<<was[n][k]<<"\n";
      continue;
    }
    
    
    ll res = 0;
    
    FOR (s, 0, n) {
//       debug(s + k);
//       debug(k);
//       debug(newt.choose(n - s, k));
//       debug(dp[s + k][k][N]);
      res += dp[s + k][k][N] * newt.choose(n - s, k);
      res %= M;
    }
    
    res *= newt.get_normal_fact(k);
    res %= M;
    was[n][k] = res;
    cerr<<"WYNIK DLA N="<<n<<" K="<<k<<"\n";
    cout<<res<<"\n";
  }
      
    
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  // nie zapomnij o ll
  return 0;
}