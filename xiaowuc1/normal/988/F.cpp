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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;

/*
<location, umbrella weight> -> minimum sum
location is implicit
weight -> minimum sum
*/

map<int, ll> dp;

int length;
bool rain[2005];
bool rainBegin[2005];
bool rainEnd[2005];
int weight[2005];

void putMin(map<int, ll>& m, int k, ll v) {
  if(!m.count(k)) m[k] = v;
  else m[k] = min(m[k], v);
}

/*
0 10
1 2
3 4
8 1
*/
ll solve() {
  if(!rain[0]) {
    dp[0] = 0;
  }
  if(weight[0]) {
    dp[weight[0]] = 0;
  }
  for(int i = 1; i <= length; i++) {
    map<int, ll> nextDP;
    for(auto out: dp) {
      // printf("%d %d %lld\n", i-1, out.first, out.second);
      // unconditionally pick up this umbrella
      if(weight[i]) {
        putMin(nextDP, weight[i], out.second + out.first);
      }

      // ignore the umbrella that is present
      if(rain[i] && !rainEnd[i]) {
        if(out.first) {
          putMin(nextDP, out.first, out.second + out.first);
        }
      }
      else {
        putMin(nextDP, out.first, out.second + out.first);
        putMin(nextDP, 0, out.second + out.first);
      }
    }
    dp = nextDP;
  }
  if(dp.empty()) return -1;
  ll ret = (1LL << 60);
  for(auto out: dp) {
    ret = min(ret, out.second);
  }
  return ret;
}

int main() {
  int numSeg, numUmbrella;
  scanf("%d%d%d", &length, &numSeg, &numUmbrella);
  while(numSeg--) {
    int l, r;
    scanf("%d%d", &l, &r);
    for(int i = l; i <= r; i++) {
      rain[i] = true;
    }
    rainBegin[l] = true;
    rainEnd[r] = true;
  }
  while(numUmbrella--) {
    int loc, w;
    scanf("%d%d", &loc, &w);
    if(weight[loc] == 0) {
      weight[loc] = w;
    }
    else {
      weight[loc] = min(weight[loc], w);
    }
  }
  printf("%lld\n", solve());
}