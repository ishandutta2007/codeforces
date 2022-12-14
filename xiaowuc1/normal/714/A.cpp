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

ll intersect(ll a, ll b, ll c, ll d) {
  return max(0LL, min(b, d) - max(a, c) + 1);
}

void solve() {
  ll l1, r1, l2, r2, k;
  scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);
  ll ret = 0;
  if(k < l1 || k > r1) {
    ret += intersect(l1, r1, l2, r2);
  }
  else {
    ret += intersect(l1, k-1, l2, r2);
    ret += intersect(k+1, r1, l2, r2);
  }
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