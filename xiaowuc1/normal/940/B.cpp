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

int n, k;

int main() {
  ll a, b;
  scanf("%d %d %lld %lld", &n, &k, &a, &b);
  ll ret = (n-1) * a;
  if(k == 1) {
    printf("%lld\n", ret);
    return 0;
  }
  ll curr = 0;
  while(n > 1) {
    if(n % k == 0) {
      n /= k;
      curr += b;
    }
    else {
      curr += a * (n%k);
      n -= n%k;
    }
    ret = min(ret, curr + (n-1) * a);
  }
  printf("%lld\n", ret);
}