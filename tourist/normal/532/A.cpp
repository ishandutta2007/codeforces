#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1.01e9;

const int N = (1 << 19);

int cost[N];
int min1[N], min2[N];
vector <int> g[N];

void go(int v, int pr, int m1, int m2) {
  if (cost[v] < cost[m1]) {
    m2 = m1;
    m1 = v;
  } else {
    if (cost[v] < cost[m2]) {
      m2 = v;
    }
  }
  min1[v] = m1;
  min2[v] = m2;
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    go(u, v, m1, m2);
  }
}

int add[4 * N], mn[4 * N];

inline void push(int x) {
  if (add[x] != 0) {
    add[x + x] += add[x];
    add[x + x + 1] += add[x];
    add[x] = 0;
  }
}

inline void gather(int x) {
  int a = mn[x + x] + add[x + x];
  int b = mn[x + x + 1] + add[x + x + 1];
  mn[x] = (a < b ? a : b);
}

void build(int x, int l, int r) {
  add[x] = 0;
  if (l == r) {
    mn[x] = -l - 1;
  } else {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    gather(x);
  }
}

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    add[x] += v;
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, v);
  }
  if (rr >= y + 1) {
    modify(x + x + 1, y + 1, r, ll, rr, v);
  }
  gather(x);
}

int k;

int guy[N];

void do_add(int value, int what_to_add) {
  int low = 0, high = k;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (guy[mid] > value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  if (low < k) {
    modify(1, 0, k - 1, low, k - 1, what_to_add);
  }
}

int find_first(int x, int l, int r, int from, int value) {
  if (l < from) {
    push(x);
    int y = (l + r) >> 1;
    if (from <= y) {
      int u = find_first(x + x, l, y, from, value);
      if (u != k) {
        gather(x);
        return u;
      }
    }
    int u = find_first(x + x + 1, y + 1, r, from, value);
    gather(x);
    return u;
  }
  if (mn[x] + add[x] >= value) {
    return k;
  }
  if (l == r) {
    return l;
  }
  push(x);
  int y = (l + r) >> 1;
  int u = find_first(x + x, l, y, from, value);
  if (u != k) {
    gather(x);
    return u;
  }
  u = find_first(x + x + 1, y + 1, r, from, value);
  gather(x);
  return u;
}

int go_down(int value, int cnt) {
  int low = 0, high = k;
  while (low < high) {
    int mid = (low + high) >> 1;
    if (guy[mid] > value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  int pos = (low < k ? find_first(1, 0, k - 1, low, cnt) : k);
  return (pos < k ? guy[pos] : -inf);
}

int mpred[N], mlast[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", cost + i);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  cost[n] = inf;
  go(0, -1, n, n);
  for (int i = 0; i < n; i++) {
    mlast[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    mpred[i] = mlast[min1[i]];
    mlast[min1[i]] = i;
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", guy + i);
  }
  sort(guy, guy + k);
  reverse(guy, guy + k);
  build(1, 0, k - 1);
  for (int i = 0; i < n; i++) {
    do_add(cost[min1[i]], 1);
  }
  if (mn[1] + add[1] >= 0) {
    printf("%d\n", 0);
    return 0;
  }
  int ans = inf;
  for (int change = 0; change < n; change++) {
    vector <int> sec;
    int q = mlast[change];
    while (q >= 0) {
      sec.push_back(cost[min2[q]]);
      q = mpred[q];
    }
    sort(sec.begin(), sec.end());
    int sec_sz = sec.size();
    int sprev = cost[change];
    bool first = true;
    for (int j = 0; j < sec_sz; j++) {
      int cnt = sec_sz - j;
      do_add(sprev, -cnt);
      do_add(sec[j], cnt);
      if (mn[1] + add[1] >= 0 && first) {
        int cur = max(sprev, go_down(sec[j], cnt)); 
        if (cur - cost[change] < ans) {
          ans = cur - cost[change];
        }
        first = false;
      }
      sprev = sec[j];
    }
    {
      do_add(cost[change], sec_sz);
      for (int j = 0; j < sec_sz; j++) {
        do_add(sec[j], -1);
      }
    }
  }
  if (ans == inf) {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}