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

const int N = 200010;

int a[N][26];

char foo[N];

bool can_win[N], can_lose[N];

int main() {
  int nnn, k;
  scanf("%d %d", &nnn, &k);
  memset(a, 0, sizeof(a));
  int n = 1;
  for (int i = 0; i < nnn; i++) {
    scanf("%s", foo);
    int t = 1;
    for (int j = 0; foo[j]; j++) {
      int p = foo[j] - 'a';
      if (a[t][p] == 0) {
        n++;
        a[t][p] = n;
      }
      t = a[t][p];
    }
  }
  for (int i = n; i >= 1; i--) {
    bool mv = false;
    for (int j = 0; j < 26; j++) {
      if (a[i][j] != 0) {
        mv = true;
        break;
      }
    }
    if (!mv) {
      can_win[i] = false;
      can_lose[i] = true;
      continue;
    }
    can_win[i] = false;
    can_lose[i] = false;
    for (int j = 0; j < 26; j++) {
      if (a[i][j] != 0) {
        if (!can_win[a[i][j]]) {
          can_win[i] = true;
        }
        if (!can_lose[a[i][j]]) {
          can_lose[i] = true;
        }
      }
    }
  }
  if (!can_win[1]) {
    puts("Second");
    return 0;
  }
  if (can_lose[1]) {
    puts("First");
    return 0;
  }
  // can_win && !can_lose
  puts((k % 2 == 1) ? "First" : "Second");
  return 0;
}