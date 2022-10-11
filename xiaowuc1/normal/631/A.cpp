#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <memory>
#include <complex>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int get(int n) {
  int ret = 0;
  while(n--) {
    int t;
    scanf("%d", &t);
    ret |= t;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", get(n) + get(n));
  return 0;
}