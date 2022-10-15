#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int n, x[200001];
long long a[200001], b[200001];
char s[200005];
void sgn(int x) {
  if (x == 1)
    std::cout << " R\n";
  else
    std::cout << " L\n";
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::cin >> (s + 1);
  std::sort(a + 1, a + n + 1);
  int l1 = 0, r1 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R')
      x[i] = 1;
    else
      x[i] = -1;
    if (i > 1)
      if (x[i] == x[i - 1]) l1++;
  }
  r1 = l1 + 1;
  b[n] = x[n];
  for (int i = n - 1; i >= 1; i--) b[i] = b[i + 1] * -1;
  std::cout << a[r1], sgn(b[r1++]);
  for (int i = 2; i <= n; i++) {
    if (b[r1 - 1] * x[i] < 0) {
      std::cout << a[r1], sgn(b[r1++]);
    } else {
      std::cout << a[l1], sgn(b[l1--]);
    }
  }
  return 0;
}