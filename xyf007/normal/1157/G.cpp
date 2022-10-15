#include <algorithm>
#include <bitset>
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
int n, m, a[200][200], r[200], c[200];
void Check(int x) {
  int p = !x ? n - 1 : 0;
  for (int j = 0; j < m; j++)
    if (a[p][j]) {
      c[j] ^= 1;
      for (int i = 0; i < n; i++) a[i][j] ^= 1;
    }
  for (int i = x + 1; i < n; i++) {
    r[i] ^= 1;
    for (int j = 0; j < m; j++) a[i][j] ^= 1;
  }
  bool f = true;
  for (int j = 0; j + 1 < m; j++) f &= a[x][j] <= a[x][j + 1];
  if (f) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) std::cout << r[i];
    std::cout << '\n';
    for (int j = 0; j < m; j++) std::cout << c[j];
    std::exit(0);
  }
  r[x] ^= 1;
  for (int j = 0; j < m; j++) a[x][j] ^= 1;
  f = true;
  for (int j = 0; j + 1 < m; j++) f &= a[x][j] <= a[x][j + 1];
  if (f) {
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) std::cout << r[i];
    std::cout << '\n';
    for (int j = 0; j < m; j++) std::cout << c[j];
    std::exit(0);
  }
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) std::cin >> a[i][j];
  for (int i = 0; i < n; i++)
    if (a[i][0]) {
      r[i] ^= 1;
      for (int j = 0; j < m; j++) a[i][j] ^= 1;
    }
  int d = 0, u = n - 1;
  for (int i = 1; i < n; i++) {
    bool f = true;
    for (int j = 0; j < m; j++) f &= a[0][j] == a[i][j];
    if (!f) break;
    d = i;
  }
  for (int i = n - 2; i >= 0; i--) {
    bool f = true;
    for (int j = 0; j < m; j++) f &= a[n - 1][j] == a[i][j];
    if (!f) break;
    u = i;
  }
  if (d == n - 1) {
    for (int j = 0; j < m; j++)
      if (a[0][j]) c[j] ^= 1;
    std::cout << "YES\n";
    for (int i = 0; i < n; i++) std::cout << r[i];
    std::cout << '\n';
    for (int j = 0; j < m; j++) std::cout << c[j];
    return 0;
  }
  bool cc = true;
  for (int j = 0; j < m; j++) cc &= a[0][j] == a[n - 1][j];
  if (!cc) {
    if (d != n - 2 && u != 1) {
      std::cout << "NO";
      return 0;
    }
    if (d == n - 2) Check(n - 1);
    if (u == 1) Check(0);
  }
  if (d + 2 < u) {
    std::cout << "NO";
    return 0;
  }
  Check(d + 1);
  std::cout << "NO";
  return 0;
}