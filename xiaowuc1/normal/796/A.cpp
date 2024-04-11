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
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int ret = 1e9;
  for(int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if(x > 0 && x <= k) {
      ret = min(ret, max(i, m) - min(i, m));
    }
  }
  printf("%d\n", 10*ret);
}