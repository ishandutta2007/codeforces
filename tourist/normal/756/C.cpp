#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int mx[N], add[N];
int value[N];

inline void push(int x) {
  if (add[x] != 0) {
    add[x + x] += add[x];
    add[x + x + 1] += add[x];
    add[x] = 0;
  }
}

inline void pull(int x) {
  mx[x] = max(mx[x + x] + add[x + x], mx[x + x + 1] + add[x + x + 1]);
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
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, v);
  }
  pull(x);
}

int find_last(int x, int l, int r) {
  if (l == r) {
    return l;
  }
  push(x);
  int y = (l + r) >> 1;
  int res = -1;
  if (mx[x + x + 1] + add[x + x + 1] > 0) {
    res = find_last(x + x + 1, y + 1, r);
  } else {
    res = find_last(x + x, l, y);
  }
  pull(x);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int id, op;
    scanf("%d %d", &id, &op);
    if (op == 1) {
      scanf("%d", value + id);
    }
    modify(1, 1, n, 1, id, op == 1 ? 1 : -1);
    if (mx[1] + add[1] <= 0) {
      printf("%d\n", -1);
    } else {
      printf("%d\n", value[find_last(1, 1, n)]);
    }
  }
  return 0;
}