#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

bitset<N> b;
int p[N];
int cnt[N];
bool was[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    p[i]--;
    was[i] = false;
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    int x = i;
    int len = 0;
    while (!was[x]) {
      was[x] = true;
      x = p[x];
      len++;
    }
    c1 += len % 2;
    c2 += len / 2;
    cnt[len]++;
  }
  b.set(n);
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) {
      continue;
    }
    int j = 1;
    while (cnt[i] > 0) {
      j = min(j, cnt[i]);
      int u = i * j;
      b |= (b >> u);
      cnt[i] -= j;
      j *= 2;
    }
  }
  int ans_min = k;
  if (!b.test(n - k)) {
    ans_min++;
  }
  int ans_max = 0;
  ans_max += 2 * min(k, c2);
  k -= min(k, c2);
  ans_max += min(k, c1);
  printf("%d %d\n", ans_min, ans_max);
  return 0;
}