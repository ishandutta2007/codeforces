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
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i=0;i<k;i++) {
    for (int j=1;j<n;j++) printf("%d ", j+(1 << i) < n ? j+(1 << i) : n);
    printf("%d\n", n);
  }
  return 0;
}