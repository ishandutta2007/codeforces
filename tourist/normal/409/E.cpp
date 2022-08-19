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
  double x;
  scanf("%lf", &x);
  double diff = 12345;
  int da = -1, db = -1;
  for (int a = 1; a <= 10; a++)
    for (int b = 1; b <= 10; b++) {
      double u = (a * b) / sqrt(4 * a * a + b * b);
      u = fabs(u - x);
      if (u < diff) {
        diff = u;
        da = b;
        db = a;
      }
    }
  printf("%d %d\n", da, db);
  return 0;
}