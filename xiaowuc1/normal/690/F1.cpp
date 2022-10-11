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

int amt[10005];
void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    amt[a]++;
    amt[b]++;
  }
  int ret = 0;
  for(int i = 1; i <= n; i++) {
    int l = amt[i];
    ret += (l * (l-1)) / 2;
  }
  printf("%d\n", ret);
}

int main() {
  solve();
  return 0;
}