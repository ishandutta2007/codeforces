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

int x[3];
int y[3];

void solve() {
  scanf("%d%d", &x[0], &y[0]);
  scanf("%d%d", &x[1], &y[1]);
  scanf("%d%d", &x[2], &y[2]);
  if(x[0] == x[1] && x[1] == x[2]) {
    printf("1\n");
    return;
  }
  if(y[0] == y[1] && y[1] == y[2]) {
    printf("1\n");
    return;
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < i; j++) {
      int k = 0;
      while(i == k || j == k) k++;
      if(y[k] < min(y[i], y[j]) || y[k] > max(y[i], y[j])) continue;
      if(x[k] < min(x[i], x[j]) || x[k] > max(x[i], x[j])) continue;
      if(y[k] != y[i] && y[k] != y[j] && x[k] != x[i] && x[k] != x[j]) continue;
      printf("2\n");
      return;
    }
  }
  printf("3\n");
}

int main() {
  solve();
  return 0;
}