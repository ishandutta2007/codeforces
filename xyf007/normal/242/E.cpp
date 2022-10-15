#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
int n, m, a[100001], b[100001];
class SegmentTree {
 public:
  SegmentTree() {}
  void Build(int l, int r, int x) {
    if (l == r) {
      sum_[x] = b[l];
      return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x);
    Build(mid + 1, r, x + x + 1);
    Pushup(x);
  }
  void Modify(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) {
      sum_[x] = r - l + 1 - sum_[x];
      rev_[x] ^= 1;
      return;
    }
    Pushdown(l, r, x);
    int mid = (l + r) >> 1;
    if (L <= mid) {
      Modify(L, R, l, mid, x + x);
    }
    if (R > mid) {
      Modify(L, R, mid + 1, r, x + x + 1);
    }
    Pushup(x);
  }
  int Query(int L, int R, int l, int r, int x) {
    if (L <= l && r <= R) {
      return sum_[x];
    }
    Pushdown(l, r, x);
    int mid = (l + r) >> 1, ans = 0;
    if (L <= mid) {
      ans += Query(L, R, l, mid, x + x);
    }
    if (R > mid) {
      ans += Query(L, R, mid + 1, r, x + x + 1);
    }
    return ans;
  }
  ~SegmentTree() {}

 private:
  int sum_[400001], rev_[400001];
  void Pushup(int x) { sum_[x] = sum_[x + x] + sum_[x + x + 1]; }
  void Pushdown(int l, int r, int x) {
    if (rev_[x]) {
      int mid = (l + r) >> 1;
      sum_[x + x] = mid - l + 1 - sum_[x + x];
      sum_[x + x + 1] = r - mid - sum_[x + x + 1];
      rev_[x + x] ^= 1;
      rev_[x + x + 1] ^= 1;
      rev_[x] = 0;
    }
  }
} T[20];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      b[j] = (a[j] >> i) & 1;
    }
    T[i].Build(1, n, 1);
  }
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int op, l, r, x;
    std::cin >> op >> l >> r;
    if (op == 1) {
      long long ans = 0LL;
      for (int j = 0; j < 20; j++) {
        ans += T[j].Query(l, r, 1, n, 1) * (1LL << j);
      }
      std::cout << ans << '\n';
    } else {
      std::cin >> x;
      for (int j = 0; j < 20; j++) {
        if ((x >> j) & 1) {
          T[j].Modify(l, r, 1, n, 1);
        }
      }
    }
  }
  return 0;
}