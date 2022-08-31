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
const int MAGIC = 474;

int len;
int a[N];

int cnt, from[N], to[N];
vector <int> where[N];

void init() {
  cnt = 1;
  from[0] = 1;
  to[0] = len;
  for (int i = 1; i <= len; i++) {
    where[i].clear();
  }
  for (int i = 1; i <= len; i++) {
    where[a[i]].push_back(i);
  }
}

int get_count(int k, int from, int to) {
  int sz = where[k].size();
  if (sz == 0) {
    return 0;
  }
  int low = 0, high = sz;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (where[k][mid] < from) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int X = low;
  low = -1, high = sz - 1;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    if (where[k][mid] > to) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  int Y = low;
  return (Y - X + 1);
}

int new_from[N], new_to[N];

int bounds[4], bound_id;

void cut(int b0, int b1, int b2) {
  bounds[0] = b0;
  bounds[1] = b1;
  bounds[2] = b2;
  bounds[3] = 123456789;
  bound_id = 0;
  int new_cnt = 0;
  int sum = 0;
  for (int i = 0; i < cnt; i++) {
    int new_sum = sum + (to[i] - from[i] + 1);
    if (new_sum <= bounds[bound_id]) {
      if (new_sum == bounds[bound_id]) {
        bound_id++;
      }
      new_from[new_cnt] = from[i];
      new_to[new_cnt] = to[i];
      new_cnt++;
      sum = new_sum;
      continue;
    }
    int get = bounds[bound_id] - sum;
    new_from[new_cnt] = from[i];
    new_to[new_cnt] = from[i] + get - 1;
    new_cnt++;
    from[i] += get;
    sum += get;
    bound_id++;
    i--;
  }
  cnt = new_cnt;
  for (int i = 0; i < cnt; i++) {
    from[i] = new_from[i];
    to[i] = new_to[i];
  }
}

int new_a[N];

int main() {
  scanf("%d", &len);
  for (int i = 1; i <= len; i++) {
    scanf("%d", a + i);
  }
  init();
  int tt;
  scanf("%d", &tt);
  int lastans = 0;
  for (int qq = 1; qq <= tt; qq++) {
    int com;
    scanf("%d", &com);
    if (com == 2) {
      int ll, rr, kk;
      scanf("%d %d %d", &ll, &rr, &kk);
      ll = ((ll + lastans - 1) % len) + 1;
      rr = ((rr + lastans - 1) % len) + 1;
      kk = ((kk + lastans - 1) % len) + 1;
      if (ll > rr) {
        swap(ll, rr);
      }
      int ans = 0;
      int sum = 0;
      for (int i = 0; i < cnt; i++) {
        int x = from[i], y = to[i];
        int begin = sum + 1, end = sum + (y - x + 1);
        if (ll > begin) {
          x += ll - begin;
        }
        if (rr < end) {
          y -= end - rr;
        }
        if (x <= y) {
          ans += get_count(kk, x, y);
        }
        sum = end;
      }
      lastans = ans;
      printf("%d\n", ans);
    } else {
      int ll, rr;
      scanf("%d %d", &ll, &rr);
      ll = ((ll + lastans - 1) % len) + 1;
      rr = ((rr + lastans - 1) % len) + 1;
      if (ll > rr) {
        swap(ll, rr);
      }
      if (ll == rr) {
        continue;
      }
      cut(ll - 1, rr - 1, rr);
      int first = -1;
      int sum = 0;
      for (int i = 0; i < cnt; i++) {
        if (sum == ll - 1) {
          first = i;
        }
        sum += to[i] - from[i] + 1;
        if (sum == rr) {
          int p = from[i];
          for (int j = i; j > first; j--) {
            from[j] = from[j - 1];
            to[j] = to[j - 1];
          }
          from[first] = to[first] = p;
          break;
        }
      }
    }
    if (cnt > MAGIC) {
      int pos = 0;
      for (int i = 0; i < cnt; i++) {
        for (int j = from[i]; j <= to[i]; j++) {
          new_a[++pos] = a[j];
        }
      }
      for (int i = 1; i <= len; i++) {
        a[i] = new_a[i];
      }
      init();
    }
  }
  return 0;
}