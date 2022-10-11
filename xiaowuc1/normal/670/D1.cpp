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
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

const int MOD = 1000000007;

ll a[100005];
ll b[100005];

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%lld", &b[i]);
  }
  int lhs = 0;
  int rhs = 2000000000;
  while(lhs < rhs) {
    int mid = (int)((lhs+(ll)rhs+1)/2);
    ll need = 0;
    for(int i = 0; i < n && need <= k; i++) {
      need += max(0LL, a[i] * mid - b[i]);
    }
    if(need <= k) lhs = mid;
    else rhs = mid-1;
  }
  printf("%d\n", lhs);
}

int main() {
  solve();
  return 0;
}