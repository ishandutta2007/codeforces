#include <bits/stdc++.h>

using namespace std;

const int N = 3234567;

int fenw[N];
int n;

void modify(int x, int v) {
  while (x <= n) {
    fenw[x] += v;
    x = (x | (x - 1)) + 1;
  }
}

int find_sum(int x) {
  int v = 0;
  while (x > 0) {
    v += fenw[x];
    x &= x - 1;
  }
  return v;
}

int main() {
  int k;
  scanf("%d %d", &n, &k);
  if (2 * k > n) {
    k = n - k;
  }
  for (int i = 1; i <= n; i++) {
    fenw[i] = 0;
  }
  int x = 1;
  long long ans = 1;
  for (int it = 1; it <= n; it++) {
    ans++;
    int from = x - k + 1;
    int to = x + k - 1;
    if (from < 1) {
      ans += find_sum(to) + find_sum(n) - find_sum(from + n - 1);
    } else {
      if (to > n) {
        ans += find_sum(n) - find_sum(from - 1) + find_sum(to - n);
      } else {
        ans += find_sum(to) - find_sum(from - 1);
      }
    }
    modify(x, 1);
    x += k;
    if (x > n) {
      x -= n;
    }
    if (it > 1) putchar(' ');
    printf("%I64d", ans);
  }
  printf("\n");
  return 0;
}