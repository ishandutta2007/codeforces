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

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

void solve() {
  ll n;
  scanf("%lld", &n);
  if(n < 3) {
    printf("-1\n");
    return;
  }
  int amt = 0;
  while(n%2 == 0) {
    n /= 2;
    amt++;
  }
  ll lhs = (n*n)/2;
  ll rhs = lhs+1;
  if(n == 1) {
    lhs = 3;
    rhs = 5;
    amt -= 2;
  }
  while(amt-- > 0) {
    lhs *= 2;
    rhs *= 2;
  }
  printf("%lld %lld\n", lhs, rhs);
}

int main() {
  /*
  freopen("integral.in","r",stdin);
  freopen("integral.out","w",stdout);
  */
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}