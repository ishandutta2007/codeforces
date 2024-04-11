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

int k;
char buf[100005];

int amt[100005];

int main() {
  scanf("%d\n%s", &k, buf);
  int n = strlen(buf);
  for(int i = 0; i < n; i++) {
    amt[i] = '9' - buf[i];
    k -= (buf[i] - '0');
  }
  sort(amt, amt + n);
  int ret = 0;
  while(k > 0) {
    k -= amt[n-++ret];
  }
  printf("%d\n", ret);
}