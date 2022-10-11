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

typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ret = 1;
  for(int i = 2; i <= min(a, b); i++) {
    ret *= i;
  }
  printf("%d\n", ret);
}