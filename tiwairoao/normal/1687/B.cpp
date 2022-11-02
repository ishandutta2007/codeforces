#include <bits/stdc++.h>

const int M = 500;

bool b[M + 5]; int s, n, m;
int query() {
  printf("? ");
  for (int i = 1; i <= m; i++) putchar(b[i] ? '1' : '0');
  puts(""), fflush(stdout);
  
  int res; scanf("%d", &res);
  return res;
}
std::pair<int, int>a[M + 5];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    b[i] = true;
    a[i] = std::make_pair(query(), i);
    b[i] = false;
  }
  std::sort(a + 1, a + m + 1);
  for (int k = 1; k <= m; k++) {
    int i = a[k].second;
    b[i] = true;
    if (query() == s + a[k].first) {
      s += a[k].first;
    } else {
      b[i] = false;
    }
  }
  printf("! %d\n", s), fflush(stdout);
}