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

bool can[100005];
void solve() {
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  can[0] = true;
  for(int i = 0; i < n; i++) {
    if(can[i]) can[i+a] = true;
    if(can[i]) can[i+b] = true;
  }
  if(can[n]) printf("Yes\n");
  else printf("No\n");
}

int main() {
  solve();
  return 0;
}