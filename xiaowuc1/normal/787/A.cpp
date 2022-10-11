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

int a, b, c, d;

int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  int i = 0;
  int j = 0;
  while(i < 1e5 && j < 1e5) {
    if(b+i*a == d+c*j) {
      printf("%d\n", b+i*a);
      return 0;
    }
    if(b+i*a < d+c*j) {
      i++;
    }
    else {
      j++;
    }
  }
  printf("-1\n");
}