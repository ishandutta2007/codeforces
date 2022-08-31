#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector < pair <int, int> > a(n);
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    a[i] = make_pair(foo, i + 1);
  }
  sort(a.begin(), a.end());
  vector <int> ret;
  for (int i = 0; i < n; i++) {
    if (k >= a[i].first) {
      k -= a[i].first;
      ret.push_back(a[i].second);
    }
  }
  sort(ret.begin(), ret.end());
  int sz = ret.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) printf(" ");
    printf("%d", ret[i]);
  }
  printf("\n");
  return 0;
}