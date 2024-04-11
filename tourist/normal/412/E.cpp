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

char s[N];
int next_NL_ND[N];
int next_NL[N];
int last_NL_ND_NU[N];
int sum_L[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  next_NL_ND[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
      next_NL_ND[i] = next_NL_ND[i + 1];
    } else {
      next_NL_ND[i] = i;
    }
  }
  next_NL[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if ('a' <= s[i] && s[i] <= 'z') {
      next_NL[i] = next_NL[i + 1];
    } else {
      next_NL[i] = i;
    }
  }
  last_NL_ND_NU[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9') || s[i] == '_') {
      last_NL_ND_NU[i] = last_NL_ND_NU[i - 1];
    } else {
      last_NL_ND_NU[i] = i;
    }
  }
  sum_L[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum_L[i] = sum_L[i - 1] + ('a' <= s[i] && s[i] <= 'z');
  }
  long long ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    if (s[i] != '@') {
      continue;
    }
    int lower = last_NL_ND_NU[i - 1] + 1;
    long long X = sum_L[i - 1] - sum_L[lower - 1];
    int higher = next_NL_ND[i + 1];
    if (higher == i + 1) {
      continue;
    }
    if (s[higher] != '.') {
      continue;
    }
    long long Y = next_NL[higher + 1] - (higher + 1);
    ans += X * Y;
  }
  cout << ans << endl;
  return 0;
}