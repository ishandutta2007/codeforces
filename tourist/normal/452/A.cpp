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

string names[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

char foo[42];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", foo);
  for (int i = 0; i < 8; i++) {
    int u = names[i].length();
    if (u == n) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (foo[j] != '.' && foo[j] != names[i][j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        puts(names[i].c_str());
        return 0;
      }
    }
  }
  puts("not found :(");
  return 0;
}