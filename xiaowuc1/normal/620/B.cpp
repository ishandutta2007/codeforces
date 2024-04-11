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

int amtO[10] = {
  6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

int amt(int n) {
  int r = 0;
  while(n) {
    r += amtO[n%10];
    n /= 10;
  }
  return r;
}

void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  int r = 0;
  for(int i = a; i <= b; i++) {
    r += amt(i);
  }
  printf("%d\n", r);
}

int main() {
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}