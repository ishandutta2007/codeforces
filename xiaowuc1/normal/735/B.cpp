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

const double PI = 2 * acos(0);
typedef long long ll;

int n, k1, k2;

ll amt[100005];

void solve() {
  scanf("%d%d%d", &n, &k1, &k2);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &amt[i]);
    amt[i] *= -1;
  }
  sort(amt, amt+n);
  double ret = 0;
  for(int i = 0; i < n; i++) {
    if(i < min(k1, k2)) {
      ret -= amt[i] * 1.0 / min(k1, k2);
    }
    else if(i < k1+k2) {
      ret -= amt[i] * 1.0 / max(k1, k2);
    }
  }
  printf("%.8f\n", ret);
}

int main() {
  solve();
  return 0;
}