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
const double PI = 2 * acos(0);
const int MOD = 1000000007;

int n;
int orig[200005];
int ret[200005];

void solve() {
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &orig[i]);
    ret[i] = orig[i];
  }
  vector<pii> ops;
  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &b, &a);
    while(!ops.empty() && ops[ops.size()-1].first <= a) {
      ops.pop_back();
    }
    ops.push_back(pii(a, b));
  }
  ops.push_back(pii(0, 1));
  sort(orig, orig + ops[0].first);
  int lhs = 0;
  int rhs = ops[0].first-1;
  int nextIndex = ops[0].first-1;
  for(int i = 1; i < ops.size(); i++) {
    while(nextIndex >= ops[i].first) {
      if(ops[i-1].second == 1) {
        ret[nextIndex--] = orig[rhs--];
      }
      else {
        ret[nextIndex--] = orig[lhs++];
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}