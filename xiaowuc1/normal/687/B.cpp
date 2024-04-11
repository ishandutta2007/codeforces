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

ll gcd(ll a, ll b) {
  return a%b == 0 ? b : gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  // gcd(a,b) * lcm(a,b) == a*b;
  return a / gcd(a,b) * b;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  ll lastVal = 1;
  for(int i = 0; i < n; i++) {
    ll curr;
    scanf("%lld", &curr);
    lastVal = lcm(lastVal, curr);
    lastVal = gcd(lastVal, k);
  }
  if(lastVal == k) {
    printf("Yes\n");
  }
  else {
    printf("No\n");
  }
  return 0;
}