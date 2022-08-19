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
  int n, p;
  scanf("%d %d", &n, &p);
  scanf("%s", s);
  for (int i = n - 1; i >= 0; i--) {
    for (char c = s[i] + 1; c < 'a' + p; c++) {
      if (i - 1 >= 0 && s[i - 1] == c) {
        continue;
      }
      if (i - 2 >= 0 && s[i - 2] == c) {
        continue;
      }
      if (p == 2 && n > 2) {
        continue;
      }
      if (p == 1 && n > 1) {
        continue;
      }
      for (int j = 0; j < n; j++) {
        if (j < i) {
          putchar(s[j]);
          continue;
        }
        if (j == i) {
          s[i] = c;
          putchar(s[i]);
          continue;
        }
        for (char c = 'a'; c < 'a' + p; c++) {
          if (j - 1 >= 0 && s[j - 1] == c) {
            continue;
          }
          if (j - 2 >= 0 && s[j - 2] == c) {
            continue;
          }
          s[j] = c;
          break;
        }
        putchar(s[j]);
      }
      printf("\n");
      return 0;
    }
  }
  puts("NO");
  return 0;
}