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

const int N = 4 * 77777;

unsigned int one = 1;
unsigned int f[N], nf[N];
pair <int, int> a[N];
int last[N], inside[N], A[N];
bool used[N];

int main() {
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    A[i] = a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  reverse(a, a + n);
  if (a[0].first > s) {
    printf("%d\n", -1);
    return 0;
  }
  s -= a[0].first;
  int nn = (s >> 5) + 1;
  for (int i = 0; i < nn; i++) f[i] = 0;
  for (int i = 0; i <= s; i++) last[i] = -1;
  last[0] = 0;
  f[0] |= (one << 0);
  for (int q = 1; q < n; q++) {
    int w = a[q].first;
    for (int i = 0; i < nn; i++) nf[i] = 0;
    int els = (w >> 5);
    int shift = (w & 31);
    for (int i = 0; i < nn; i++) {
      int j = i + els;
      if (j < nn) {
        nf[j] |= (f[i] << shift);
        if (j + 1 < nn && shift != 0) {
          nf[j + 1] |= (f[i] >> (32 - shift));
        }
      }
      else break;
    }
    for (int i = 0; i < nn; i++)
      if ((f[i] | nf[i]) != f[i]) {
        for (int j = 0; j < 32; j++)
          if (nf[i] & (one << j)) {
            if (!(f[i] & (one << j))) {
              int id = (i << 5) + j;
              last[id] = q;
            }
          }
        f[i] |= nf[i];
      }
  }
  if (last[s] == -1) {
    printf("%d\n", -1);
    return 0;
  }
  for (int i = 1; i < n; i++) used[i] = false;
  while (s > 0) {
    used[last[s]] = true;
    s -= a[last[s]].first;
  }
  for (int i = 0; i < n; i++) inside[i] = -1;
  int prev = 0;
  for (int i = 1; i < n; i++) {
    if (!used[i]) {
      inside[a[prev].second] = a[i].second;
      prev = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (inside[i] == -1) {
      printf("%d 0\n", A[i]);
    } else {
      printf("%d 1 %d\n", A[i] - A[inside[i]], inside[i] + 1);
    }
  }
  return 0;
}