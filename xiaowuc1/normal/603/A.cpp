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
typedef pair<int, pii> pipii;

const int MOD = 1000000007;

int n;
char buf[100005];

void solve() {
  scanf("%d\n", &n);
  gets(buf);
  int ret = 1;
  for(int i = 1; i < n; i++) {
    if(buf[i] != buf[i-1]) {
      ret++;
    }
  }
  printf("%d\n", min(ret + 2, n));
}

int main() {
  solve();
  return 0;
}