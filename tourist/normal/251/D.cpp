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

using namespace std;

const int N = 222222;
const int m = 62;

long long a[N], b[N], mask[N];
int c[N], n, who[N];
int need[N], used[N];

bool can() {
  int i, j, k;
  for (i=0;i<n;i++) b[i] = a[i], mask[i] = 0, used[i] = 0;
  for (j=m-1;j>=0;j--)
    if (need[j] != -1) {
      who[j] = -1;
      for (i=0;i<n;i++)
        if (!used[i] && (b[i] & (1LL << j))) {
          used[i] = 1;
          who[j] = i;
          mask[i] |= (1LL << j);
          for (k=0;k<n;k++)
            if (i != k && (b[k] & (1LL << j))) {
              b[k] ^= b[i];
              mask[k] ^= mask[i];
            }
          break;
        }
    }
  long long have = 0, ms = 0;
  for (j=m-1;j>=0;j--)
    if (need[j] != -1) {
      if ((!!(have & (1LL << j))) != need[j]) {
        if (who[j] == -1) return false;
        have ^= b[who[j]];
        ms ^= mask[who[j]];
      }
    }
  for (i=0;i<n;i++) c[i] = 2;
  for (j=0;j<m;j++)
    if (ms & (1LL << j)) c[who[j]] = 1;
  return true;
}

int main() {
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int i, j;
  scanf("%d", &n);
  for (i=0;i<n;i++) scanf("%I64d", &a[i]);
  long long X = 0;
  for (i=0;i<n;i++) X ^= a[i];
  for (j=0;j<m;j++) need[j] = -1;
  for (j=m-1;j>=0;j--)
    if (!(X & (1LL << j))) {
      need[j] = 1;
      if (!can()) need[j] = 0;
    }
  for (j=m-1;j>=0;j--)
    if (X & (1LL << j)) {
      need[j] = 0;
      if (!can()) need[j] = 1;
    }
  can();
  for (i=0;i<n-1;i++) printf("%d ", c[i]);
  printf("%d\n", c[n-1]);
  return 0;
}