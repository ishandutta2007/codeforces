#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <random>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
int T, n, a[200001], p[200001], tot;
bool np[200001];
std::mt19937 rng(
    std::chrono::_V2::steady_clock::now().time_since_epoch().count());
int Rand(int l, int r) { return std::uniform_int_distribution<int>(l, r)(rng); }
void Init(int n) {
  np[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = true;
      if (!(i % p[j])) break;
    }
  }
}
int Maxd(long long n) {
  int ans = 0;
  for (int i = 1; i <= tot && p[i] * static_cast<long long>(p[i]) <= n; i++)
    if (!(n % p[i])) {
      checkmax(ans, p[i]);
      while (!(n % p[i])) n /= p[i];
    }
  if (n > 1) checkmax(ans, static_cast<int>(n));
  return ans;
}
long long Query(int x, int y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  long long s;
  std::cin >> s;
  return s;
}
long long t[101][101];
bool vis[101];
void Brute() {
  long long max = 0LL;
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) checkmax(max, t[i][j] = Query(i, j));
  int x = std::sqrt(max) + 1, rt = 0;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= n; j++)
      if (t[i][j] == max) {
        for (int k = 1; k <= n; k++) {
          if (k == i || k == j) continue;
          if (t[std::min(k, i)][std::max(k, i)] ==
              (x - 1) * static_cast<long long>(x - 2)) {
            rt = j;
            break;
          }
          if (t[std::min(k, j)][std::max(k, j)] ==
              (x - 1) * static_cast<long long>(x - 2)) {
            rt = i;
            break;
          }
        }
      }
  for (int i = 0; i < x; i++) {
    a[rt] = x - i, vis[rt] = true;
    int p = 0;
    for (int j = 1; j <= n; j++) {
      if (vis[j]) continue;
      if (t[std::min(j, rt)][std::max(j, rt)] ==
          (x - i) * static_cast<long long>(x - i - 1)) {
        p = j;
        break;
      }
    }
    rt = p;
  }
  std::cout << "!";
  for (int i = 1; i <= n; i++) std::cout << ' ' << a[i];
  std::cout << std::endl;
  std::memset(vis, false, sizeof(vis));
}
int l[5001], r[5001];
long long s[5001];
void Solve() {
  std::cin >> n;
  if (n <= 100) {
    Brute();
    return;
  }
  int p = 0;
  for (int i = 1; i <= 5000; i++) {
    l[i] = Rand(1, n), r[i] = Rand(1, n);
    while (l[i] == r[i]) r[i] = Rand(1, n);
    s[i] = Maxd(Query(l[i], r[i]));
    if (s[i] > s[p]) p = i;
  }
  int rt = 0, rp = Rand(1, n);
  while (rp == l[p] || rt == r[p]) rp = Rand(1, n);
  if (Maxd(Query(rp, l[p])) == s[p])
    rt = l[p];
  else
    rt = r[p];
  for (int i = 1; i <= n; i++)
    if (i == rt)
      a[i] = s[p];
    else
      a[i] = Query(i, rt) / s[p];
  std::cout << "!";
  for (int i = 1; i <= n; i++) std::cout << ' ' << a[i];
  std::cout << std::endl;
}
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  Init(200000);
  std::cin >> T;
  while (T--) Solve();
  return 0;
}