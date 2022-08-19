#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int p[N], p_help[N];

int find_set(int x) {
  if (x != p[x]) p[x] = find_set(p[x]);
  return p[x];
}

int find_set_help(int x) {
  if (x != p_help[x]) p_help[x] = find_set_help(p_help[x]);
  return p_help[x];
}

void unite(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  if (x != y) {
    p[x] = y;
  }
}

int main() {
  int n, tt;
  scanf("%d %d", &n, &tt);
  for (int i = 0; i <= n; i++) {
    p[i] = i;
  }
  for (int i = 0; i <= n; i++) {
    p_help[i] = i;
  }
  while (tt--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    x--; y--;
    if (op == 1) {
      unite(x, y);
    }
    if (op == 2) {
      while (true) {
        x = find_set_help(x);
        if (x >= y) {
          break;
        }
        unite(x, x + 1);
        p_help[x] = x + 1;
      }
    }
    if (op == 3) {
      x = find_set(x);
      y = find_set(y);
      puts(x == y ? "YES" : "NO");
    }
  }
  return 0;
}