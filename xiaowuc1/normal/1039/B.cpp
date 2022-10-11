#include <algorithm>
#include <cassert>
#include <chrono>
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
#include <random>
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

char buf[10];

void guess(ll lhs, ll rhs) {
  printf("%lld %lld\n", lhs, rhs);
  fflush(stdout);
}

int main() {
  unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
  mt19937 g1;
  g1.seed(seed1);
  ll n, k;
  scanf("%lld%lld", &n, &k);
  ll lhs = 1;
  ll rhs = n;
  while(true) {
    if(rhs - lhs <= 4*k) {
      int sz = rhs - lhs + 1;
      int inc = g1() % sz;
      if(inc < 0) inc += sz;
      guess(lhs + inc, lhs + inc);
      scanf("%s", buf);
      if(buf[0] == 'Y') return 0;
      assert(buf[0] == 'N');
    }
    else {
      ll mid = (lhs+rhs)/2;
      guess(lhs, mid);
      scanf("%s", buf);
      if(buf[0] == 'Y') rhs = mid;
      else {
        assert(buf[0] == 'N');
        lhs = mid+1; 
      }
    }
    lhs = max(1LL, lhs-k);
    rhs = min(n, rhs+k);
  }
}