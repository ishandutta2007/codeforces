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

int n;
int colors[5005];

int ret[5005];

int numAppear[5005];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &colors[i]);
  }
  for(int lhs = 0; lhs < n; lhs++) {
    memset(numAppear, 0, sizeof(numAppear));
    int dominantColor = -1;
    int dominantCount = 0;
    for(int rhs = lhs; rhs < n; rhs++) {
      numAppear[colors[rhs]]++;
      if(numAppear[colors[rhs]] > dominantCount || (numAppear[colors[rhs]] == dominantCount && colors[rhs] < dominantColor)) {
        dominantColor = colors[rhs];
        dominantCount = numAppear[dominantColor];
      }
      ret[dominantColor]++;
    }
  }
  for(int i = 1; i <= n; i++) {
    printf("%d ", ret[i]);
  }
  printf("\n");
  return 0;
}