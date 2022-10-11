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

char buf[200005];

void solve() {
  int n;
  scanf("%d\n", &n);
  gets(buf);
  int ret = 0;
  int start = 0;
  while(start < n && buf[start] == '<') {
    ret++;
    start++;
  }
  start = n-1;
  while(start >= 0 && buf[start] == '>') {
    ret++;
    start--;
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}