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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

// DID YOU FIX GLOBAL STATE

int l[100005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  sort(l, l+n);
  int ret = 0;
  const int MOD = 10007;
  for(int i = 0; i < n; i++) {
    int curr = l[i] % MOD;
    curr *= l[n-1-i];
    curr %= MOD;
    ret += curr;
    ret %= MOD;
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}