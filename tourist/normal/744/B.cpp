#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int x[N][N], y[N][N];

void query(vector <int> z) {
  int sz = z.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) putchar(' ');
    printf("%d", z[i] + 1);
  }
  printf("\n");
  fflush(stdout);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int j = 0; (1 << j) < n; j++) {
    vector <int> a, b;
    for (int i = 0; i < n; i++) {
      if (i & (1 << j)) {
        a.push_back(i);
      } else {
        b.push_back(i);
      }
    }
    query(a);
    for (int i = 0; i < n; i++) {
      scanf("%d", &x[i][j]);
    }
    query(b);
    for (int i = 0; i < n; i++) {
      scanf("%d", &y[i][j]);
    }
  }
  printf("%d\n", -1);
  for (int i = 0; i < n; i++) {
    int ans = (int) 2e9;
    for (int j = 0; (1 << j) < n; j++) {
      if (i & (1 << j)) {
        ans = min(ans, y[i][j]);
      } else {
        ans = min(ans, x[i][j]);
      }
    }
    if (i > 0) putchar(' ');
    printf("%d", ans);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}