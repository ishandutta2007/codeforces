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

char a[444], b[444];

int main() {
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a);
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    int x = (a[i] == '8' ? 0 : (a[i] == '(' ? 1 : 2));
    int y = (b[i] == '8' ? 0 : (b[i] == '(' ? 1 : 2));
    if (x == y) {
      continue;
    }
    if ((x + 1) % 3 == y) {
      res++;
    } else {
      res--;
    }
  }
  puts(res == 0 ? "TIE" : (res < 0 ? "TEAM 1 WINS" : "TEAM 2 WINS"));
  return 0;
}