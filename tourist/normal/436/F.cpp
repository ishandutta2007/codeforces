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

const int MAX = 100200;
const int BLOCK_SIZE = 300;
const int BLOCK_CNT = MAX / BLOCK_SIZE;

pair <int, int> user[MAX];

int sz[BLOCK_CNT];
int st[BLOCK_CNT][BLOCK_SIZE + 10];
long double sx[BLOCK_CNT][BLOCK_SIZE + 10];
int ptr[BLOCK_CNT];

long long bmax[BLOCK_CNT];
int bid[BLOCK_CNT];
int badd[BLOCK_CNT];

int a[MAX];

long double intersect(int i, int j) {
  return 1.0 * ((long long)i * a[i] - (long long)j * a[j]) / (j - i);
}

long long pay[MAX];
int opt[MAX];

int main() {
  int n, w;
  scanf("%d %d", &n, &w);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &user[i].second, &user[i].first);
  }
  sort(user, user + n);
  int maxbi = user[n - 1].first;
  for (int i = 0; i < MAX; i++) {
    a[i] = 0;
  }
  for (int b = 0; b < BLOCK_CNT; b++) {
    bmax[b] = 0;
    bid[b] = b * BLOCK_SIZE;
    badd[b] = 0;
  }
  int j = 0;
  for (int C = 0; C <= maxbi + 1; C++) {
    while (j < n) {
      if (user[j].first >= C) {
        break;
      }
      int pos = user[j].second;
      for (int b = 0; b < BLOCK_CNT; b++) {
        int from = b * BLOCK_SIZE;
        int to = from + BLOCK_SIZE;
        if (pos >= to) {
          badd[b]++;
          while (ptr[b] < sz[b] && badd[b] > sx[b][ptr[b]]) {
            ptr[b]++;
          }
          int q = st[b][ptr[b]];
          bmax[b] = (long long)q * (a[q] + badd[b]);
          bid[b] = q;
        } else {
          for (int i = from; i < to; i++) {
            a[i] += badd[b];
          }
          for (int i = from; i <= pos; i++) {
            a[i]++;
          }
          badd[b] = 0;
          sz[b] = 0;
          for (int i = from; i < to; i++) {
            while (sz[b] >= 2) {
              long double u = intersect(i, st[b][sz[b]]);
              if (u < sx[b][sz[b] - 1]) {
                sz[b]--;
              } else {
                break;
              }
            }
            st[b][++sz[b]] = i;
            if (sz[b] >= 2) {
              sx[b][sz[b] - 1] = intersect(i, st[b][sz[b] - 1]);
            }
          }
          ptr[b] = 1;
          while (ptr[b] < sz[b] && 0 > sx[b][ptr[b]]) {
            ptr[b]++;
          }
          int q = st[b][ptr[b]];
          bmax[b] = (long long)q * a[q];
          bid[b] = q;
          break;
        }
      }
      j++;
    }
    pay[C] = -1;
    opt[C] = -1;
    for (int b = 0; b < BLOCK_CNT; b++) {
      if (bmax[b] > pay[C]) {
        pay[C] = bmax[b];
        opt[C] = bid[b];
      }
    }
    pay[C] += C * 1LL * w * (n - j);
  }
  for (int C = 0; C <= maxbi + 1; C++) {
    printf("%I64d %d\n", pay[C], opt[C]);
  }
  return 0;
}