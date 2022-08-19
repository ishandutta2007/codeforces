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

const int N = 400010;

double inter(pair <int, int> a, pair <int, int> b) {
  return 1.0 * (b.second - a.second) / (a.first - b.first);
}

vector < pair <int, int> > st;
double sx[N];
int len;

void init() {
  st.clear();
  len = 0;
}

void add(pair <int, int> u) {
  while (len >= 2) {
    double xx = inter(st[len - 1], u);
    if (xx > sx[len - 2]) {
      break;
    }
    st.pop_back();
    len--;
  }
  if (len >= 1) {
    sx[len - 1] = inter(st[len - 1], u);
  }
  st.push_back(u);
  len++;
}

vector < pair <int, int> > p[N];
int sz[N];

int k[N], b[N];

void build(int x, int l, int r) {
  if (l == r) {
    p[x].push_back(make_pair(k[l], b[l]));
    return;
  }
  int y = (l + r) >> 1;
  build(x + x, l, y);
  build(x + x + 1, y + 1, r);
  init();
  int ci = x + x, cj = x + x + 1;
  int si = p[ci].size(), sj = p[cj].size();
  int i = 0, j = 0;
  while (i < si || j < sj) {
    if (i == si) {
      add(p[cj][j]);
      j++;
      continue;
    }
    if (j == sj) {
      add(p[ci][i]);
      i++;
      continue;
    }
    if (p[ci][i].first == p[cj][j].first) {
      if (p[ci][i].second < p[cj][j].second) {
        add(p[ci][i]);
      } else {
        add(p[cj][j]);
      }
      i++; j++;
      continue;
    }
    if (p[ci][i].first > p[cj][j].first) {
      add(p[ci][i]);
      i++;
    } else {
      add(p[cj][j]);
      j++;
    }
  }
  p[x] = st;
  sz[x] = len;
}

int ptr[N];

int ans;

void solve(int x, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) {
    int point = ll - 1;
    int u = p[x][ptr[x]].first * point + p[x][ptr[x]].second;
    if (u < ans) {
      ans = u;
    }
    while (ptr[x] + 1 < sz[x]) {
      int v = p[x][ptr[x] + 1].first * point + p[x][ptr[x] + 1].second;
      if (v < ans) {
        ans = v;
      }
      if (v <= u) {
        ptr[x]++;
        u = v;
      } else {
        break;
      }
    }
    return;
  }
  int y = (l + r) >> 1;
  if (ll <= y) {
    solve(x + x, l, y, ll, rr);
  }
  if (y + 1 <= rr) {
    solve(x + x + 1, y + 1, r, ll, rr);
  }
}

int a[N], s[N];

pair < pair <int, int>, pair <int, int> > queries[N];

int result[N];

int main() {
  int n;
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    k[i] = -a[i];
    b[i] = a[i] * (i - 1) - s[i - 1];
  }
  for (int i = 0; i < N; i++) {
    p[i].clear();
  }
  build(1, 1, n);
  memset(ptr, 0, sizeof(ptr));
  int tt;
  scanf("%d", &tt);
  for (int qq = 0; qq < tt; qq++) {
    int x, y;
    scanf("%d %d", &x, &y);
    queries[qq] = make_pair(make_pair(y - x, qq), make_pair(x, y));
  }
  sort(queries, queries + tt);
  for (int qq = 0; qq < tt; qq++) {
    int x = queries[qq].second.first;
    int y = queries[qq].second.second;
    ans = (int)2.1e9;
    solve(1, 1, n, y - x + 1, y);
    result[queries[qq].first.second] = s[y] + ans;
  }
  for (int qq = 0; qq < tt; qq++) {
    printf("%d\n", result[qq]);
  }
  return 0;
}