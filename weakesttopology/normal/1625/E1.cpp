#include <bits/stdc++.h>

struct Solver {
  std::stack<int> stk;
  int64_t res = 0;
  Solver() {
    stk.push(0);
  }
  void add(int c) {
    if (c == +1) {
      stk.push(0);
    } else if (stk.size() > 1) {
      stk.pop();
      ++stk.top();
      res += stk.top();
    } else {
      stk.top() = 0;
    }
  }
};

struct PrefixMinimum {
  int sum = 0, prefmin = 0;
  PrefixMinimum(int x = 0) : sum(x), prefmin(std::min(x, 0)) {}
  friend PrefixMinimum operator+(PrefixMinimum lhs, PrefixMinimum rhs) {
    PrefixMinimum res;
    res.sum = lhs.sum + rhs.sum;
    res.prefmin = std::min(lhs.prefmin, lhs.sum + rhs.prefmin);
    return res;
  }
};

constexpr int block_size = 400;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, Q;
  std::string S;
  std::cin >> N >> Q >> S;
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    A[i] = S[i] == '(' ? +1 : -1;
  }
  auto solve = [&](int l, int r) {
    Solver solver;
    for (int i = l; i < r; ++i) {
      solver.add(A[i]);
    }
    return solver.res;
  };
  int B = (N + block_size - 1) / block_size;
  std::vector<int> L(Q), R(Q);
  std::vector<int64_t> ans(Q);
  std::vector<std::vector<int>> qs(B);
  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t >> L[q] >> R[q];
    --L[q];
    int b = (L[q] + block_size - 1) / block_size, m = b * block_size;
    if (R[q] <= m) {
      ans[q] = solve(L[q], R[q]);
    } else {
      qs[b].push_back(q);
    }
  }
  for (int b = 0; b < B; ++b) {
    std::sort(qs[b].begin(), qs[b].end(), [&](int q1, int q2) { return R[q1] < R[q2]; });
    int m = b * block_size, ptr = m;
    Solver solver;
    PrefixMinimum suff;
    std::vector<int> suffcnt(N + 1);
    for (auto q : qs[b]) {
      for (int& i = ptr; i < R[q]; ++i) {
        solver.add(A[i]);
        suff = suff + A[i];
        if (suff.prefmin == suff.sum && suff.sum <= 0) {
          ++suffcnt[-suff.sum];
        }
      }
      ans[q] += solver.res;
      PrefixMinimum pref;
      Solver prefsolver;
      for (int i = m - 1; i >= L[q]; --i) {
        pref = A[i] + pref;
        if (pref.prefmin >= 0) {
          ans[q] += suffcnt[pref.sum];
        }
        prefsolver.add(-A[i]);
      }
      ans[q] += prefsolver.res;
    }
  }
  for (int q = 0; q < Q; ++q) {
    std::cout << ans[q] << '\n';
  }
  exit(0);
}