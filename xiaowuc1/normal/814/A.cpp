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

int n, k;

int l[105];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  for(int i = 0; i < n; i++) {
    if(l[i] == 0) {
      scanf("%d", &l[i]);
    }
  }
  if(k >= 2) {
    printf("Yes\n");
    return 0;
  }
  int amt = 0;
  for(int i = 1; i < n; i++) {
    if(l[i] > l[i-1]) amt++;
  }
  if(amt == n-1) printf("No\n");
  else printf("Yes\n");
}