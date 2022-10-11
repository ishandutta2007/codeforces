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
  int n;
  scanf("%d\n", &n);
  bool ret = false;
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%s%d%d", buf, &a, &b);
    ret |= a >= 2400 && b > a;
  }
  if(ret) printf("YES\n");
  else printf("NO\n");
}

int main() {
  solve();
  return 0;
}