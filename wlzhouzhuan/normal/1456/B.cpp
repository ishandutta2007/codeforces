// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 500005;
int a[N], s[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] ^ a[i];
  } 
  if (n > 500) {
    puts("1");
    return 0;
  }
  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int ok = 0;
      for (int k = i + 1; k <= j; k++) {
        if ((s[k - 1] ^ s[i - 1]) > (s[j] ^ s[k - 1])) {
          ok = 1;
          break;
        }
      } 
      if (ok) ans = min(ans, j - i - 1);
    }
  }
  printf("%d\n", ans == 1e9 ? -1 : ans);
  return 0;
}