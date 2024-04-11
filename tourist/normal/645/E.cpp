#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

const int N = 3456789;

char s[N];
int f[N];
int last[42];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  int m = strlen(s + 1);
  for (int j = 0; j < k; j++) {
    last[j] = 0;
  }
  f[0] = 1;
  for (int i = 1; i <= m + n; i++) {
    f[i] = f[i - 1] * 2 % md;
    int c;
    if (i <= m) {
      c = s[i] - 'a';
    } else {
      c = -1;
      int pos = i;
      for (int cc = 0; cc < k; cc++) {
        if (last[cc] < pos) {
          pos = last[cc];
          c = cc;
        }
      }
    }
    if (last[c] > 0) {
      f[i] = (f[i] - f[last[c] - 1] + md) % md;
    }
    last[c] = i;
  }
  printf("%d\n", f[m + n]);
  return 0;
}