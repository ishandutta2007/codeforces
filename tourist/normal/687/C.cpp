#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

bool can[N][N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int x = 0; x <= k; x++) {
    for (int y = 0; x + y <= k; y++) {
      can[x][y] = false;
    }
  }
  can[0][0] = true;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    for (int x = k - c; x >= 0; x--) {
      for (int y = k - c - x; y >= 0; y--) {
        if (can[x][y]) {
          can[x + c][y] = true;
          can[x][y + c] = true;
        }
      }
    }
  }
  vector <int> z;
  for (int x = 0; x <= k; x++) {
    if (can[x][k - x]) {
      z.push_back(x);
    }
  }
  int sz = z.size();
  printf("%d\n", sz);
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      putchar(' ');
    }
    printf("%d", z[i]);
  }
  printf("\n");
  return 0;
}