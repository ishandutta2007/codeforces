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

char s[123456];
char dir[42];

int main() {
  string w[3];
  w[0] = "qwertyuiop";
  w[1] = "asdfghjkl;";
  w[2] = "zxcvbnm,./";
  scanf("%s", dir);
  scanf("%s", s);
  for (int i = 0; s[i]; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < w[j].length(); k++) {
        if (w[j][k] == s[i]) {
          if (dir[0] == 'L') {
            putchar(w[j][k + 1]);
          } else {
            putchar(w[j][k - 1]);
          }
        }
      }
    }
  }
  putchar('\n');
  return 0;
}