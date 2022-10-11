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

ll amt[55];
ll t[55];

void solve() {
  int n, c;
  scanf("%d%d", &n, &c);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &amt[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%lld", &t[i]);
  }
  ll lhs = 0;
  ll rhs = 0;
  ll lhsT = 0;
  ll rhsT = 0;
  for(int i = 0; i < n; i++) {
    lhsT += t[i];
    rhsT += t[n-1-i];
    lhs += max(0LL, amt[i] - c * lhsT);
    rhs += max(0LL, amt[n-1-i] - c * rhsT);
  }
  if(lhs > rhs) printf("Limak\n");
  if(lhs < rhs) printf("Radewoosh\n");
  if(lhs == rhs) printf("Tie\n");
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