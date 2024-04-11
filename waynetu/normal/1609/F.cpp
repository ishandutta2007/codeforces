#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int64_t> A(N);
  vector<int> pc(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  auto Popcount = [&](int64_t x) {
    return __builtin_popcountll(x);
  };

  constexpr int64_t kInf = 2'000'000'000'000'000'000;
  vector<int64_t> best(N);
  vector<int> cnt(60);

  auto DivideConquer = [&](auto self, int l, int r) -> int64_t {
    if (r - l == 1) {
      return 1;
    }
    int m = (l + r) >> 1;
    int64_t res = self(self, l, m) + self(self, m, r);
    int64_t x = -1, y = kInf, z = kInf;
    int goods = 0;
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = m, j = m - 1, k = m - 1; i < r; ++i) {
      x = max(x, A[i]);
      z = min(z, A[i]);
      while (j >= l && A[j] <= x) {
        y = min(y, A[j]);
        best[j] = y;
        cnt[Popcount(y)]++;
        j--;
      }
      while (k > j && A[k] > z) {
        goods++;
        cnt[Popcount(best[k])]--;
        k--;
      }
      res += cnt[Popcount(x)];
      if (Popcount(x) == Popcount(z)) {
        res += goods;
      }
    }
    fill(cnt.begin(), cnt.end(), 0);
    goods = 0;
    x = -1;
    y = kInf;
    z = kInf;
    for (int i = m - 1, j = m, k = m; i >= l; --i) {
      x = max(x, A[i]);
      z = min(z, A[i]);
      while (j < r && A[j] < x) {
        y = min(y, A[j]);
        best[j] = y;
        cnt[Popcount(y)]++;
        j++;
      }
      while (k < j && A[k] >= z) {
        goods++;
        cnt[Popcount(best[k])]--;
        k++;
      }
      res += cnt[Popcount(x)];
      if (Popcount(x) == Popcount(z)) {
        res += goods;
      }
    }
    return res;
  };

  cout << DivideConquer(DivideConquer, 0, N) << "\n";
  return 0;
}