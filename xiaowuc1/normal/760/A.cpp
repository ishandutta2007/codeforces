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
typedef pair<ll, ll> pllll;

int numDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  m--;
  int ret = 1;
  for(int i = 1; i < numDays[n]; i++) {
    if((m+i)%7 == 0) {
      ret++;
    }
  }
  printf("%d\n", ret);
  return 0;
}