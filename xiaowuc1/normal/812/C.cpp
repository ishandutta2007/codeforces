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

typedef long long ll;
typedef pair<int, int> pii;

int l[100005];
int actual[100005];

int n, maxAmt;

int solve(int num) {
  for(int i = 0; i < n; i++) {
    actual[i] = min((ll)1.05e9, l[i] + (i+1LL) * num);
  }
  sort(actual, actual+n);
  int ret = 0;
  for(int i = 0; i < num; i++) {
    ret = min(maxAmt+1, ret + actual[i]);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &maxAmt);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  int lhs = 0;
  int rhs = n;
  int ret = 0;
  while(lhs != rhs) {
    int mid = (lhs+rhs+1)/2;
    int amt = solve(mid);
    if(amt <= maxAmt) {
      lhs = mid;
      ret = amt;
    }
    else {
      rhs = mid-1;
    }
  }
  printf("%d %d\n", lhs, ret);
}