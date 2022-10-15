#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, nn, a[100001], b[100001];
long long k, pre[100001], suf[100005];
class FenwickTree {
 public:
  FenwickTree() {}
  void Add(int, int);
  int Query(int);
  void Clear();
  ~FenwickTree() {}

 private:
  int t_[100001];
} T1, T2;

void FenwickTree::Add(int x, int v) {
  while (x <= nn) {
    t_[x] += v;
    x += x & -x;
  }
}

int FenwickTree::Query(int x) {
  int s = 0;
  while (x) {
    s += t_[x];
    x -= x & -x;
  }
  return s;
}

void FenwickTree::Clear() { std::memset(t_, 0, sizeof(t_)); }
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::memcpy(b + 1, a + 1, 4 * n);
  std::sort(b + 1, b + n + 1);
  nn = std::unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
  }
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + i - 1 - T1.Query(a[i]);
    T1.Add(a[i], 1);
  }
  if (pre[n] <= k) {
    std::cout << n * static_cast<long long>(n - 1) / 2;
    return 0;
  }
  T1.Clear();
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + T2.Query(a[i] - 1);
    T2.Add(a[i], 1);
  }
  T2.Add(a[1], -1);
  T2.Add(a[2], -1);
  int l = 0;
  long long cnt = 0LL, ans = 0LL;
  for (int r = 3; r <= n; r++) {
    while (l + 2 < r && pre[l + 1] + suf[r] + cnt + T2.Query(a[l + 1] - 1) <= k) {
      cnt += T2.Query(a[++l] - 1);
      T1.Add(a[l], 1);
    }
    ans += l;
    cnt -= l - T1.Query(a[r]);
    T2.Add(a[r], -1);
  }
  std::cout << ans;
  return 0;
}