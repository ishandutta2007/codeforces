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

int main() {
  int n;
  scanf("%d", &n);
  int x = 0;
  while(n--) {
    int t;
    scanf("%d", &t);
    x += t;
  }
  int qqq;
  scanf("%d", &qqq);
  while(qqq--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if(x <= r) {
      printf("%d\n", max(l, x));
      return 0;
    }
  }
  printf("-1\n");
}