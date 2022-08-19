#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;
const int N = 5555;

char s[N];
int f[N], nf[N];
int nxt[N][42];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  for (int c = 0; c < 26; c++) {
    nxt[n][c] = n;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int c = 0; c < 26; c++) {
      nxt[i][c] = nxt[i + 1][c];
    }
    nxt[i][s[i] - 'a'] = i;
  }
  for (int i = 0; i < n; i++) {
    f[i] = 0;
  }
  f[0] = 1;
  for (int it = 0; it < n; it++) {
    for (int i = 0; i < n; i++) {
      nf[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      for (int c = 0; c < 26; c++) {
        int u = nxt[i][c];
        nf[u] += f[i];
        if (nf[u] >= md) {
          nf[u] -= md;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      f[i] = nf[i];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + f[i]) % md;
  }
  printf("%d\n", ans);
  return 0;
}