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
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int main() {
  int n, k;
  map<int, int> dp;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    dp[t]++;
  }
  while(k--) {
    int want;
    scanf("%d", &want);
    int ret = 0;
    for(map<int, int>::reverse_iterator it = dp.rbegin(); it != dp.rend(); it++) {
      int maxCan = want / it->first;
      int use = min(it->second, maxCan);
      want -= use * it->first;
      ret += use;
    }
    if(want) {
      ret = -1;
    }
    printf("%d\n", ret);
  }
}