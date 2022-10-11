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
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

const double PI = 2 * acos(0);
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int two, three;
  scanf("%d%d", &two, &three);
  int left = 1;
  int right = 1e9;
  while(left < right) {
    int mid = (left+right)/2;
    int twoPure = mid / 2 - mid / 6;
    int threePure = mid / 3 - mid / 6;
    int twoLeft = max(0, two - twoPure);
    int threeLeft = max(0, three - threePure);
    if(twoLeft + threeLeft <= mid / 6) {
      right = mid;
    }
    else {
      left = mid+1;
    }
  }
  printf("%d\n", left);
}

int main() {
  solve();
  return 0;
}