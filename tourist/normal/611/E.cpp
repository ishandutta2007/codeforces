#include <bits/stdc++.h>

using namespace std;

inline int solve(int a, int b, int c, int ac, int bc, int abc) {
  int res = abc;
  {
    res += bc;
    a = max(a - bc, 0);
  }
  {
    res += ac;
    int take = min(b, ac);
    b -= take;
    ac -= take;
    a = max(a - ac, 0);
  }
  res += max(c, max((b + c + 1) / 2, (a + b + c + 2) / 3));
  return res;
}

int main() {
  int n, A, B, C;
  scanf("%d", &n);
  scanf("%d %d %d", &A, &B, &C);
  if (A > B) swap(A, B);
  if (A > C) swap(A, C);
  if (B > C) swap(B, C);
  int x[42];
  x[0] = A;
  x[1] = B;
  x[2] = C;
  x[3] = A + B;
  x[4] = A + C;
  x[5] = B + C;
  x[6] = A + B + C;
  sort(x, x + 7);
  vector <int> z(7, 0);
  for (int i = 0; i < n; i++) {
    int y;
    scanf("%d", &y);
    if (y > x[6]) {
      printf("%d\n", -1);
      return 0;
    }
    for (int j = 0; j < 7; j++) {
      if (y <= x[j]) {
        z[j]++;
        break;
      }
    }
  }
  int ans = n;
  for (int cnt = 0; cnt <= n; cnt++) {
    if (C < A + B) {
      ans = min(ans, cnt + solve(z[0], z[1], z[2], z[3] + z[4], z[5], z[6]));
    } else {
      ans = min(ans, cnt + solve(z[0], z[1], z[2] + z[3], z[4], z[5], z[6]));
    }
    for (int who = 2; who <= 3; who++) {
      for (int j = who; j >= 0; j--) {
        if (z[j] > 0) {
          z[j]--;
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}