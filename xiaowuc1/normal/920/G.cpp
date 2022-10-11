#include <algorithm>
#include <cassert>
// #include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
// #include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<string, string> pss;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int sieve[1000005];
void initSieve() {
  for(int i = 2; i <= 1000000; i++) {
    if(sieve[i]) continue;
    for(int j = i; j <= 1000000; j += i) {
      sieve[j] = i;
    }
  }
}

int primes[15];

ll solve(ll rhs, int n) {
  // number of integers less than or equal to rhs relatively prime to N
  ll ret = 0;
  int numP = 0;
  int x = n;
  while(x > 1) {
    if(numP > 0 && primes[numP-1] == sieve[x]) {
      x /= sieve[x];
    }
    else {
      primes[numP++] = sieve[x];
      x /= sieve[x];
    }
  }  
  for(int mask = 0; mask < (1<<numP); mask++) {
    bool sub = false;
    int curr = 1;
    for(int i = 0; i < numP; i++) {
      if(mask&(1<<i)) {
        curr *= primes[i];
        sub = !sub;
      }
    }
    ll scale = rhs / curr;
    if(sub) ret -= scale;
    else ret += scale;
  }
  return ret;
}

int main() {
  initSieve();
  int q;
  scanf("%d", &q);
  while(q--) {
    int x, p, k;
    scanf("%d%d%d", &x, &p, &k);
    // kth integer greater than x relatively prime to p
    ll baseline = solve(x, p);
    ll lhs = x;
    ll rhs = (ll)1e10;
    while(lhs != rhs) {
      ll mid = (lhs+rhs)/2;
      if(solve(mid, p) - baseline >= k) {
        rhs = mid;
      }
      else {
        lhs = mid+1;
      }
    }
    printf("%lld\n", lhs);
  }
}