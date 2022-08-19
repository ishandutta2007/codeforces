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

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int cur = 0, pt = 0, mx = 0;
  for (int i=0;i<n;i++) {
    int t, c;
    scanf("%d %d", &t, &c);
    cur -= (t-pt);
    if (cur < 0) cur = 0;
    cur += c;
    if (cur > mx) mx = cur;
    pt = t;
  }
  printf("%d %d\n", pt+cur, mx);
  return 0;
}