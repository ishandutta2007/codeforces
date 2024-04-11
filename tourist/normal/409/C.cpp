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
  int a, b, c, d, e;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
  a /= 1;
  b /= 1;
  c /= 2;
  d /= 7;
  e /= 4;
  if (b < a) a = b;
  if (c < a) a = c;
  if (d < a) a = d;
  if (e < a) a = e;
  printf("%d\n", a);
  return 0;
}