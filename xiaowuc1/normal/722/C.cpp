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

// DID YOU FIX GLOBAL STATE

ll totalSum[100005];

ll ret[100005];

ll vals[100005];
int perm[100005];

bool seen[100005];
int p[100005];
ll pSum[100005];

int find(int x) {
  return x == p[x] ? x : (p[x] = find(p[x]));
}

void merge(int x, int y) {
  int fx = find(x);
  int fy = find(y);
  if(fx == fy) return;
  ll sx = pSum[fx];
  ll sy = pSum[fy];
  p[fx] = fy;
  pSum[fx] = sx+sy;
  pSum[fy] = sx+sy;
}

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &vals[i]);
    pSum[i] = vals[i];
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &perm[i]);
    p[i] = i;
  }
  ll maxNow = 0;
  for(int i = n; i > 0; i--) {
    if(seen[perm[i]-1]) {
      merge(perm[i], perm[i]-1);
    }
    if(seen[perm[i]+1]) {
      merge(perm[i], perm[i]+1);
    }
    seen[perm[i]] = true;
    maxNow = max(maxNow, pSum[find(perm[i])]);
    ret[i] = maxNow;
  }
  for(int i = 1; i <= n; i++) {
    printf("%lld\n", ret[i+1]);
  }
}

int main() {
  solve();
  return 0;
}