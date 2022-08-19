#include <bits/stdc++.h>

using namespace std;

const int N = 77777;
const int MAX = 300;

int f[N][MAX];
int cR[N], cB[N];
int r[N], b[N];
bool type[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char ch = getchar();
    while (ch != 'R' && ch != 'B') {
      ch = getchar();
    }
    type[i] = (ch == 'R');
    scanf("%d %d", r + i, b + i);
  }
  for (int t = 0; t < (1 << n); t++) {
    cR[t] = cB[t] = 0;
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) {
        cR[t] += (type[i] == true);
        cB[t] += (type[i] == false);
      }
    }
  }
  for (int t = 0; t < (1 << n); t++) {
    for (int ar = 0; ar < MAX; ar++) {
      f[t][ar] = -1;
    }
  }
  f[0][0] = 0;
  for (int t = 0; t < (1 << n); t++) {
    for (int ar = 0; ar < MAX; ar++) {
      int ft = f[t][ar];
      if (ft == -1) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (t & (1 << i)) {
          continue;
        }
        int new_ar = ar + min(r[i], cR[t]);
        int new_ab = ft + min(b[i], cB[t]);
        if (new_ab > f[t + (1 << i)][new_ar]) {
          f[t + (1 << i)][new_ar] = new_ab;
        }
      }
    }
  }
  int allR = 0, allB = 0;
  for (int i = 0; i < n; i++) {
    allR += r[i];
    allB += b[i];
  }
  int ans = max(allR, allB);
  for (int ar = 0; ar < MAX; ar++) {
    int ab = f[(1 << n) - 1][ar];
    if (ab == -1) {
      continue;
    }
    ans = min(ans, max(allR - ar, allB - ab));
  }
  printf("%d\n", ans + n);
  return 0;
}