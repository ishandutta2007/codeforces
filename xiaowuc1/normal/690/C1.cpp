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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int p[1005];

int find(int x) {
  return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
  p[find(x)] = find(y);
}

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  if(n - 1 != m) {
    printf("no\n");
    return;
  }
  for(int i = 1; i <= n; i++) {
    p[i] = i;
  }
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(find(a) == find(b)) {
      printf("no\n");
      return;
    }
    merge(a, b);
  }
  printf("yes\n");
}

int main() {
  solve();
  return 0;
}