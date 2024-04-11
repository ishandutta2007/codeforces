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

bool prime(int n) {
  for(int i = 2; i * i <= n; i++) {
    if(n%i==0) return false;
  }
  return true;
}

void solve() {
  int n;
  scanf("%d", &n);
  if(prime(n)) {
    printf("1\n");
    return;
  }
  if(prime(n-2)) {
    printf("2\n");
    return;
  }
  printf("%d\n", 2 + (n%2));
}

int main() {
  solve();
  return 0;
}