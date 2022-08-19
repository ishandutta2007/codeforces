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

const int MAXN = 100010;

int s[2][MAXN];

void modify(int q, int x, int v) {
  while (x < MAXN) {
    s[q][x] += v;
    x = (x | (x - 1)) + 1;
  }
}

int find_sum(int q, int x) {
  int v = 0;
  while (x > 0) {
    v += s[q][x];
    x &= x - 1;
  }
  return v;
}

multiset <int> votes[MAXN];

int pred[MAXN], last[MAXN];
int danger[MAXN];

int main() {
  int n;
  scanf("%d", &n);
  int my = 0;
  for (int i = 0; i < MAXN; i++) {
    votes[i].clear();
  }
  for (int q = 0; q < 2; q++) {
    for (int i = 0; i < MAXN; i++) {
      s[q][i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == 0) {
      my++;
    } else {
      votes[a].insert(b);
      modify(0, b + 1, 1);
      modify(1, b + 1, b);
    }
  }
  for (int i = 0; i <= n; i++) {
    last[i] = 0;
  }
  for (int i = 1; i < MAXN; i++) {
    int cnt = votes[i].size();
    pred[i] = last[cnt];
    last[cnt] = i;
  }
  int ans = (int)2e9;
  int nd = 0;
  int add = 0;
  for (int win = n; win >= my; win--) {
    int j = last[win];
    while (j > 0) {
      danger[nd++] = j;
      j = pred[j];
    }
    for (int q = 0; q < nd; q++) {
      int j = danger[q];
      int u = *(votes[j].begin());
      add += u;
      my++;
      modify(0, u + 1, -1);
      modify(1, u + 1, -u);
      votes[j].erase(votes[j].begin());
    }
    int cur = add;
    if (my < win) {
      int need = win - my;
      int ll = 1, rr = MAXN - 1;
      while (ll < rr) {
        int mid = (ll + rr) >> 1;
        int have = find_sum(0, mid);
        if (have >= need) {
          rr = mid;
        } else {
          ll = mid + 1;
        }
      }
      int have = find_sum(0, ll);
      int sum = find_sum(1, ll);
      if (have > need) {
        sum -= (have - need) * (ll - 1);
      }
      cur += sum;
    }
    if (cur < ans) {
      ans = cur;
    }
  }
  printf("%d\n", ans);
  return 0;
}