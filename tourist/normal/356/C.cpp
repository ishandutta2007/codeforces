#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = (int)1e9;

int start[42], finish[42];
int dstart[42], dfinish[42];
int c[42], d[42];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= 4; i++) c[i] = 0;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    scanf("%d", &foo);
    c[foo]++;
    tot += foo;
  }
  int sum = 0;
  for (int i = 4; i >= 0; i--) {
    start[i] = sum + 1;
    finish[i] = sum + c[i];
    sum += c[i];
  }
  int ans = inf;
  for (int k4 = 0; 4 * k4 <= tot; k4++) {
    int k3 = (tot - 4 * k4);
    if (k3 % 3 != 0) continue;
    k3 /= 3;
    if (k4 + k3 > n) continue;
    for (int i = 0; i <= 4; i++) d[i] = 0;
    d[4] = k4;
    d[3] = k3;
    d[0] = n - k4 - k3;
    int sum = 0;
    for (int i = 4; i >= 0; i--) {
      dstart[i] = sum + 1;
      dfinish[i] = sum + d[i];
      sum += d[i];
    }
    int cur = 0;
    for (int i = 0; i <= 4; i++)
      for (int j = 0; j <= 4; j++) {
        int low = start[i];
        if (dstart[j] > low) low = dstart[j];
        int high = finish[i];
        if (dfinish[j] < high) high = dfinish[j];
        if (low <= high) {
          int diff = i - j;
          if (diff < 0) diff = -diff;
          cur += (high - low + 1) * diff;
        }
      }
    cur /= 2;
    if (cur < ans) ans = cur;
  }
  printf("%d\n", ans == inf ? -1 : ans);
  return 0;
}