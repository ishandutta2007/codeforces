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

const int N = 1234567;

int cnt[N];
bool res[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int people, dishes;
    scanf("%d %d", &people, &dishes);
    for (int i = 0; i < dishes; i++) {
      scanf("%d", cnt + i);
      res[i] = false;
    }
    people--;
    bool good = true;
    int unknown = 0;
    while (people--) {
      int what, disapp;
      scanf("%d %d", &what, &disapp);
      what--;
      if (disapp == 1 && good) {
        good = false;
        for (int i = 0; i < dishes; i++) {
          if (cnt[i] <= unknown) {
            res[i] = true;
          }
        }
      }
      if (what != -1) {
        cnt[what]--;
        res[what] = false;
      } else {
        unknown++;
      }
    }
    int reserved = 0;
    if (!good) {
      reserved = (int)1e9;
      for (int i = 0; i < dishes; i++) {
        if (res[i]) {
          reserved = min(reserved, cnt[i]);
        }
      }
    }
    for (int i = 0; i < dishes; i++) {
      if (cnt[i] <= unknown - reserved) {
        res[i] = true;
      }
      putchar(res[i] ? 'Y' : 'N');
    }
    putchar('\n');
  }
  return 0;
}