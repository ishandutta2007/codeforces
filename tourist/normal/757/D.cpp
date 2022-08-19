#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

const int NUM = 20;
const int N = (1 << NUM) + 10;
const int LEN = 79;

int f[LEN][N];
char s[LEN];

int main() {
  int len;
  scanf("%d", &len);
  scanf("%s", s);
  for (int i = 0; i < len; i++) {
    f[i][0] = 1;
    for (int t = 0; t < (1 << NUM); t++) {
      if (f[i][t] == 0) {
        continue;
      }
      int x = 0;
      for (int j = i; j < len; j++) {
        x = x * 2 + s[j] - '0';
        if (x > NUM) {
          break;
        }
        if (x > 0) {
          add(f[j + 1][t | (1 << (x - 1))], f[i][t]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= len; i++) {
    int r = 1;
    while (r < (1 << NUM)) {
      add(ans, f[i][r]);
      r = r * 2 + 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}