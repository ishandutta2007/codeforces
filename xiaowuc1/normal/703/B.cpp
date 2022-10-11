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

ll l[100005];

void solve() {
  int n;
  scanf("%d", &n);
  int k;
  scanf("%d", &k);
  ll tot = 0;
  for(int i = 0; i < n; i++) {
    scanf("%lld", &l[i]);
    tot += l[i];
  }
  ll ret = 0;
  set<int> s;
  for(int i = 0; i < k; i++) {
    int t;
    scanf("%d", &t);
    s.insert(--t);
  }
  for(auto x: s) {
    ret += l[x] * (tot - l[x]);
    tot -= l[x];
    int y = (x+1)%n;
  }
  for(int i = 0; i < n; i++) {
    int j = (i+1)%n;
    if(!s.count(i) && !s.count(j)) {
      ret += l[i] * l[j];
    }
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