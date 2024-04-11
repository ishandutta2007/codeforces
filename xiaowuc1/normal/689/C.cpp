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

ll solve(ll n) {
  ll ret = 0;
  ll d = 2;
  while(d*d*d <= n) {
    ret += n/(d*d*d);
    d++;
  }
  return ret;
}

int main() {
  ll n;
  scanf("%lld", &n);
  ll lhs = 1;
  ll rhs = (ll)1e16;
  while(lhs < rhs) {
    ll mid = (lhs+rhs)/2;
    if(solve(mid) >= n) {
      rhs = mid;
    }
    else {
      lhs = mid+1;
    }
  }
  if(solve(lhs) != n) lhs = -1;
  printf("%lld\n", lhs);
}