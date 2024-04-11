#include <bits/stdc++.h>
using namespace std;

#define int long long
int bit[1 << 13], a[1001], ans[13], cnt;
int n;

int ask(vector<int> a) {
  printf("? %lld", (long long)a.size());
  for (auto v: a) printf(" %lld", v);
  puts(""), fflush(stdout);
  int x; scanf("%lld", &x);
  return x;
}
signed main() {
  scanf("%lld", &n);
  int it = 0;
  for (int i = 0; i < (1ll << 13); i++) {
    bit[i] = bit[i >> 1ll] + (i & 1ll);
    if (bit[i] == 6) {
      a[++it] = i;
      if (it == n) break;
    }
  }
  for (int bit = 0; bit < 13; bit++) {
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
      if (a[i] >> bit & 1) {
        tmp.push_back(i);
      }
    }
    if (tmp.size() == 0) continue;
    ans[bit] = ask(tmp);
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    int res = 0;
    for (int j = 0; j < 13; j++) {
      if (!(a[i] >> j & 1)) {
        res |= ans[j];
      }
    }
    printf("%lld ", res);
  }
  puts(""), fflush(stdout);
  return 0;
}