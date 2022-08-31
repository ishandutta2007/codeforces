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

const int N = 1000010;
const int MAX = 25;

int parent[N];
int cnt[N][MAX];
int ptr[N];

int ans[N];
int f[N];
int pred[N], last[N];

int main() {
  int n;
  scanf("%d", &n);
  n++;
  for (int i = 1; i <= n; i++) {
    last[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    scanf("%d", parent + i);
    pred[i] = last[parent[i]];
    last[parent[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < MAX; j++) {
      cnt[i][j] = 0;
    }
    int q = last[i];
    while (q > 0) {
      cnt[i][f[q]]++;
      q = pred[q];
    }
    ptr[i] = MAX - 1;
    while (ptr[i] > 0 && cnt[i][ptr[i]] == 0) {
      ptr[i]--;
    }
    if (i == 1) {
      f[i] = ptr[i];
    } else {
      if (cnt[i][ptr[i]] >= 2) {
        f[i] = ptr[i] + 1;
      } else {
        f[i] = ptr[i];
      }
    }
  }
  ans[n] = 1 + f[1];
  for (int i = n; i >= 3; i--) {
    int v = i;
    cnt[parent[v]][f[v]]--;
    while (v > 1) {
      int p = parent[v];
      while (ptr[p] > 0 && cnt[p][ptr[p]] == 0) {
        ptr[p]--;
      }
      int new_f;
      if (p == 1) {
        new_f = ptr[p];
      } else {
        if (cnt[p][ptr[p]] >= 2) {
          new_f = ptr[p] + 1;
        } else {
          new_f = ptr[p];
        }
      }
      if (new_f == f[p]) {
        break;
      }
      if (p > 1) {
        cnt[parent[p]][f[p]]--;
        cnt[parent[p]][new_f]++;
      }
      f[p] = new_f;
      v = p;
    }
    ans[i - 1] = 1 + f[1];
  }
  for (int i = 2; i < n; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[n]);
  return 0;
}