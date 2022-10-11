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

char buf[2005];
char ret[2005];

int main() {
  int n;
  scanf("%d\n%s", &n, buf);
  int lhs, rhs;
  if(n%2) {
    ret[n/2] = buf[0];
    lhs = n/2-1;
    rhs = n/2+1;
    for(int i = 1; i < n; i++) {
      if(i%2) {
        ret[lhs--] = buf[i];
      }
      else {
        ret[rhs++] = buf[i];
      }
    }
  }
  else {
    lhs = n/2-1;
    rhs = n/2;
    for(int i = 0; i < n; i++) {
      if(i%2==0) {
        ret[lhs--] = buf[i];
      }
      else {
        ret[rhs++] = buf[i];
      }
    }
  }
  printf("%s\n", ret);
}