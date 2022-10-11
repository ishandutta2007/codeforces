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
int a[105];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += a[i];
  }
  if(sum != 0) {
    printf("YES\n");
    printf("1\n");
    printf("1 %d\n", n);
    return 0;
  }
  int leftSum = 0;
  for(int i = 0; i < n; i++) {
    leftSum += a[i];
    if(leftSum != 0) {
      printf("YES\n");
      printf("2\n");
      // 0 to i
      // 1 to i+1
      printf("1 %d\n", i+1);
      printf("%d %d\n", i+2, n);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}