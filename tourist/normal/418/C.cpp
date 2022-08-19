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

vector <int> gen(int n) {
  vector <int> ret(n);
  if (n == 1) {
    ret[0] = 1;
  } else
  if (n == 2) {
    ret[0] = 3;
    ret[1] = 4;
  } else
  if (n % 2 == 0) {
    for (int i = 0; i < n - 1; i++) ret[i] = 1;
    ret[n - 1] = n / 2 - 1;
  } else {
    for (int i = 0; i < n - 2; i++) ret[i] = 1;
    ret[n - 2] = 2;
    ret[n - 1] = n / 2 + 1;
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector <int> a = gen(n);
  vector <int> b = gen(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", a[i] * b[j]);
      if (j < m - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}