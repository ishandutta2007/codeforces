#include <iostream>
#include <iomanip>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  if (k - 1 <= n - k) {
    for (int i = k - 1; i >= 1; i--) puts("LEFT");
    for (int i = 0; i < n; i++) {
      printf("PRINT %c\n", s[i]);
      if (i < n - 1) {
        puts("RIGHT");
      }
    }
  } else {
    for (int i = k + 1; i <= n; i++) puts("RIGHT");
    for (int i = n - 1; i >= 0; i--) {
      printf("PRINT %c\n", s[i]);
      if (i > 0) {
        puts("LEFT");
      }
    }
  }
  return 0;
}