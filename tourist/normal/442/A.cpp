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

const int N = 12345;

int c[N], num[N];
char card[N];
int mask[N];

vector < pair <int, int> > p;

int main() {
  int n;
  scanf("%d", &n);
  p.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", card);
    c[i] = -1;
    num[i] = 0;
    if (card[0] == 'R') c[i] = 0;
    if (card[0] == 'G') c[i] = 1;
    if (card[0] == 'B') c[i] = 2;
    if (card[0] == 'Y') c[i] = 3;
    if (card[0] == 'W') c[i] = 4;
    num[i] = card[1] - '1';
    p[i] = make_pair(c[i], num[i]);
  }
  sort(p.begin(), p.end());
  p.resize(unique(p.begin(), p.end()) - p.begin());
  n = p.size();
  for (int i = 0; i < n; i++) {
    c[i] = p[i].first;
    num[i] = p[i].second;
  }
  int ans = 42;
  for (int tn = 0; tn < (1 << 5); tn++) {
    for (int tc = 0; tc < (1 << 5); tc++) {
      vector <int> hints;
      for (int i = 0; i < 5; i++) {
        if (tn & (1 << i)) {
          hints.push_back(i);
        }
      }
      for (int i = 0; i < 5; i++) {
        if (tc & (1 << i)) {
          hints.push_back(~i);
        }
      }
      int cnt = hints.size();
      for (int i = 0; i < n; i++) {
        mask[i] = 0;
        for (int j = 0; j < cnt; j++) {
          if (hints[j] >= 0) {
            if (num[i] == hints[j]) {
              mask[i] |= (1 << j);
            }
          } else {
            if (c[i] == ~hints[j]) {
              mask[i] |= (1 << j);
            }
          }
        }
      }
      sort(mask, mask + n);
      bool ok = true;
      for (int i = 0; i < n - 1; i++) {
        if (mask[i] == mask[i + 1]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        if (cnt < ans) {
          ans = cnt;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}