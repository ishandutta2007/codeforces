#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
char Gc() {
  static char now[1 << 20], *S, *T;
  if (T == S) {
    T = (S = now) + std::fread(now, 1, 1 << 20, stdin);
    if (T == S) {
      return EOF;
    }
  }
  return *S++;
}
template <typename T>
void Read(T &x) {
  x = 0;
  int f = 1;
  char c;
  while ((c = Gc()) < '0' || c > '9') {
    if (c == '-') {
      f = -1;
    }
  }
  x = c - '0';
  while ((c = Gc()) >= '0' && c <= '9') {
    x = x * 10 + c - '0';
  }
  x *= f;
}
template <typename T, typename... Args>
void Read(T &x, Args &...args) {
  Read(x);
  Read(args...);
}
int n, m, k, a[1001][1001];
long long sum1[1001][1001], sum2[1001][1001], sum3[1001][1001], l[1001][1001],
    r[1001][1001], dp[1001][1001];
auto calc1 = [](int x1, int y1, int x2, int y2) -> long long {
  return sum1[x2][y2] - sum1[x1 - 1][y1 + 1];
};
auto calc2 = [](int x1, int y1, int x2, int y2) -> long long {
  return sum2[x2][y2] - sum2[x1 - 1][y1 - 1];
};
auto calc3 = [](int x1, int y1, int x2, int y2) -> long long {
  return sum3[x2][y2] - sum3[x1 - 1][y1];
};
int main(int argc, char const *argv[]) {
  Read(n, m, k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Read(a[i][j]);
      sum1[i][j] = sum2[i][j] = sum3[i][j] = a[i][j];
    }
  }
  for (int s = 2; s <= n + m; s++) {
    for (int i = std::max(1, s - m); i <= n && i < s; i++) {
      sum1[i][s - i] += sum1[i - 1][s - i + 1];
    }
  }
  for (int s = m - 1; s >= 1 - n; s--) {
    for (int i = std::max(1, 1 - s); i <= n && i <= m - s; i++) {
      sum2[i][i + s] += sum2[i - 1][i + s - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      sum3[j][i] += sum3[j - 1][i];
    }
  }
  for (int i = 1; i <= k; i++) {
    l[k][k] += calc3(k - i + 1, i, k + i - 1, i);
  }
  for (int i = k + 1; i <= n - k + 1; i++) {
    l[i][k] =
        l[i - 1][k] - calc1(i - k, k, i - 1, 1) + calc2(i, 1, i + k - 1, k);
  }
  for (int i = k; i <= n - k + 1; i++) {
    for (int j = k + 1; j <= m - k + 1; j++) {
      l[i][j] = l[i][j - 1] - calc1(i - k + 1, j - 1, i, j - k) -
                calc2(i + 1, j - k + 1, i + k - 1, j - 1) +
                calc3(i - k + 1, j, i + k - 1, j);
    }
  }
  for (int i = 1; i <= k; i++) {
    r[k][m - k + 1] += calc3(k - i + 1, m - i + 1, k + i - 1, m - i + 1);
  }
  for (int i = k + 1; i <= n - k + 1; i++) {
    r[i][m - k + 1] = r[i - 1][m - k + 1] - calc2(i - k, m - k + 1, i - 1, m) +
                      calc1(i, m, i + k - 1, m - k + 1);
  }
  for (int i = k; i <= n - k + 1; i++) {
    for (int j = m - k; j >= k; j--) {
      r[i][j] = r[i][j + 1] - calc2(i - k + 1, j + 1, i, j + k) -
                calc1(i + 1, j + k - 1, i + k - 1, j + 1) +
                calc3(i - k + 1, j, i + k - 1, j);
    }
  }
  int x = k, y = k;
  long long ans = 0LL;
  for (int i = k; i <= n - k + 1; i++) {
    dp[i][k] = k * a[i][k];
    for (int j = 1; j < k; j++) {
      dp[i][k] += j * (calc1(i - k + j, k, i - 1, j + 1) +
                       calc2(i, j, i + k - j - 1, k - 1) +
                       calc1(i + 1, 2 * k - j - 1, i + k - j, k) +
                       calc2(i - k + j + 1, k + 1, i, 2 * k - j));
    }
    if (dp[i][k] >= ans) {
      ans = dp[i][k];
      x = i;
      y = k;
    }
  }
  for (int i = k; i <= n - k + 1; i++) {
    for (int j = k + 1; j <= m - k + 1; j++) {
      if ((dp[i][j] = dp[i][j - 1] - l[i][j - 1] + r[i][j]) >= ans) {
        ans = dp[i][j];
        x = i;
        y = j;
      }
    }
  }
  std::printf("%d %d", x, y);
  return 0;
}