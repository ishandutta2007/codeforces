#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int LOG = 22;

char s[N];
int p[N];
int pr[N][LOG];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  int kk = 0;
  p[1] = 0;
  for (int i = 2; i <= n; i++) {
    while (kk > 0 && s[i] != s[kk + 1]) kk = p[kk];
    if (s[i] == s[kk + 1]) kk++;
    p[i] = kk;
  }
  p[0] = 0;
  for (int i = 0; i <= n; i++) {
    pr[i][0] = p[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i <= n; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }
  for (int len = 1; len <= n; len++) {
    int from = (((long long)(k - 1)) * len + k - 1) / k;
    int to = (((long long)k) * len) / (k + 1);
    int t = len;
    for (int j = LOG - 1; j >= 0; j--) {
      if (pr[t][j] > to) {
        t = pr[t][j];
      }
    }
    t = pr[t][0];
    if (from <= t && t <= to) {
      putchar('1');
    } else {
      putchar('0');
    }
  }
  return 0;
}