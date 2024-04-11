#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

template <typename T>
struct CoordinateCompression : public std::vector<T> {
  template <typename... Args>
  CoordinateCompression(Args&&... args) : std::vector<T>(std::forward<Args>(args)...) {
    std::sort(this->begin(), this->end());
    this->erase(std::unique(this->begin(), this->end()), this->end());
  }
  int id(const T& value) const {
    return std::lower_bound(this->begin(), this->end(), value) - this->begin();
  }
};

template <typename F>
void go(int N, int l, int r, F&& f) {
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1) f(l++);
    if (r & 1) f(--r);
  }
}

using DP = std::pair<long long, long long>;

constexpr long long inf = std::numeric_limits<long long>::max() / 2;

struct Bucket {
  std::vector<DP> qpos, qneg, pos, neg;
  int potPos = 1, potNeg = 1;
  void rebuild() {
    static std::vector<DP> tmp;
    // positive
    if (!qpos.empty() && -potPos > (int) qpos.size() + (int) pos.size()) {
      auto cmp = [&](DP a, DP b) { return a.first != b.first ? a.first < b.first : a.second > b.second; };
      potPos += (int) qpos.size() + (int) pos.size();
      std::sort(qpos.begin(), qpos.end(), cmp);
      std::merge(qpos.begin(), qpos.end(), pos.begin(), pos.end(), std::back_inserter(tmp), cmp);
      qpos.clear();
      std::vector<DP> npos;
      for (auto a : tmp) {
        if (npos.empty() || npos.back().second < a.second) {
          npos.push_back(a);
        }
      }
      tmp.clear();
      pos.swap(npos);
    }
    // negative
    if (!qneg.empty() && -potNeg > (int) qneg.size() + (int) neg.size()) {
      auto cmp = [&](DP a, DP b) { return a.first != b.first ? a.first > b.first : a.second > b.second; };
      potNeg += (int) qneg.size() + (int) neg.size();
      std::sort(qneg.begin(), qneg.end(), cmp);
      std::merge(qneg.begin(), qneg.end(), neg.begin(), neg.end(), std::back_inserter(tmp), cmp);
      qneg.clear();
      std::vector<DP> nneg;
      for (auto a : tmp) {
        if (nneg.empty() || nneg.back().second < a.second) {
          nneg.push_back(a);
        }
      }
      tmp.clear();
      neg.swap(nneg);
    }
  }
  long long query_pos(long long key) {
    rebuild();
    auto iter = std::upper_bound(pos.begin(), pos.end(), std::pair(key, inf));
    long long res = 0;
    if (iter != pos.begin()) {
      res = (iter - 1)->second;
    }
    potPos -= (int) qpos.size();
    for (auto a : qpos) {
      if (a.first <= key) {
        res = std::max(res, a.second);
      }
    }
    return res;
  }
  long long query_neg(long long key) {
    rebuild();
    auto iter = std::lower_bound(neg.rbegin(), neg.rend(), std::pair(key, 0LL));
    long long res = 0;
    if (iter != neg.rend()) {
      res = iter->second;
    }
    potNeg -= (int) qneg.size();
    for (auto a : qneg) {
      if (a.first >= key) {
        res = std::max(res, a.second);
      }
    }
    return res;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N;
  long long v;
  std::cin >> N >> v;
  std::vector<long long> t(N), a(N);
  for (int i = 0; i < N; ++i) {
    t[i] = i;
    std::cin >> t[i];
  }
  for (int i = 0; i < N; ++i) {
    a[i] = i;
    std::cin >> a[i];
  }
  CoordinateCompression<long long> c(a.begin(), a.end());
  int M = c.size();
  std::vector<Bucket> st(2 * M);
  std::vector<long long> dp(N);
  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    if (std::abs(a[i]) > t[i] * v) continue;
    long long pos_key = a[i] + v * t[i], neg_key = a[i] - v * t[i];
    int j = c.id(a[i]);
    for (int p = M + j; p; p >>= 1) {
      dp[i] = std::max(dp[i], st[p].query_pos(pos_key));
      dp[i] = std::max(dp[i], st[p].query_neg(neg_key));
    }
    dp[i] += 1;
    ans = std::max(ans, dp[i]);
    go(M, 0, j, [&](int p) { st[p].qpos.emplace_back(pos_key, dp[i]); });
    go(M, j, M, [&](int p) { st[p].qneg.emplace_back(neg_key, dp[i]); });
  }
  std::cout << ans << '\n';
  exit(0);
}