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

const int N = 1234567;

char ans[N], foo[N];

int main() {
  int n;
  scanf("%d", &n);
  memset(ans, '*', sizeof(ans));
  int len;
  for (int i = 0; i < n; i++) {
    scanf("%s", foo);
    len = strlen(foo);
    for (int j = 0; foo[j]; j++)
      if (foo[j] != '?') {
        if (ans[j] == '*') ans[j] = foo[j]; else
        if (ans[j] != foo[j]) ans[j] = '?';
      }
  }
  for (int j = 0; j < len; j++) putchar(ans[j] == '*' ? 'a' : ans[j]);
  return 0;
}