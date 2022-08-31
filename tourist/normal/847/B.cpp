/**
 *    author:  tourist
 *    created: 18.09.2017 16:16:46       
**/
#include <bits/stdc++.h>

using namespace std;

int mx[1234567];
int a[1234567];

void build(int x, int l, int r) {
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
    mx[x] = max(mx[x + x], mx[x + x + 1]);
  } else {
    mx[x] = a[l];
  }
}

void modify(int x, int l, int r, int p, int v) {
  if (l == r) {
    mx[x] = v;
    return;
  }
  int y = (l + r) >> 1;
  if (p <= y) {
    modify(x + x, l, y, p, v);
  } else {
    modify(x + x + 1, y + 1, r, p, v);
  }
  mx[x] = max(mx[x + x], mx[x + x + 1]);
}

int get(int x, int l, int r, int p, int v) {
  if (l == r) {
    return (mx[x] >= v ? l : -1);
  }
  if (r < p) {
    return -1;
  }
  int y = (l + r) >> 1;
  if (l >= p) {
    if (mx[x] < v) {
      return -1;
    }
    if (mx[x + x] >= v) {
      return get(x + x, l, y, p, v);
    }
    return get(x + x + 1, y + 1, r, p, v);
  }
  int z = get(x + x, l, y, p, v);
  if (z == -1) {
    z = get(x + x + 1, y + 1, r, p, v);
  }
  return z;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  build(1, 0, n - 1);
  int cnt = n;
  while (cnt > 0) {
    int ptr = 0;
    int last = 0;
    while (ptr < n) {
      int pos = get(1, 0, n - 1, ptr, last);
      if (pos == -1) {
        break;
      }
      if (ptr > 0) putchar(' ');
      cnt--;
      printf("%d", a[pos]);
      ptr = pos + 1;
      last = a[pos];
      modify(1, 0, n - 1, pos, -1);
    }
    printf("\n");
  }
  return 0;
}