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

char s[1234567];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int total = 0;
  int pos = -1;
  for (int i = 0; i < n; i++) {
    total += (s[i] == '(' ? 1 : -1);
    if (s[i] == '#') {
      pos = i;
    }
  }
  if (total < 0) {
    printf("%d\n", -1);
    return 0;
  }
  int last = 1 + total;
  total = 0;
  for (int i = 0; i < n; i++) {
    total += (i == pos ? -last : (s[i] == '(' ? 1 : -1));
    if (total < 0) {
      printf("%d\n", -1);
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      if (i == pos) {
        printf("%d\n", last);
      } else {
        printf("%d\n", 1);
      }
    }
  }
  return 0;
}