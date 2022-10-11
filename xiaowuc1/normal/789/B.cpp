#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

set<ll> bad;

int main() {
  ll start, ratio, maxVal;
  int n;
  scanf("%lld%lld%lld%d\n", &start, &ratio, &maxVal, &n);
  while(n--) {
    ll x;
    scanf("%lld", &x);
    bad.insert(x);
  }
  int ret = 0;
  int iter = 0;
  while(iter++ <= 1e6 && start >= -maxVal && start <= maxVal) {
    if(!bad.count(start)) {
      ret++;
    }
    start *= ratio;
  }
  if(ret >= 1e4) {
    printf("inf\n");
  }
  else {
    printf("%d\n", ret);
  }
}