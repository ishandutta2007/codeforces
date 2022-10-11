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

ll solve(ll a, ll b, ll c) {
  ll fullDays = max(a-1, max(b-1, c));
  ll ret = 0;
  if(fullDays > a) {
    ret += fullDays - a;
    a = 0;
  }
  else {
    a -= fullDays;
  }
  if(fullDays > b) {
    ret += fullDays - b;
    b = 0;
  }
  else {
    b -= fullDays;
  }
  if(fullDays > c) {
    ret += fullDays - c;
    c = 0;
  }
  else {
    c -= fullDays;
  }
  if(c > 0) {
    if(a == 0) ret++;
    if(b == 0) ret++;
    return ret;
  }
  if(b > 0) {
    if(a == 0) ret++;
    return ret;
  }
  return ret;
}

void solve() {
  ll a, b, c;
  scanf("%lld", &a);
  scanf("%lld", &b);
  scanf("%lld", &c);
  ll ret = solve(a, b, c);
  ret = min(ret, solve(b, c, a));
  ret = min(ret, solve(c, a, b));
  printf("%lld\n", ret);
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