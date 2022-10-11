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

int n;

int g[2][6];

int main() {
  scanf("%d", &n);
  for(int a = 0; a < 2; a++) {
    for(int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      g[a][t]++;
    }
  }
  int ret = 0;
  for(int a = 0; a <= 5; a++) {
    if((g[0][a] % 2) != (g[1][a] % 2)) {
      printf("-1\n");
      return 0;
    }
    ret += max(g[0][a], g[1][a]) - min(g[0][a], g[1][a]);
  }
  printf("%d\n", ret/4);
}