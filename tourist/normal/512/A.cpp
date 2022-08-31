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

const int ALPHA = 26;

int g[123][123];
int x[12345];
int deg[12345];
char s[1234][1234];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < ALPHA; i++) {
    for (int j = 0; j < ALPHA; j++) {
      g[i][j] = 0;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int j = 0;
    while (s[i][j] == s[i + 1][j]) {
      j++;
    }
    if (!s[i][j]) {
      continue;
    }
    if (s[i][j] && !s[i + 1][j]) {
      puts("Impossible");
      return 0;
    }
    if (s[i][j] && s[i + 1][j]) {
      g[s[i][j] - 'a'][s[i + 1][j] - 'a'] = 1;
    }
  }
  for (int i = 0; i < ALPHA; i++) {
    deg[i] = 0;
  }
  for (int i = 0; i < ALPHA; i++) {
    for (int j = 0; j < ALPHA; j++) {
      if (g[i][j]) {
        deg[j]++;
      }
    }
  }
  int b = 1, e = 0;
  for (int i = 0; i < ALPHA; i++) {
    if (deg[i] == 0) {
      x[++e] = i;
    }
  }
  while (b <= e) {
    for (int j = 0; j < ALPHA; j++) {
      if (g[x[b]][j] == 0) {
        continue;
      }
      deg[j]--;
      if (deg[j] == 0) {
        x[++e] = j;
      }
    }
    b++;
  }
  if (e != ALPHA) {
    puts("Impossible");
    return 0;
  }
  for (int i = 1; i <= e; i++) {
    putchar('a' + x[i]);
  }
  printf("\n");
  return 0;
}