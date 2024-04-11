#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

map<ll, pll> dp;

pll gen(ll n) {
  if(n == 0) {
    return pll(1, 0);
  }
  if(n == 1) {
    return pll(0, 1);
  }
  if(dp.count(n)) {
    return dp[n];
  }
  pll ret = gen(n/2);
  ret.first *= 2;
  ret.second *= 2;
  if(n%2) {
    ret.second++;
  }
  else {
    ret.first++;
  }
  dp[n] = ret;
  return ret;
}

// first is zero count
// second is one count

ll solve(ll n, ll num) {
  if(num == 0) return 0;
  pll curr = gen(n);
  if(curr.first + curr.second <= num) {
    return curr.second;
  }
  assert(n > 1);
  pll lhs = gen(n/2);
  ll ret = 0;
  if(lhs.first + lhs.second >= num) {
    return solve(n/2, num);
  }
  ret = lhs.second;
  num -= lhs.first + lhs.second;
  assert(num > 0);
  num--;
  if(n%2 == 1) {
    ret++;
  }
  return ret + solve(n/2, num);
}

int main() {
  ll n, lhs, rhs;
  scanf("%lld%lld%lld", &n, &lhs, &rhs);
  gen(n);
  printf("%lld\n", solve(n, rhs) - solve(n, lhs-1));
}