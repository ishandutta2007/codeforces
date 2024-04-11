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

int l[100005];
int ret[100005];

void solve() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  ret[n-1] = l[n-1];
  for(int i = n-2; i >= 0; i--) {
    ret[i] = l[i] + l[i+1];
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